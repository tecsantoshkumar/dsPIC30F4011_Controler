/*******************************************************************************
* This is the sample program for the SKds40A + dsPIC30F4011 controlling SC16A
*
* Author: Ober Choo @ Cytron Technologies Sdn. Bhd.
* modified by: Hyng
* Date: 22Mar12
*******************************************************************************/
// Include the neccesary header files
#include <p30F4011.h>
#include "system.h"
#include "lcd.h"
#include "delay.h"
#include "uart.h"


/*******************************************************************************
* DEVICE CONFIGURATION WORDS                                                   *
*******************************************************************************/

// Primary Oscillator Mode = XT with PLL 8x.
// Clock Switching and Monitor = Off.
_FOSC(CSW_FSCM_OFF & XT_PLL8);

// Watchdog Timer = Off.
_FWDT(WDT_OFF);

// Brown Out Reset = Off.
// POR Timer Value = 64ms.
// Master Clear = Enabled.
_FBORPOR(PBOR_OFF & PWRT_64 & MCLR_EN);

// Code Protection = On.
_FGS(CODE_PROT_ON);



/*******************************************************************************
* PRIVATE FUNCTION PROTOTYPES                                                  *
*******************************************************************************/
void test_SC116A(void);
void delay(unsigned long data);
void send_cmd(unsigned char num, unsigned int data, unsigned int ramp);

/*******************************************************************************
* Global Variables                                                             *
*******************************************************************************/

/*******************************************************************************
* MAIN FUNCTION                                                                *
*******************************************************************************/
int main(void)
{	
	// Clear all ports.	
	LATB = 0;
	LATC = 0;
	LATD = 0;
	LATE = 0;
	LATF = 0;
	
	// Initialize I/O directions.
	TRISB = 0;
	TRISC = 0;
	TRISD = 0;
	TRISDbits.TRISD0 = 1;	// SW2 is connected at RD0 of dsPIC30F4011/3011
	TRISE = 0;				// dsPIC30F3011 & 4011 have PORTE
	TRISEbits.TRISE8 = 1;	// SW1 is connected at RE8 of dsPIC30F4011/3011
	TRISF = 0;	

	
	// Wait 1ms before we start the loop.
	delay_ms(200);	
	lcd_initialize();	// initialize LCD
	
	lcd_clear();
	lcd_putstr("     Cytron\n  Technologies");	//Buzzer and LED share same output pin	
	delay_ms(1500);
	
	lcd_clear();
	lcd_putstr("    SC16A\n  dsPIC30F4011");	
	delay_ms(1500);	
	LED1 = 0;
	LED2 = 0;

	while(1){
			if(SW1==0)
			{
				test_SC116A();
			}

	}		
	
		

}
// =========================================== PRIVATE Function Defination =================================
/*******************************************************************************
* PRIVATE FUNCTION: test_uart1
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Test the UART1.
*
*******************************************************************************/
void test_SC116A(void)
{	
	unsigned char i = 0, j=0;
	while (SW1==1) // Loop until SW1 is press
	{
	uart1_initialize();
	lcd_clear();
	lcd_putstr("sending");	
		while(1)	
		{
	
				for(i=0x40;i<0x51;i++)
				{
					send_cmd(i,200,50);
				}
				for(j=0;j<80;j++)
				{
				delay(45000);
				}
				for(i=0x40;i<0x51;i++)
				{
					send_cmd(i,1200,50);
				}
				for(j=0;j<80;j++)
				{
				delay(45000);
				}
			
	
		

		}
	}//while (SW1 == 1)		

}



/*******************************************************************************/
void send_cmd(unsigned char num, unsigned int data, unsigned int ramp)
{
	unsigned char higher_byte=0, lower_byte=0;
	
	//position value from 0-1463 are greater than a byte
	//so needs two bytes to send
	higher_byte=(data>>6)&0x003f;		//higher byte = 0b00xxxxxx
	lower_byte=data&0x003f;				//lower byte  = 0b00xxxxxx

	uart1_transmit(num);
	uart1_transmit(higher_byte);
	uart1_transmit(lower_byte);
	uart1_transmit(ramp);
}

void delay(unsigned long data)			//delay function, the delay time
{										//depend on the given value
	for( ;data>0;data-=1);
}
