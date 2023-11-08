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
#include <math.h>
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
	
// 	uint16 u16ADCreaaaad = 0;
// 	u16ADCreaaaad = MCAL_ADC_u8ChannelRead(1);	
// 	u16ADCreaaaad =((10230000/u16ADCreaaaad) - 10000);/* calculate the resistance */
// 	u16ADCreaaaad = log(u16ADCreaaaad);	/* calculate natural log of resistance */
// 	/* Steinhart-Hart Thermistor Equation: */
// 	/*  Temperature in Kelvin = 1 / (A + B[ln(R)] + C[ln(R)]^3)		*/
// 	/*  where A = 0.001129148, B = 0.000234125 and C = 8.76741*10^-8  */
// 	u16ADCreaaaad = 1 / (0.001129148 + (0.000234125 * u16ADCreaaaad) + (0.0000000876741 * u16ADCreaaaad * u16ADCreaaaad * u16ADCreaaaad));
// 	u16ADCreaaaad = u16ADCreaaaad - 273.15;/* convert kelvin to °C */
	
// 	u16ADCreaaaad = 1 / ((1 / 298.15) + (1 / 3380)*(log ( 256 / u16ADCreaaaad - 1)));
// 	u16ADCreaaaad = u16ADCreaaaad - 273.15;/* convert kelvin to °C */

// 	u16ADCreaaaad = (u16ADCreaaaad * 500UL) / 1024;
// 	return u16ADCreaaaad;
}

/*
 * Temperature_Sensor_program.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 