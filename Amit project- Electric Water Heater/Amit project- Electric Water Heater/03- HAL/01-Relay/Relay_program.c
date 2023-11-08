/*
 * Relay.c
 *
 * Created: 10/30/2023 7:08:45 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 

#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "Relay_interface.h"
#include "Relay_private.h"
#include "Relay_config.h"

void HAL_udtInitRelay (void)
{
	Realy_OUTPUT; // relay output
	Realy_LOW;		 // relay low
}

void HAL_udtEnableRelay(void)
{
	Realy_HIGH;		 // relay high
}

void HAL_udtDisableRelay(void)
{
	Realy_LOW;		 // relay low
}

/*
 * Relay.c
 *
 * Created: 10/30/2023 7:08:45 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 