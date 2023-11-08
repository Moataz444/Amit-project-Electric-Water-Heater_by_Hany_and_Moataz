/*
 * Cooling_Element_Fan_private.h
 *
 * Created: 10/31/2023 5:53:05 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 
#ifndef _LEDS_PRIVATE_H_
#define _LEDS_PRIVATE_H_

#define Led_0_Output DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN2, DIO_OUTPUT)	//led  0	OUTPUT
#define Led_1_Output DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN7, DIO_OUTPUT)	//led  1    OUTPUT
#define Led_2_Output DIO_udtSetPinDirection(DIO_PORTD, DIO_PIN3, DIO_OUTPUT)	//led  2	OUTPUT

#define Led_0_HIGH DIO_udtSetPinValue(DIO_PORTC, DIO_PIN2, DIO_HIGH)			//led  0	HIGH
#define Led_1_HIGH DIO_udtSetPinValue(DIO_PORTC, DIO_PIN7, DIO_HIGH)			//led  1    HIGH
#define Led_2_HIGH DIO_udtSetPinValue(DIO_PORTD, DIO_PIN3, DIO_HIGH)			//led  2	HIGH

#define Led_0_LOW DIO_udtSetPinValue(DIO_PORTC, DIO_PIN2, DIO_LOW)				//led  0	LOW
#define Led_1_LOW DIO_udtSetPinValue(DIO_PORTC, DIO_PIN7, DIO_LOW)				//led  1    LOW
#define Led_2_LOW DIO_udtSetPinValue(DIO_PORTD, DIO_PIN3, DIO_LOW)				//led  2	LOW

#endif

/*
 * Cooling_Element_Fan_private.h
 *
 * Created: 10/31/2023 5:53:05 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 