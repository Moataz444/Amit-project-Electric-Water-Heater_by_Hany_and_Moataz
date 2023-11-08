/*
 * _7_SEGMENT.c
 *
 * Created: 7/28/2023 4:19:02 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "_7_Segment_interface.h"
#include "_7_Segment_private.h"

void HAL_udtEnable7Segment(void)
{
	 En1_HIGH;	// 7-SEGMENT  EN1 HIGH
	 En1_HIGH;	// 7-SEGMENT  EN2 HIGH
}

void HAL_udtDisable7Segment(void)
{
	En1_LOW;	// 7-SEGMENT  EN1 LOW
	En2_LOW;	// 7-SEGMENT  EN2 LOW
}

void HAL_udtInit7Segment (void)
{
	En1_OUTPUT; // 7-SEGMENT  EN1 OUTPUT
	En2_OUTPUT; // 7-SEGMENT  EN2 OUTPUT
	
	A_OUTPUT;	// 7-SEGMENT  A OUTPUT
	B_OUTPUT;	// 7-SEGMENT  B OUTPUT
	C_OUTPUT;	// 7-SEGMENT  C OUTPUT
	D_OUTPUT;	// 7-SEGMENT  D OUTPUT
}


void HAL_udtSet7Segment(uint8 u8_7_SegmentNumber)
{

	switch(u8_7_SegmentNumber)
	{
		case 0: A_LOW; B_LOW; C_LOW; D_LOW;
				break;
		case 1: A_LOW; B_LOW; C_LOW; D_HIGH;
				break;
		case 2: A_LOW; B_LOW; C_HIGH; D_LOW;
				break;					
		case 3: A_LOW; B_LOW; C_HIGH; D_HIGH;
				break;
		case 4: A_LOW; B_HIGH; C_LOW; D_LOW;
				break;
		case 5: A_LOW; B_HIGH; C_LOW; D_HIGH;
				break;
		case 6: A_LOW; B_HIGH; C_HIGH; D_LOW;
				break;
		case 7: A_LOW; B_HIGH; C_HIGH; D_HIGH;
				break;
		case 8: A_HIGH; B_LOW; C_LOW; D_LOW;
				break;
		case 9: A_HIGH; B_LOW; C_LOW; D_HIGH;
				break;
		default: break;
	}
}

void HAL_udtWrite_On_2_7Segment (uint8 u8_7_SegmentNumber)
{
	
	int right_num = u8_7_SegmentNumber % 10;
	int left_num = u8_7_SegmentNumber / 10;
	
	HAL_udtSet7Segment(left_num);
	En1_HIGH; // Enable 1st 7-seg
	En2_LOW;
	_delay_ms(2);
	
	HAL_udtSet7Segment(right_num);
	En1_LOW; // Enable 1st 7-seg
	En2_HIGH;
	_delay_ms(2);
	
	HAL_udtDisable7Segment();
}

/*
 * _7_SEGMENT.c
 *
 * Created: 7/28/2023 4:19:02 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */ 