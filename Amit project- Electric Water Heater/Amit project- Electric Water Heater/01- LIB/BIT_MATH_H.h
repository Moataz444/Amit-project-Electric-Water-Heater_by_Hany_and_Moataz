/*
 * BIT_MATH_H.h
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */

# ifndef  _BIT_MATH_H_  // syntax style _NAME_H_
# define  _BIT_MATH_H_

#define SET_BIT(var, bit)		var |= (1<< bit)
#define TOG_BIT(var, bit)		var ^= (1<< bit)
#define CLR_BIT(var, bit)		var &= ~(1<< bit)
#define GET_BIT(var, bit)		((var >> bit) & 1)

#endif

/*
 * BIT_MATH_H.h
 *
 * Created: 11/1/2023 4:28:28 PM
 *  Author: Moataz Hassan, Hany El Taweel
 */