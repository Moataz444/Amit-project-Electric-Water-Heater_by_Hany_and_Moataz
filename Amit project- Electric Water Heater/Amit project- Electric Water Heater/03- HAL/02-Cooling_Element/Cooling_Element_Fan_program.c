/*
 * Cooling_Element_Fan.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 

#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "Cooling_Element_Fan_interface.h"
#include "Cooling_Element_Fan_private.h"
#include "Cooling_Element_Fan_config.h"
// #include "Leds_interface.h"

void HAL_udtInitCooler (void)
{
	Enable_Motor_1_Pin_Output;
	Enable_Motor_2_Pin_Output;
	Motor_1_Pin1_Output;
	Motor_1_Pin2_Output;
	Motor_2_Pin1_Output;
	Motor_2_Pin2_Output;
}

void HAL_udtEnableCooler_Clockwise(void)
{
// 	HAL_udtLedOn(Led0);
	Enable_Motor_1;
	Enable_Motor_2;
	Clock_Wise_Pin1;
	Clock_Wise_Pin2;
}

void HAL_udtEnableCooler_AntiClockwise(void)
{
// 	HAL_udtLedOn(Led0);
	Enable_Motor_1;
	Enable_Motor_2;
	Anti_Clock_Wise_Pin1;
	Anti_Clock_Wise_Pin2;
}

void HAL_udtDisableCooler(void)
{
// 	HAL_udtLedOff(Led0);
	Disable_Motor_1;
	Disable_Motor_2;
}

/*
 * Cooling_Element_Fan.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 