/*******************************************************************************
* This is the header file that describes the system properties. Using SKds40A + dsPIC30F4011
* It should be compatible for dsPIC30F3011
*
* Author: Kong Wai Weng @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



// Oscillator Frequency.
#define	_XTAL_FREQ		80000000			//80MHz, running with 10MHz external Crystal, config with 8xPLL

// Default UART baud rate.
#define UART_BAUD		9600

// I/O Connections.
#define LED1			LATDbits.LATD2		// 3011 & 4011, 3014 & 4013
#define LED2			LATDbits.LATD3		// 3011 & 4011, 3014 & 4013

#define SW1				PORTEbits.RE8		// 3011 & 4011
#define SW2				PORTDbits.RD0		// 3011 & 4011

#define BUZZER 				LATFbits.LATF6			// for test board, the buzzer at RF6

// Parallel 2x16 Character LCD
#define LCD_RS			PORTFbits.RF0		// RS pin is used for LCD to differentiate data is command or character, RF0
#define LCD_E			PORTFbits.RF1		// E clock pin is connected to RF1	

#define	LCD_DATA		PORTB	// Data port of LCD is connected to PORTB, 8 bit mode
								// DB7(LCD) = RB7(dsPIC)
								// DB6(LCD) = RB6(dsPIC)
								// DB5(LCD) = RB5(dsPIC)
								// DB4(LCD) = RB4(dsPIC)
								// DB3(LCD) = RB3(dsPIC)
								// DB2(LCD) = RB2(dsPIC)
								// DB1(LCD) = RB1(dsPIC)
								// DB0(LCD) = RB0(dsPIC)
