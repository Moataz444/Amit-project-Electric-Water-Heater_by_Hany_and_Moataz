/*
 * main.c
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */
#include "STD_TYPES.h"   /// include order matters to avoid errors
#include "BIT_MATH_H.h"

// include MCAL //
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "ADC_interface.h"
#include "Timer_interface.h"
#include "EEPROM_interface.h"

// include HCAL //
#include "Relay_interface.h"
#include "Cooling_Element_Fan_interface.h"
#include "Heating_Element_Fan_interface.h"
#include "_7_Segment_interface.h"
#include "Push_Buttons_interface.h"
#include "Leds_interface.h"
#include "Temperature_Sensor_interface.h"

#define Maximum_Temperature 75
#define Minimum_Temperature 35

uint8 Wanted_Temperature = 60;		// initiall value stored in EEPROM
uint8 Current_Temperature_Sensor = 0;

uint32 Timer0_OVF_Counter = 0;
uint32 Timer1_OVF_Counter = 0;
uint32 Timer2_OVF_Counter = 0;

uint8 u8Temprature_Array[10]; //FOR STORING THE LAST 10 READINGS INSTED OF EEPROM
uint8 u8Temprature_Array_Counter = 0;
uint16 u16Teperature_Sum = 0;
uint16 u16Teperature_Average = 0;

Std_ReturnState set_temperature_mode = false ;
Std_ReturnState live_temperature_mode = false ;
Std_ReturnState Toggle_Every_1_sec = false ;

void vidInit_drivers (void);
void Interupt_UART_Received_Order(void);
void vidGet_Temperature_And_Average_Of_Last_10_Temperature_Readings(void);
void Interupt_OVF_Timer0_100milisec_Get_Temperature(void);
void Interupt_OVF_Timer1_5sec_Set_Temoperature_Mode(void);
void Interupt_OVF_Timer2_1sec_Toggle(void);


int main (void)
{
	vidInit_drivers();
	MCAL_TIMER0_vidCallBack (&Interupt_OVF_Timer0_100milisec_Get_Temperature);
	MCAL_TIMER1_vidCallBack (&Interupt_OVF_Timer1_5sec_Set_Temoperature_Mode);
	MCAL_TIMER2_vidCallBack (&Interupt_OVF_Timer2_1sec_Toggle);
	
	Std_ReturnState sleep_mode = true ;

	uint16 u16EEPROM_Set_temp_Address = 4 ;
	uint8 u8EEPROM_Set_temp_Data = EEPROM_vidRead(u16EEPROM_Set_temp_Address);	
	// check EEPROM stored data
	if (u8EEPROM_Set_temp_Data >=35 && u8EEPROM_Set_temp_Data <=75 )
	{
		Wanted_Temperature = u8EEPROM_Set_temp_Data;
	}
	else // if not stored store Wanted_Temperature = 60 in EEPROM
	{
		EEPROM_vidWrite(u16EEPROM_Set_temp_Address, Wanted_Temperature);
	}
// 	Timer0_OVF_Counter = 0;
// 	Timer1_OVF_Counter = 0;
// 	Timer2_OVF_Counter = 0;
	uint16 Timer0_Reg_StrtFrom = 124;	// for remainder ticks 132  - 2^8 bit timer
	uint16 Timer1_Reg_StrtFrom = 59448;	// for remainder ticks 6088 - 2^16 bit timer
	uint16 Timer2_Reg_StrtFrom = 216;	// for remainder ticks 40	- 2^8 bit timer
	
	while(1)
	{
		if (sleep_mode)
		{
 			HAL_udtDisable7Segment(); 
			HAL_udtDisableHeater();
			HAL_udtDisableCooler();
			HAL_udtLedOff(Led1);
			
			if (HAL_udtCheck_ChangeStateButton())
			{
				sleep_mode = !sleep_mode;
				set_temperature_mode = false;
				live_temperature_mode = true;
				HAL_udtEnableHeater();  // start with heater on
				Current_Temperature_Sensor = HAL_udtGetTemperature();
				MCAL_Timer0_vidEnable(Timer0_Reg_StrtFrom); // timer0 to get temperature and average temp every 100ms
			}else{}
		}
		else
		{			
			// check 7_segment mode
			if (live_temperature_mode)
			{
 				HAL_udtWrite_On_2_7Segment( Current_Temperature_Sensor );
			}
			else if (set_temperature_mode)
			{
				/// 7_Segment blink
				MCAL_Timer2_vidEnable(Timer2_Reg_StrtFrom); // timer2 interrupt toggle 7_Segment every 1sec
				if (Toggle_Every_1_sec)
				{
					HAL_udtWrite_On_2_7Segment( Wanted_Temperature );
				}
				else{}
			}else{}	
			
			//check up/down push buttons
			//check down button
			if (HAL_udtCheck_DownButton())		
			{
				set_temperature_mode = true;
				live_temperature_mode = false;
				Timer1_OVF_Counter = 0; // to reset 5sec
				MCAL_Timer1_vidEnable(Timer1_Reg_StrtFrom); // timer1 interrupt to switch to (set temperature mode) 7_Segment for 5sec
				if ( Wanted_Temperature > Minimum_Temperature )	// min 35
				{
					Wanted_Temperature-=5;
					EEPROM_vidWrite(u16EEPROM_Set_temp_Address, Wanted_Temperature); 	// store new Wanted_Temperature value in EEPROM
				}else{}
			}else {}
				
			//check up button
			if (HAL_udtCheck_UpButton())	
			{
				set_temperature_mode = true;
				live_temperature_mode = false;
				Timer1_OVF_Counter = 0;  // to reset 5sec
				MCAL_Timer1_vidEnable(Timer1_Reg_StrtFrom); // timer1 interrupt to switch to (set temperature mode) 7_Segment for 5sec
				if ( Wanted_Temperature < Maximum_Temperature )	// max 75
				{
					Wanted_Temperature+=5;
					EEPROM_vidWrite(u16EEPROM_Set_temp_Address, Wanted_Temperature);  // store new Wanted_Temperature value in EEPROM
				}else{}
			}else {}
			
			// check on/off push button
			if (HAL_udtCheck_ChangeStateButton())
			{
				sleep_mode = !sleep_mode;
				MCAL_Timer0_vidDisable();
				MCAL_Timer1_vidDisable();
				MCAL_Timer2_vidDisable();
			}else{}
			
			// check temperature
			if ( u16Teperature_Average < Wanted_Temperature-5 ) // Enable Heater
			{
				/// led1 blink
				MCAL_Timer2_vidEnable(Timer2_Reg_StrtFrom); // // timer2 interrupt toggle led and 7_Segment every 1sec
				if (Toggle_Every_1_sec)
				{
					HAL_udtLedOn(Led1);
				}
				else
				{
					HAL_udtLedOff(Led1);
				}
				HAL_udtEnableHeater();
				HAL_udtDisableCooler();
			}else {}
				
			if ( u16Teperature_Average > Wanted_Temperature+5 ) // Enable Cooler
			{
				MCAL_Timer2_vidDisable();
				HAL_udtLedOn(Led1);
				HAL_udtEnableCooler_Clockwise();
				HAL_udtDisableHeater();
			} else{}
		}
	}
	return 0;
}

void vidInit_drivers (void)
{
	// init hal
	HAL_udtInitCooler();
	HAL_udtInitHeater();
	HAL_udtInit7Segment();
	HAL_udtInitPushButtons();
	HAL_udtInitLeds();
	HAL_udtInitTemperature_Sensor();
	
	// init mcal
	MCAL_ADC_vidInit();
	MCAL_Timer0_vidInit();
	MCAL_Timer1_vidInit();
	MCAL_Timer2_vidInit();
	MCAL_GIE_vidEnable();
}

//get Average Of Last 10 Temperature Readings
void vidGet_Temperature_And_Average_Of_Last_10_Temperature_Readings(void)
{
	uint8 u8Counter = 0;
	Current_Temperature_Sensor = HAL_udtGetTemperature();
	//stores the last ten values of lm35 readings instead of EEprom
	u8Temprature_Array[u8Temprature_Array_Counter] = Current_Temperature_Sensor;
	u8Temprature_Array_Counter++;
	
	if (u8Temprature_Array_Counter == 10)
	{
		u8Temprature_Array_Counter = 0;
		for (u8Counter = 0; u8Counter < 10; u8Counter++)
		{
			u16Teperature_Sum += u8Temprature_Array[u8Counter];
		}
		u16Teperature_Average = u16Teperature_Sum / 10;
		u16Teperature_Sum = 0;
	}
}

void Interupt_OVF_Timer0_100milisec_Get_Temperature(void) // 8-bit timer, prescaler 10244, wanted delay = 100msec, total OVF count = 6104
{
	Timer0_OVF_Counter++; 
	if (Timer0_OVF_Counter >= 6104)
	{
		vidGet_Temperature_And_Average_Of_Last_10_Temperature_Readings();
// 		MCAL_Timer0_vidDisable();
		Timer0_OVF_Counter = 0;
	}
}

void Interupt_OVF_Timer1_5sec_Set_Temoperature_Mode(void)  // 16-bit timer, prescaler 10244, wanted delay = 5sec, total OVF count = 1193
{
	Timer1_OVF_Counter++;
	if (Timer1_OVF_Counter >= 1193)
	{
		MCAL_Timer1_vidDisable();
		Timer1_OVF_Counter = 0;
		set_temperature_mode = false;
		live_temperature_mode = true;
	}
}

void Interupt_OVF_Timer2_1sec_Toggle(void) // 8-bit timer, prescaler 1024, wanted delay = 1sec, total OVF count = 61036
{
	Timer2_OVF_Counter++;
	if (Timer2_OVF_Counter >= 61036)
	{
		Toggle_Every_1_sec = !Toggle_Every_1_sec;
		Timer2_OVF_Counter = 0;
		MCAL_Timer2_vidDisable();
	}
}

/*
 * main.c
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */
