/*
 * GIE_program.c
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */
#include "STD_TYPES.h"
#include "BIT_MATH_H.h"

#include "GIE_interface.h"
#include "GIE_private.h"


void MCAL_GIE_vidEnable (void)
{
	SET_BIT(SREG, I_BIT) ;
}

void MCAL_GIE_vidDisable (void)
{
	CLR_BIT(SREG, I_BIT) ;
}

/*
 * GIE_program.c
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */