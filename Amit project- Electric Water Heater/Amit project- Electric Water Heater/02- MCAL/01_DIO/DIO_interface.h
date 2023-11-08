/*
 * DIO_interface.h
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#define DIO_PORTA	((uint8) 0u)  /// u = unsigned (misra rule)
#define DIO_PORTB	((uint8) 1u)  // to be used in switch
#define DIO_PORTC	((uint8) 2u)
#define DIO_PORTD	((uint8) 3u)

#define DIO_PIN0	((uint8) 0u)	// bit to be used (shifted) in BIT_MATH.h (set, clear, get, ... )
#define DIO_PIN1	((uint8) 1u)
#define DIO_PIN2	((uint8) 2u)
#define DIO_PIN3	((uint8) 3u)
#define DIO_PIN4	((uint8) 4u)
#define DIO_PIN5	((uint8) 5u)
#define DIO_PIN6	((uint8) 6u)
#define DIO_PIN7	((uint8) 7u)

#define DIO_OUTPUT	((uint8) 1u) 
#define DIO_INPUT	((uint8) 0u) 

#define DIO_HIGH	((uint8) 1u) // 5v
#define DIO_LOW		((uint8) 0u) // 0v

Std_ReturnType DIO_udtSetPinDirection // udt = user defined type
(
uint8 u8Port,					// syntax way to write operators by (Enter)
uint8 u8Pin,
uint8 u8Direction
);

Std_ReturnType DIO_udtSetPinValue // udt = user defined type
(
uint8 u8Port,					// syntax way to write operators by (Enter)
uint8 u8Pin,
uint8 u8Value
);

Std_ReturnType DIO_udtGetPinValue // udt = user defined type
(
uint8  u8Port,					// syntax way to write operators by (Enter)
uint8  u8Pin,
uint8* u8Value					/// point to send value
);


#endif

/*
 * DIO_interface.h
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */
