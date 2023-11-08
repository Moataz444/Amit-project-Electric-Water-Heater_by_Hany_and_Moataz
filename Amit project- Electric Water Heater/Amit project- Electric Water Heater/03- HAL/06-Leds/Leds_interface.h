/*
 * Cooling_Element_Fan.h
 *
 * Created: 10/30/2023 9:06:03 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 
#ifndef _LEDS_INTERFACE_H_
#define _LEDS_INTERFACE_H_

#define Led0 0u
#define Led1 1u
#define Led2 2u

void HAL_udtInitLeds(void);
void HAL_udtLedOn(uint8 u8Led_Num);
void HAL_udtLedOff(uint8 u8Led_Num);

#endif

/*
 * Cooling_Element_Fan.h
 *
 * Created: 10/30/2023 9:06:03 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 