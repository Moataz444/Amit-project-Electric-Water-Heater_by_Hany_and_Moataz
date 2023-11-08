/*
 * EEPROM_program.c     
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

#include "STD_TYPES.h"
#include "BIT_MATH_H.h"

#include "EEPROM_private.h"
#include "EEPROM_config.h"

void EEPROM_vidWrite (uint16 u16Address, uint8 u8Data)
{
	/* wait until EEWE becomes 0. */
	while (GET_BIT(EECR, 1) !=0 ) ;
	
	/* write new EEPRM address to eear (optional) */
	EEAR = u16Address ;
	
	/* write new EEPRM data to eedr (optional) */
	EEDR = u8Data ;
	
	/* Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR */
	SET_BIT(EECR, 2) ; 
	// previos instruction will take 4 cycles 
	 /*  Within four clock cycles after setting EEMWE, write a logical one to EEWE. */
	SET_BIT(EECR, 1) ;
}

uint8 EEPROM_vidRead (uint16 u16Address)
{
	/* wait until EEWE becomes 0. */
	while (GET_BIT(EECR, 1) !=0 ) ;
	
	/* write new EEPRM address to eear (optional) */
	EEAR = u16Address ;
	
	/*  Bit 0 – EERE: EEPROM Read Enable */
	SET_BIT(EECR, 0);
	
	return EEDR ;
}

/*
 * EEPROM_program.c     
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */
