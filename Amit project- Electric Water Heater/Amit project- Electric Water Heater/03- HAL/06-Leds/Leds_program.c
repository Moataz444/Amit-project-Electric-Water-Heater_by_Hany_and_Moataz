/*
 * Cooling_Element_Fan.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 

#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "Leds_interface.h"
#include "Leds_private.h"
#include "Leds_config.h"

void HAL_udtInitLeds(void)
{
	Led_0_Output;	//led  0	OUTPUT
	Led_1_Output;	//led  1	OUTPUT
	Led_2_Output;	//led  2	OUTPUT

	Led_0_LOW;		//led 0	LOW
	Led_1_LOW;		//led 1	LOW
	Led_2_LOW;		//led 2	LOW
	
}

void HAL_udtLedOn(uint8 u8Led_Num)
{
	switch(u8Led_Num)
	{
		case Led0: Led_0_HIGH;
		break;	   
		case Led1: Led_1_HIGH;
		break;
		case Led2: Led_2_HIGH;
		break;

		default: break;
	}
}

void HAL_udtLedOff(uint8 u8Led_Num)
{
	switch(u8Led_Num)
	{
		case Led0: Led_0_LOW;
		break;
		case Led1: Led_1_LOW;
		break;
		case Led2: Led_2_LOW;
		break;

		default: break;
	}
}

/*
 * Cooling_Element_Fan.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 

