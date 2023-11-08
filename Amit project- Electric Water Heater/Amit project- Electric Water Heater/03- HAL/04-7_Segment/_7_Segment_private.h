/*
 * _7_SEGMENT_private.h
 *
 * Created: 10/30/2023 8:16:05 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 
#ifndef _7_SEGMENT_PRIVATE_H_
#define _7_SEGMENT_PRIVATE_H_

#define En1_OUTPUT DIO_udtSetPinDirection(DIO_PORTB, DIO_PIN2, DIO_OUTPUT); // 7-SEGMENT  EN1 OUTPUT
#define En2_OUTPUT DIO_udtSetPinDirection(DIO_PORTB, DIO_PIN1, DIO_OUTPUT); // 7-SEGMENT  EN2 OUTPUT

#define A_OUTPUT DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN4, DIO_OUTPUT)	// 7-SEGMENT  A OUTPUT
#define B_OUTPUT DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN5, DIO_OUTPUT)	// 7-SEGMENT  B OUTPUT
#define C_OUTPUT DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN6, DIO_OUTPUT)	// 7-SEGMENT  C OUTPUT
#define D_OUTPUT DIO_udtSetPinDirection(DIO_PORTA, DIO_PIN7, DIO_OUTPUT)	// 7-SEGMENT  D OUTPUT

#define D_LOW  DIO_udtSetPinValue(DIO_PORTA, DIO_PIN4, DIO_LOW)				// 7-SEGMENT  A HIGH
#define D_HIGH DIO_udtSetPinValue(DIO_PORTA, DIO_PIN4, DIO_HIGH)			// 7-SEGMENT  A LOW

#define C_LOW  DIO_udtSetPinValue(DIO_PORTA, DIO_PIN5, DIO_LOW)				// 7-SEGMENT  B HIGH
#define C_HIGH DIO_udtSetPinValue(DIO_PORTA, DIO_PIN5, DIO_HIGH)			// 7-SEGMENT  B LOW

#define B_LOW  DIO_udtSetPinValue(DIO_PORTA, DIO_PIN6, DIO_LOW)				// 7-SEGMENT  C HIGH
#define B_HIGH DIO_udtSetPinValue(DIO_PORTA, DIO_PIN6, DIO_HIGH)			// 7-SEGMENT  C LOW

#define A_LOW  DIO_udtSetPinValue(DIO_PORTA, DIO_PIN7, DIO_LOW)				// 7-SEGMENT  D HIGH
#define A_HIGH DIO_udtSetPinValue(DIO_PORTA, DIO_PIN7, DIO_HIGH)			// 7-SEGMENT  D LOW

#define En1_HIGH DIO_udtSetPinValue (DIO_PORTB, DIO_PIN2, DIO_HIGH) 		// 7-SEGMENT  EN1 HIGH
#define En1_LOW DIO_udtSetPinValue (DIO_PORTB, DIO_PIN2, DIO_LOW)			// 7-SEGMENT  EN1 LOW

#define En2_HIGH DIO_udtSetPinValue (DIO_PORTB, DIO_PIN1, DIO_HIGH) 		// 7-SEGMENT  EN2 HIGH
#define	En2_LOW DIO_udtSetPinValue (DIO_PORTB, DIO_PIN1, DIO_LOW)			// 7-SEGMENT  EN2 LOW


#endif

/*
 * _7_SEGMENT_private.h
 *
 * Created: 10/30/2023 8:16:05 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 