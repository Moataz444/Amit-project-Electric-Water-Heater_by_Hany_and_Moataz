/*
 * ADC_program.c
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

#include "BIT_MATH_H.h"
#include "STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

void MCAL_ADC_vidInit (void) 
{
	/*
	Options:
			Internal_Vref_turned_off					////AREF, Internal Vref turned off
			AVCC_with_external_capacitor					////AVCC with external capacitor at AREF pin
			Reserved
			Internal_Voltage_Reference				//// Internal 2.56V Voltage Reference with external capacitor at AREF pin
	*/
	#if Voltage_Reference_Selection == Internal_Vref_turned_off
	CLR_BIT(ADMUX, 6) ;
	CLR_BIT(ADMUX, 7) ;
	#elif Voltage_Reference_Selection == AVCC_with_external_capacitor
	/* !Comment: Bit 7:6 – REFS1:0: Reference Selection Bits */
	SET_BIT(ADMUX, 6) ;
	CLR_BIT(ADMUX, 7) ;
	#elif Voltage_Reference_Selection == Reserved
	CLR_BIT(ADMUX, 6) ;
	SET_BIT(ADMUX, 7) ;
	#elif Voltage_Reference_Selection == Internal_Voltage_Reference
	SET_BIT(ADMUX, 6) ;
	SET_BIT(ADMUX, 7) ;
	#else
		#error "Invalid mode of operation"
	#endif

	
	/* !Comment: Bit 5 – ADLAR: ADC Left Adjust Result */
	SET_BIT(ADMUX, 5) ;
	
	/* !Comment: Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits */
	SET_BIT(ADCSRA, 2) ;
	SET_BIT(ADCSRA, 1) ;
	SET_BIT(ADCSRA, 0) ;
	
	
	/* !Comment: Bit 7 – ADEN: ADC Enable */
	SET_BIT(ADCSRA, 7) ;
	
}

uint8 MCAL_ADC_u8ChannelRead (uint8 u8Channel) 
{
	/* !Comment:  Bit 4:0 - MUX4:0: Analog Channel */
// 	ADMUX &= 0b11100000 ;
// 	ADMUX |= u8Channel ;
	ADMUX = ADMUX & 0b11100000;
	ADMUX = ADMUX | u8Channel;	
	
	/* !Comment:  Bit 6 – ADSC: ADC Start Conversion */
	SET_BIT(ADCSRA, 6) ;
	
	/* !Comment:  Bit 4 – ADIF: ADC Interrupt Flag */
	while(GET_BIT(ADCSRA, 4) == 0);
	
	/* !Comment:  Bit 4 – ADIF is cleared by writing a logical one to the flag */
	SET_BIT(ADCSRA, 4) ;
	
	/* !Comment: return ADC output */
	return ADCH ;
}

/*
 * ADC_program.c
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */
