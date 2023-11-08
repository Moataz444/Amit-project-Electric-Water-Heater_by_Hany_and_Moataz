/*
 * Timer_private.h  
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

#ifndef _TIMER_PRIVATE_H_
#define _TIMER_PRIVATE_H_

#define TIMER0_NORMAL	1u
#define TIMER0_PWM_PC	2u
#define TIMER0_CTC		3u
#define TIMER0_PWM_FAST	4u

#define TIMER0_NO_PRESCALING	u1
#define TIMER0_DIV_BY_8			u2
#define TIMER0_DIV_BY_64		u3
#define TIMER0_DIV_BY_256		u4
#define TIMER0_DIV_BY_1024		u5
#define TIMER0_EXTERNAL_FALIING	u6
#define TIMER0_EXTERNAL_RISING	u7

#define TIMER1_NO_PRESCALING	u1
#define TIMER1_DIV_BY_8			u2
#define TIMER1_DIV_BY_64		u3
#define TIMER1_DIV_BY_256		u4
#define TIMER1_DIV_BY_1024		u5
#define TIMER1_EXTERNAL_FALIING	u6
#define TIMER1_EXTERNAL_RISING	u7

#define TIMER2_NO_PRESCALING	u1
#define TIMER2_DIV_BY_8			u2
#define TIMER2_DIV_BY_32		u3
#define TIMER2_DIV_BY_64		u4
#define TIMER2_DIV_BY_128		u5
#define TIMER2_DIV_BY_256		u6
#define TIMER2_DIV_BY_1024		u7

/* Timer0 */
#define  OCR0		*((volatile uint8*) 0x5Cu )
#define  TIMSK		*((volatile uint8*) 0x59u )
#define  TIFR		*((volatile uint8*) 0x58u )
#define  TCCR0		*((volatile uint8*) 0x53u )
#define  TCNT0		*((volatile uint8*) 0x52u )
#define  TCCR1A		*((volatile uint8*) 0x4Fu )
#define  TCCR1B		*((volatile uint8*) 0x4Eu )
#define  ICR1		*((volatile uint16*) 0x46u ) // icrl and icrh
#define  OCR1A		*((volatile uint16*) 0x4Au ) // ocrl and ocrh

/* Timer1 */
#define TCCR1A      *((volatile uint8*)	0x4Fu )
#define TCCR1B      *((volatile uint8*)	0x4Eu )   
#define TCNT1		*((volatile uint16*) 0x4Cu )

/* Timer2 */
#define TCCR2      *((volatile uint8*)	0x45u )
#define TCNT2      *((volatile uint8*)	0x44u ) 

#endif

/*
 * Timer_private.h  
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */