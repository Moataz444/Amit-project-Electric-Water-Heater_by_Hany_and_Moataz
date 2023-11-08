/*
 * EEPROM_private.h      
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

#ifndef _EEPROM_PRIVATE_H_
#define _EEPROM_PRIVATE_H_


#define EEAR	*((volatile uint16*) 0x3Eu ) // eearh and eearl
// #define EEARL	*((volatile uint8*) 0x3Fu )
#define EEDR	*((volatile uint8*) 0x3Du )
#define EECR	*((volatile uint8*) 0x3Cu )


#endif

/*
 * EEPROM_private.h      
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */