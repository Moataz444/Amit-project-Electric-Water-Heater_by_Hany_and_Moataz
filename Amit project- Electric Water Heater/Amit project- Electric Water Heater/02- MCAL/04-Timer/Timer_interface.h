/*
 * Timer_interface.h   
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

// Timer0 counter 
void MCAL_Timer0_vidInit (void) ;
void MCAL_Timer0_vidEnable(uint16 u16Timer0_Counter);
void MCAL_Timer0_vidDisable(void);
void MCAL_TIMER0_vidCallBack (void (*pvCallBack) (void) ) ;

// Timer1 counter 
void MCAL_Timer1_vidInit(void);
void MCAL_Timer1_vidEnable(uint16 u16Timer1_Counter);
void MCAL_Timer1_vidDisable(void);
void MCAL_TIMER1_vidCallBack (void (*pvCallBack) (void) );

// Timer2 counter
void MCAL_Timer2_vidInit(void);
void MCAL_Timer2_vidEnable(uint16 u16Timer2_Counter);
void MCAL_Timer2_vidDisable(void);
void MCAL_TIMER2_vidCallBack (void (*pvCallBack) (void) );

#endif

/*
 * Timer_interface.h   
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */
