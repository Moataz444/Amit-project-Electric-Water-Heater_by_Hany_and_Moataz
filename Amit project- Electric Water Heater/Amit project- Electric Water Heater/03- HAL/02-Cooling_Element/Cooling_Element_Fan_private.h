/*
 * Cooling_Element_Fan_private.h
 *
 * Created: 10/31/2023 5:53:05 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 
#ifndef _COOLING_ELEMENT_FAN_PRIVATE_H_
#define _COOLING_ELEMENT_FAN_PRIVATE_H_

#define Enable_Motor_1_Pin_Output DIO_udtSetPinDirection(DIO_PORTD, DIO_PIN4, DIO_OUTPUT)	// h_en1
#define Enable_Motor_2_Pin_Output DIO_udtSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT)	// h_en2

#define Motor_1_Pin1_Output DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN3, DIO_OUTPUT)			// h_A1
#define Motor_1_Pin2_Output DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN4, DIO_OUTPUT)			// h_A2
#define Motor_2_Pin1_Output DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN5, DIO_OUTPUT)			// h_A3
#define Motor_2_Pin2_Output DIO_udtSetPinDirection(DIO_PORTC, DIO_PIN6, DIO_OUTPUT)			// h_A4

#define Enable_Motor_1 DIO_udtSetPinValue(DIO_PORTD, DIO_PIN4, DIO_HIGH)		// h_en1 enable motor 1
#define Enable_Motor_2 DIO_udtSetPinValue(DIO_PORTD, DIO_PIN5, DIO_HIGH)		// h_en2 enable motor 2

#define Disable_Motor_1 DIO_udtSetPinValue(DIO_PORTD, DIO_PIN4, DIO_LOW)		// h_en1 Disable motor 1
#define Disable_Motor_2 DIO_udtSetPinValue(DIO_PORTD, DIO_PIN5, DIO_LOW)		// h_en2 Disable motor 2

#define Clock_Wise_Pin1 DIO_udtSetPinValue(DIO_PORTC, DIO_PIN3, DIO_HIGH)		// h_A1
#define Clock_Wise_Pin2 DIO_udtSetPinValue(DIO_PORTC, DIO_PIN4, DIO_LOW)		// h_A2

#define Anti_Clock_Wise_Pin1 DIO_udtSetPinValue(DIO_PORTC, DIO_PIN3, DIO_LOW)	// h_A1
#define Anti_Clock_Wise_Pin2 DIO_udtSetPinValue(DIO_PORTC, DIO_PIN4, DIO_HIGH)	// h_A2

#endif

/*
 * Cooling_Element_Fan_private.h
 *
 * Created: 10/31/2023 5:53:05 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 