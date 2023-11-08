/*
 * Cooling_Element_Fan.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 

#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "Push_Buttons_interface.h"
#include "Push_Buttons_private.h"
#include "Push_Buttons_config.h"

uint8 pushButtonValue = 1 ; // var to store PUSH button input value (high by default)

void HAL_udtInitPushButtons(void)
{
	DownButton_Input;			// push button
	DownButton_HIGH;			// MAKE PUSH button high  // because avr are all pull up resistor (high by default)

	UpButton_Input;				// Up push button output
	UpButton_HIGH;				// MAKE PUSH button high  // because avr are all pull up resistor (high by default)
	
	ChangeStateButton_Input;	// ChangeStateButton push button output
	ChangeStateButton_HIGH;		// MAKE PUSH button high  // because avr are all pull up resistor (high by default)

}

Std_ReturnState HAL_udtCheck_DownButton(void)
{
	DownButton_GetValue(&pushButtonValue);			// get pushButtonValue1
	if(pushButtonValue == DIO_HIGH)		   			// check if button is pushed
	{
		while(pushButtonValue == DIO_HIGH)
		{
			DownButton_GetValue(&pushButtonValue);
		}
		return true;
	}
	else
	{
		return false;
	}
}

Std_ReturnState HAL_udtCheck_UpButton(void)
{
		UpButton_GetValue(&pushButtonValue);		// get pushButtonValue1
		if(pushButtonValue == DIO_HIGH)				// check if button is pushed
		{
			while(pushButtonValue == DIO_HIGH)
			{
				UpButton_GetValue(&pushButtonValue);
			}
			return true;
		}
		else
		{
			return false;
		}
}

Std_ReturnState HAL_udtCheck_ChangeStateButton(void)
{
	ChangeStateButton_GetValue(&pushButtonValue);	// get pushButtonValue1
	if(pushButtonValue == DIO_HIGH)					// check if button is pushed
	{
		while(pushButtonValue == DIO_HIGH)
		{
			ChangeStateButton_GetValue(&pushButtonValue);
		}
		return true;
	}
	else
	{
		return false;
	}
}

/*
 * Cooling_Element_Fan.c
 *
 * Created: 10/30/2023 9:05:47 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 