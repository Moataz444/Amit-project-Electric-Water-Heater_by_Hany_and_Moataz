/*
 * ADC_private.h 
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

#define Internal_Vref_turned_off		1u
#define AVCC_with_external_capacitor	2u
#define Reserved						3u
#define Internal_Voltage_Reference		4u


#define ADMUX	*((volatile uint8*) 0x27)
#define ADCSRA	*((volatile uint8*) 0x26)
#define ADCH	*((volatile uint8*) 0x25)
#define ADCL	*((volatile uint8*) 0x24)

// #define SFIOR	*(volatile uint8*) 0x24)

#endif

/*
 * ADC_private.h 
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */
