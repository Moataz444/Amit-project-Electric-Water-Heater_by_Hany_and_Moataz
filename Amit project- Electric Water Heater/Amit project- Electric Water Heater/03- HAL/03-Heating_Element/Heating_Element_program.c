/*
 * Cooling_Element_Fan.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 

#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "Heating_Element_Fan_interface.h"
#include "Heating_Element_Fan_private.h"
#include "Heating_Element_Fan_config.h"
#include "Relay_interface.h"
// #include "Leds_interface.h"

void HAL_udtInitHeater (void)
{
	HAL_udtInitRelay();
}

void HAL_udtEnableHeater(void)
{
// 	HAL_udtLedOn(Led2);
	HAL_udtEnableRelay();
}

void HAL_udtDisableHeater(void)
{
// 	HAL_udtLedOff(Led2);
	HAL_udtDisableRelay();
}

/*
 * Cooling_Element_Fan.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 