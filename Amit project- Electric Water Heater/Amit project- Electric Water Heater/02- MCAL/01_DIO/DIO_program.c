/*
 * DIO_program.c
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan Ahmed, Hany Mahmoud El Taweel
 */

#include "STD_TYPES.h"   /// include " " order matters to avoid errors ex: std first to be used later
#include "BIT_MATH_H.h"

#include "DIO_private.h"
#include "DIO_interface.h"

Std_ReturnType DIO_udtSetPinDirection // udt = user defined type
(
uint8 u8Port,
uint8 u8Pin,
uint8 u8Direction
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK ;
	if(u8Direction == DIO_OUTPUT)
	{
		switch(u8Port)
		{
			case DIO_PORTA: SET_BIT(DIO ->DDRA, u8Pin) ;
							udtReturnValue = E_OK;
							break;
							
			case DIO_PORTB: SET_BIT(DIO ->DDRB, u8Pin) ;
							udtReturnValue = E_OK;
							break;
							
			case DIO_PORTC:	SET_BIT(DIO ->DDRC, u8Pin) ;
							udtReturnValue = E_OK;
							break;
							
			case DIO_PORTD:	SET_BIT(DIO ->DDRD, u8Pin) ;
							udtReturnValue = E_OK;
							break;
							
			default: /*Comment: Do notion */ // misra rule leave empty if not used
							break;			//  misra rule add break for default
		}
	}
	else if(u8Direction == DIO_INPUT)
	{
		switch(u8Port)
		{
			case DIO_PORTA: CLR_BIT(DIO ->DDRA, u8Pin) ;
							udtReturnValue = E_OK;
							break;
							
			case DIO_PORTB: CLR_BIT(DIO ->DDRB, u8Pin) ;
							udtReturnValue = E_OK;
							break;
							
			case DIO_PORTC:	CLR_BIT(DIO ->DDRC, u8Pin) ;
							udtReturnValue = E_OK;
							break;
							
			case DIO_PORTD:	CLR_BIT(DIO ->DDRD, u8Pin) ;
							udtReturnValue = E_OK;
							break;
							
			default: /*Comment: Do notion */ // misra rule leave empty if not used
							break;			//  misra rule add break for default
		}
	}
	else{} // misra rule leave empty if not used
	return udtReturnValue;
}


Std_ReturnType DIO_udtSetPinValue // udt = user defined type
(
uint8 u8Port,
uint8 u8Pin,
uint8 u8Value
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK ;
	if(u8Value == DIO_HIGH)
	{
		switch(u8Port)
		{
			case DIO_PORTA: SET_BIT(DIO ->PORTA, u8Pin) ;
			udtReturnValue = E_OK;
			break;
			
			case DIO_PORTB: SET_BIT(DIO ->PORTB, u8Pin) ;
			udtReturnValue = E_OK;
			break;
			
			case DIO_PORTC:	SET_BIT(DIO ->PORTC, u8Pin) ;
			udtReturnValue = E_OK;
			break;
			
			case DIO_PORTD:	SET_BIT(DIO ->PORTD, u8Pin) ;
			udtReturnValue = E_OK;
			break;
			
			default: /*Comment: Do notion */ // misra rule leave empty if not used
			break;							//  misra rule add break for default
		}
	}
	else if(u8Value == DIO_LOW)
	{
		switch(u8Port)
		{
			case DIO_PORTA: CLR_BIT(DIO ->PORTA, u8Pin) ;
							udtReturnValue = E_OK;
							break;
			
			case DIO_PORTB: CLR_BIT(DIO ->PORTB, u8Pin) ;
							udtReturnValue = E_OK;
							break;
			
			case DIO_PORTC:	CLR_BIT(DIO ->PORTC, u8Pin) ;
							udtReturnValue = E_OK;
							break;
			
			case DIO_PORTD:	CLR_BIT(DIO ->PORTD, u8Pin) ;
							udtReturnValue = E_OK;
							break;
			
			default: /*Comment: Do notion */ // misra rule leave empty if not used
			break;							//  misra rule add break for default
		}
	}
	else{} // misra rule add else and leave empty if not used
	return udtReturnValue;
}

Std_ReturnType DIO_udtGetPinValue // udt = user defined type
(
uint8  u8Port,
uint8  u8Pin,
uint8* pu8Value /// pointer to send value
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK ;
	
	switch(u8Port)
	{
		case DIO_PORTA: *pu8Value = GET_BIT(DIO->PINA, u8Pin);
						udtReturnValue = E_OK;
						break;
		case DIO_PORTB: *pu8Value = GET_BIT(DIO->PINB, u8Pin);
						udtReturnValue = E_OK;
						break;
		case DIO_PORTC: *pu8Value = GET_BIT(DIO->PINC, u8Pin);
						udtReturnValue = E_OK;
						break;
		case DIO_PORTD: *pu8Value = GET_BIT(DIO->PIND, u8Pin);
						udtReturnValue = E_OK;
						break;
		default: /*Comment: Do nothing */	// misra rule add default and leave empty if not used    //// misra rule to write comment 
						break;				//  misra rule add break for default
	}
	return udtReturnValue;
}

/*
 * DIO_program.c
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan Ahmed, Hany Mahmoud El Taweel
 */