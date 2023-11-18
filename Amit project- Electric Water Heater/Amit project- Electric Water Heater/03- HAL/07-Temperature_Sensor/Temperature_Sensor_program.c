/*
 * Temperature_Sensor_program.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 

#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "Temperature_Sensor_interface.h"
#include "Temperature_Sensor_private.h"
#include "Temperature_Sensor_config.h"
#include "ADC_interface.h"
void HAL_udtInitTemperature_Sensor (void)
{
	Temperature_Sensor_Intput;
}

uint8 HAL_udtGetTemperature(void)
{
	uint16 u16ADCreaaaad = 0;
	u16ADCreaaaad = MCAL_ADC_u8ChannelRead(1);  // portA pin1 (Potentiometer) + NTC Thermistor    //////////////////////////////////
	
	u16ADCreaaaad =  (u16ADCreaaaad*2 +20 *2)/2 ;
	u16ADCreaaaad = u16ADCreaaaad - 100;
	return u16ADCreaaaad;
}

/*
 * Temperature_Sensor_program.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 
