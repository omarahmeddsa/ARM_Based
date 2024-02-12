/*
 * Bit_calc.h
 *
 *  Created on: Jul 2, 2023
 *      Author: omar
 */

#ifndef BIT_CALC_H_
#define BIT_CALC_H_

#define Set_Bit(var,bit_no) (var) |= (1<<(bit_no))

#define Clear_Bit(var,bit_no) (var) &= (~(1<<(bit_no)))

#define Toggle_Bit(var,bit_no) (var) ^= (1<<(bit_no))

#define Get_Bit(var,bit_no) ((var)>>(bit_no) &(1))

#define Assign_Bit(var,bit_no,value) do{ if(value == 1) Set_Bit(var,bit_no);\
	else Clear_Bit(var,bit_no);}while(0)


#endif /* BIT_CALC_H_ */
