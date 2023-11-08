/*
 * Cooling_Element_Fan_private.h
 *
 * Created: 10/31/2023 5:53:05 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 
#ifndef _PUSH_BUTTONS_PRIVATE_H_ 
#define _PUSH_BUTTONS_PRIVATE_H_

#define DownButton_Input					DIO_udtSetPinDirection	(DIO_PORTD, DIO_PIN6, DIO_INPUT)	// Down push button output
#define DownButton_HIGH						DIO_udtSetPinValue		(DIO_PORTD, DIO_PIN6, DIO_HIGH)		// MAKE PUSH button high  // because avr are all pull up resistor (high by default)

#define UpButton_Input						DIO_udtSetPinDirection	(DIO_PORTD, DIO_PIN2, DIO_INPUT)	// Up push button output
#define UpButton_HIGH						DIO_udtSetPinValue		(DIO_PORTD, DIO_PIN2, DIO_HIGH)		// MAKE PUSH button high  // because avr are all pull up resistor (high by default)

#define ChangeStateButton_Input				DIO_udtSetPinDirection	(DIO_PORTB, DIO_PIN0, DIO_INPUT)	// ChangeStateButton push button output
#define ChangeStateButton_HIGH				DIO_udtSetPinValue		(DIO_PORTB, DIO_PIN0, DIO_HIGH)		// MAKE PUSH button high  // because avr are all pull up resistor (high by default)


#define DownButton_GetValue(Value)			DIO_udtGetPinValue		(DIO_PORTD, DIO_PIN6, Value)		// get pushButtonValue
#define UpButton_GetValue(Value)			DIO_udtGetPinValue		(DIO_PORTD, DIO_PIN2, Value)		// get pushButtonValue
#define ChangeStateButton_GetValue(Value) 	DIO_udtGetPinValue		(DIO_PORTB, DIO_PIN0, Value)		// get pushButtonValue

#endif

/*
 * Cooling_Element_Fan_private.h
 *
 * Created: 10/31/2023 5:53:05 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 