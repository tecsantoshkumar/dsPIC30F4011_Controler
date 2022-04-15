/*******************************************************************************
* This file provides the functions for delay using SKds40A + dsPIC30F4011
* It should be compatible for dsPIC30F3011
*
* Author: Kong Wai Weng @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#include <libpic30.h>
#include "system.h"
#include "delay.h"



/*******************************************************************************
* PRIVATE FUNCTION: delay_ms
*
* PARAMETERS:
* ~ ui_value	- The period for the delay in miliseconds.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Delay in miliseconds.
*
*******************************************************************************/
void delay_ms(unsigned int ui_value)
{
	__delay32(_XTAL_FREQ/4000 * ui_value);
}
