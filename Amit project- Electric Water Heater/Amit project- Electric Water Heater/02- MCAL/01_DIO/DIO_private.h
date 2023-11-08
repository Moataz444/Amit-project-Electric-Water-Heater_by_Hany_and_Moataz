/*
 * DIO_private.h
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */



//gaurd
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

typedef struct
{
	uint8 PIND;      // written by order from data sheet
	uint8 DDRD;
	uint8 PORTD;
	
	uint8 PINC;
	uint8 DDRC;
	uint8 PORTC;
	
	uint8 PINB;
	uint8 DDRB;
	uint8 PORTB;
	
	uint8 PINA;
	uint8 DDRA;
	uint8 PORTA;
	
}DIO_TYPE;

#define DIO ((DIO_TYPE*) 0x30)   // by datasheet order make start of struct block with start address  // pointer to struct to access with -> and . operator

// or other way longggg way wriyyen one by one
// typedef volatile unint8_t* const reg_type8_t;
// #define PIND ( *(reg_type8_t)(0x30) )
// #define DDRD ( *(reg_type8_t)(0x31) )  ... . .. . . . . .

#endif

/*
 * DIO_private.h
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */