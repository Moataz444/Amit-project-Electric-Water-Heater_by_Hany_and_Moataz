/*
 * STD_TYPES.h
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

# ifndef _STD_TYPES_H_ // syntax style _NAME_H_
# define _STD_TYPES_H_

typedef unsigned char		uint8;
typedef unsigned short int  uint16;
typedef unsigned long int	uint32;

typedef enum	// test cases
{
	E_OK		, //0
	E_NOT_OK	, //1
	E_PENDING	, //2
	}Std_ReturnType; //new name
	
typedef enum
{
	false	, //0
	true	, //1
	}Std_ReturnState; //new name

#endif

/*
 * STD_TYPES.h
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */
