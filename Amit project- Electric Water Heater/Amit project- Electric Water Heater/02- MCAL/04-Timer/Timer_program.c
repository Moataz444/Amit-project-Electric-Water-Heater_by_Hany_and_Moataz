/*
 * Timer_program.c 
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

#include "STD_TYPES.h"
#include "BIT_MATH_H.h"

#include "DIO_interface.h"

#include "Timer_interface.h"
#include "Timer_config.h"
#include "Timer_private.h"

void MCAL_Timer0_vidInit (void)
{
	/*
	Options:
			TIMER0_NORMAL
			TIMER0_PWM_PC
			TIMER0_CTC
			TIMER0_PWM_FAST
	*/
	#if TIMER0_MODE_OF_OPERATIONS == TIMER0_NORMAL
	CLR_BIT(TCCR0, 3u);
	CLR_BIT(TCCR0, 6u);
	#elif TIMER0_MODE_OF_OPERATIONS == TIMER0_PWM_PC
	CLR_BIT(TCCR0, 3u);
	SET_BIT(TCCR0, 6u);
	#elif TIMER0_MODE_OF_OPERATIONS == TIMER0_CTC
	SET_BIT(TCCR0, 3u);
	CLR_BIT(TCCR0, 6u);
	// Enable CTC Interrupt
	// SET_BIT(TIMSK,1);
	#elif TIMER0_MODE_OF_OPERATIONS == TIMER0_PWM_FAST
	SET_BIT(TCCR0, 3u);
	SET_BIT(TCCR0, 6u);
	#else
		#error "Invalid mode of operation"
	#endif
	
	/* !Comment: Enable timer0 OVF interrupt*/
	SET_BIT (TIMSK, 0);
	
	// Select Non Inverting Mode in TIMER0_PWM_FAST
// 	set_BIT(TCCR0,5u); // com 1 and 0
// 	CLR_BIT(TCCR0,4u);
}

void MCAL_Timer0_vidEnable(uint16 u16Timer0_Counter)
{
	TCNT0 = u16Timer0_Counter; // start register from 152 
// 	Timer0_Counter = 0; // counter++ till 2442 in every overflow interrupt then disable timer
	// Selected Prescaler Value = 64
	/*
	Options:
			TIMER0_NO_PRESCALING
			TIMER0_DIV_BY_8
			TIMER0_DIV_BY_64
			TIMER0_DIV_BY_256
			TIMER0_DIV_BY_1024
			TIMER0_EXTERNAL_FALIING
			TIMER0_EXTERNAL_RISING
*/
	#if TIMER0_CLOCK_SELECTIONS == TIMER0_NO_PRESCALING
	SET_BIT(TCCR0, 0u);
	CLR_BIT(TCCR0, 1u);
	CLR_BIT(TCCR0, 2u);
	#elif TIMER0_CLOCK_SELECTIONS == TIMER0_DIV_BY_8
	CLR_BIT(TCCR0, 0u);
	SET_BIT(TCCR0, 1u);
	CLR_BIT(TCCR0, 2u);
	#elif TIMER0_CLOCK_SELECTIONS == TIMER0_DIV_BY_64
	SET_BIT(TCCR0, 0u);
	SET_BIT(TCCR0, 1u);
	CLR_BIT(TCCR0, 2u);
	#elif TIMER0_CLOCK_SELECTIONS == TIMER0_DIV_BY_256
	CLR_BIT(TCCR0, 0u);
	CLR_BIT(TCCR0, 1u);
	SET_BIT(TCCR0, 2u);
	#elif TIMER0_CLOCK_SELECTIONS == TIMER0_DIV_BY_1024
	SET_BIT(TCCR0, 0u);
	CLR_BIT(TCCR0, 1u);
	SET_BIT(TCCR0, 2u);
	#elif TIMER0_CLOCK_SELECTIONS == TIMER0_EXTERNAL_FALIING
	CLR_BIT(TCCR0, 0u);
	SET_BIT(TCCR0, 1u);
	SET_BIT(TCCR0, 2u);
	#elif TIMER0_CLOCK_SELECTIONS == TIMER0_EXTERNAL_RISING
	SET_BIT(TCCR0, 0u);
	SET_BIT(TCCR0, 1u);
	SET_BIT(TCCR0, 2u);
	#else
	#error "Invalid clock selection"
	#endif
}

void MCAL_Timer0_vidDisable(void)
{
	// No clock source (Timer/Counter stopped)
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

void MCAL_Timer0_vidDelay_1_seca (void)
{
	uint8 i ;
	TCNT0 = 112 ;
	for (i=0 ; i < 977; i++)
	{
		while ( ( GET_BIT(TIFR, 0)  ) == 0); // when == 1  == overflow flag
		SET_BIT(TIFR, 0); // cleared by writing  1
	}
}

void MCAL_Timer0_vidDelay_5_seca (void)
{
	uint8 i ;
	TCNT0 = 152 ;
	for (i=0 ; i < 2442; i++)
	{
		while ( ( GET_BIT(TIFR, 0)  ) == 0); // when == 1  == overflow flag without interupt
		SET_BIT(TIFR, 0); // cleared by writing  1
	}
}

void (*TIMER0_pvCallBack) (void);
void MCAL_TIMER0_vidCallBack (void (*pvCallBack) (void) ) 
{
	TIMER0_pvCallBack = pvCallBack ;
}

void __vector_11 (void) __attribute__ ((signal)); // interupt for timer0 number 12 -1 (starts from 0) in Datasheet
void __vector_11(void)
{
	TIMER0_pvCallBack();
}

void MCAL_Timer1_vidInit(void)
{
	// Select Mode = Normal Mode
	CLR_BIT(TCCR1A, 4);
	CLR_BIT(TCCR1A, 5);
	CLR_BIT(TCCR1A, 6);
	CLR_BIT(TCCR1A, 7);
	
	// Waveform Generation Mode = Normal Mode
	CLR_BIT(TCCR1A, 0);
	CLR_BIT(TCCR1A, 1);
	
	CLR_BIT(TCCR1B, 3);
	CLR_BIT(TCCR1B, 4);
	
	/* !Comment:  Bit 2 – TOIE1: Timer1/Counter1, Overflow Interrupt Enable */
	SET_BIT (TIMSK, 2);
}

void MCAL_Timer1_vidEnable(uint16 u16Timer1_Counter)
{
	TCNT1 = u16Timer1_Counter; // start register from 152
	/*
	Options:
			TIMER1_NO_PRESCALING
			TIMER1_DIV_BY_8
			TIMER1_DIV_BY_64
			TIMER1_DIV_BY_256
			TIMER1_DIV_BY_1024
			TIMER1_EXTERNAL_FALIING
			TIMER1_EXTERNAL_RISING
*/
	#if TIMER1_CLOCK_SELECTIONS == TIMER1_NO_PRESCALING
	SET_BIT(TCCR1B, 0u);
	CLR_BIT(TCCR1B, 1u);
	CLR_BIT(TCCR1B, 2u);
	#elif TIMER1_CLOCK_SELECTIONS == TIMER1_DIV_BY_8
	CLR_BIT(TCCR1B, 0u);
	SET_BIT(TCCR1B, 1u);
	CLR_BIT(TCCR1B, 2u);
	#elif TIMER1_CLOCK_SELECTIONS == TIMER1_DIV_BY_64
	SET_BIT(TCCR1B, 0u);
	SET_BIT(TCCR1B, 1u);
	CLR_BIT(TCCR1B, 2u);
	#elif TIMER1_CLOCK_SELECTIONS == TIMER1_DIV_BY_256
	CLR_BIT(TCCR1B, 0u);
	CLR_BIT(TCCR1B, 1u);
	SET_BIT(TCCR1B, 2u);
	#elif TIMER1_CLOCK_SELECTIONS == TIMER1_DIV_BY_1024
	SET_BIT(TCCR1B, 0u);
	CLR_BIT(TCCR1B, 1u);
	SET_BIT(TCCR1B, 2u);
	#elif TIMER1_CLOCK_SELECTIONS == TIMER1_EXTERNAL_FALIING
	CLR_BIT(TCCR1B, 0u);
	SET_BIT(TCCR1B, 1u);
	SET_BIT(TCCR1B, 2u);
	#elif TIMER1_CLOCK_SELECTIONS == TIMER1_EXTERNAL_RISING
	SET_BIT(TCCR1B, 0u);
	SET_BIT(TCCR1B, 1u);
	SET_BIT(TCCR1B, 2u);
	#else
	#error "Invalid clock selection"
	#endif
}

void MCAL_Timer1_vidDisable(void)
{
	CLR_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	CLR_BIT(TCCR1B, 2);
}

void (*TIMER1_pvCallBack) (void);
void MCAL_TIMER1_vidCallBack (void (*pvCallBack) (void) )
{
	TIMER1_pvCallBack = pvCallBack ;
}

void __vector_9 (void) __attribute__ ((signal)); // interupt for timer1 number 12 -1 (starts from 0) in Datasheet
void __vector_9(void)
{
	TIMER1_pvCallBack();
}

void MCAL_Timer2_vidInit(void)
{
	// Waveform Generation Mode = Normal Mode
	CLR_BIT(TCCR2, 3);
	CLR_BIT(TCCR2, 6);
	
	// Compare Output Mode = Normal Mode
	CLR_BIT(TCCR2, 4);
	CLR_BIT(TCCR2, 5);
	
	/* !Comment:  Bit 6 – TOIE2: Timer/Counter2 Overflow Interrupt Enable */
	SET_BIT (TIMSK, 6);
}

void MCAL_Timer2_vidEnable(uint16 u16Timer2_Counter)
{
	TCNT2 = u16Timer2_Counter; // start register from 152
/*
	Options:
			TIMER2_NO_PRESCALING
			TIMER2_DIV_BY_8
			TIMER2_DIV_BY_32
			TIMER2_DIV_BY_64
			TIMER2_DIV_BY_128
			TIMER2_DIV_BY_256
			TIMER2_DIV_BY_1024
*/
	#if TIMER2_CLOCK_SELECTIONS == TIMER2_NO_PRESCALING
	SET_BIT(TCCR2, 0u);
	CLR_BIT(TCCR2, 1u);
	CLR_BIT(TCCR2, 2u);
	#elif TIMER2_CLOCK_SELECTIONS == TIMER2_DIV_BY_8
	CLR_BIT(TCCR2, 0u);
	SET_BIT(TCCR2, 1u);
	CLR_BIT(TCCR2, 2u);
	#elif TIMER2_CLOCK_SELECTIONS == TIMER2_DIV_BY_32
	SET_BIT(TCCR2, 0u);
	SET_BIT(TCCR2, 1u);
	CLR_BIT(TCCR2, 2u);
	#elif TIMER2_CLOCK_SELECTIONS == TIMER2_DIV_BY_64
	CLR_BIT(TCCR2, 0u);
	CLR_BIT(TCCR2, 1u);
	SET_BIT(TCCR2, 2u);
	#elif TIMER2_CLOCK_SELECTIONS == TIMER2_DIV_BY_128
	SET_BIT(TCCR2, 0u);
	CLR_BIT(TCCR2, 1u);
	SET_BIT(TCCR2, 2u);
	#elif TIMER2_CLOCK_SELECTIONS == TIMER2_DIV_BY_256
	CLR_BIT(TCCR2, 0u);
	SET_BIT(TCCR2, 1u);
	SET_BIT(TCCR2, 2u);
	#elif TIMER2_CLOCK_SELECTIONS == TIMER2_DIV_BY_1024
	SET_BIT(TCCR2, 0u);
	SET_BIT(TCCR2, 1u);
	SET_BIT(TCCR2, 2u);
	#else
	#error "Invalid clock selection"
	#endif
}

void MCAL_Timer2_vidDisable(void)
{
	CLR_BIT(TCCR2, 0);
	CLR_BIT(TCCR2, 1);
	CLR_BIT(TCCR2, 2);
}

void (*TIMER2_pvCallBack) (void);
void MCAL_TIMER2_vidCallBack (void (*pvCallBack) (void) )
{
	TIMER2_pvCallBack = pvCallBack ;
}

void __vector_5 (void) __attribute__ ((signal)); // interupt for timer1 number 12 -1 (starts from 0) in Datasheet
void __vector_5(void)
{
	TIMER2_pvCallBack();
}

/*
 * Timer_program.c 
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */