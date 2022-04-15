/*******************************************************************************
* This file provides the functions for the UART module.
* Using SKds40A + dsPIC30F4011, it should be compatible for dsPIC30F3011
* Author: Kong Wai Weng @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#include <p30F4011.h>
#include "system.h"
#include "uart.h"



/*******************************************************************************
* PUBLIC FUNCTION: uart1_initialize
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize the UART1 module.
*
*******************************************************************************/
void uart1_initialize(void)
{
	// Set the Baud Rate.
	U1BRG = 129;								// ((Fosc/4)/(16 * Baud rate)) - 1
												// 129 = 9600bps baudrate for 10MHz crystal with 8xPLL
												// 20 = 57600bps baudrate for 10MHz crystal with 8xPLL
												// 10 = 115200bps baudrate for 10MHz crystal with 8xPLL
	U1MODEbits.ALTIO = 0;						// 1 = Communicate using U1ATX and U1ARX pins (alternative).
												// 0 = Communicate using U1TX and U1RX pins.
	U1STAbits.URXISEL = 0;          			// Interrupt flag bit is set for every character received.
	IPC2bits.U1RXIP   = 4;          			// UART1 Receive Interrupt Priority = 4.
	U1STAbits.OERR    = 0;	        			// Clear the Receive Overflow Flag.
	IFS0bits.U1RXIF   = 0;          			// Clear the UART1 Receive Interrupt flag.
	IEC0bits.U1RXIE   = 0;          			// Disable UART1 Receive Interrupt.
	U1MODEbits.UARTEN = 1;						// Enable UART1.
	U1STAbits.UTXEN = 1;           				// Enable UART1 Transmit.
}

/*******************************************************************************
* PUBLIC FUNCTION: uart1a_initialize
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize the UART1 alternative module.
*
*******************************************************************************/
void uart1a_initialize(void)
{
	// Set the Baud Rate.
	U1BRG = 129;								// ((Fosc/4)/(16 * Baud rate)) - 1
												// 129 = 9600bps baudrate for 10MHz crystal with 8xPLL
												// 20 = 57600bps baudrate for 10MHz crystal with 8xPLL
												// 10 = 115200bps baudrate for 10MHz crystal with 8xPLL
	U1MODEbits.ALTIO = 1;						// 1 = Communicate using U1ATX and U1ARX pins (alternative).
												// 0 = Communicate using U1TX and U1RX pins.
	U1STAbits.URXISEL = 0;          			// Interrupt flag bit is set for every character received.
	IPC2bits.U1RXIP   = 4;          			// UART1 Receive Interrupt Priority = 4.
	U1STAbits.OERR    = 0;	        			// Clear the Receive Overflow Flag.
	IFS0bits.U1RXIF   = 0;          			// Clear the UART1 Receive Interrupt flag.
	IEC0bits.U1RXIE   = 0;          			// Disable UART1 Receive Interrupt.
	U1MODEbits.UARTEN = 1;						// Enable UART1.
	U1STAbits.UTXEN = 1;           				// Enable UART1 Transmit.
}

/*******************************************************************************
* PUBLIC FUNCTION: uart2_initialize
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize the UART2 module.
*
*******************************************************************************/
void uart2_initialize(void)
{
	// Set the Baud Rate.
	U2BRG = 129;								// ((Fosc/4)/(16 * Baud rate)) - 1
												// 129 = 9600bps baudrate for 10MHz crystal with 8xPLL
												// 20 = 57600bps baudrate for 10MHz crystal with 8xPLL
												// 10 = 115200bps baudrate for 10MHz crystal with 8xPLL
	
	U2STAbits.URXISEL = 0;          			// Interrupt flag bit is set for every character received.
	IPC6bits.U2RXIP   = 5;          			// UART2 Receive Interrupt Priority = 4.
	U2STAbits.OERR    = 0;	        			// Clear the Receive Overflow Flag.
	IFS1bits.U2RXIF   = 0;          			// Clear the UART2 Receive Interrupt flag.
	IEC1bits.U2RXIE   = 0;          			// Disable UART2 Receive Interrupt.
	U2MODEbits.UARTEN = 1;						// Enable UART2.
	U2STAbits.UTXEN = 1;           				// Enable UART2 Transmit.
}


/*******************************************************************************
* PUBLIC FUNCTION: uart1_transmit
*
* PARAMETERS:
* ~ uc_data		- The data that we want to transmit.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* This function will transmit one byte of data using UART1. This is a blocking
* function, if the transmit buffer is full, we will wait until the
* data in the buffer has been sent out before we move in the new data.
*
*******************************************************************************/
void uart1_transmit(unsigned char uc_data)
{
	// Wait until the transmit buffer is ready for new data.
	while (U1STAbits.UTXBF == 1);
	
	// Transmit the data.
	U1TXREG = uc_data;
}

/*******************************************************************************
* PUBLIC FUNCTION: uart2_transmit
*
* PARAMETERS:
* ~ uc_data		- The data that we want to transmit.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* This function will transmit one byte of data using UART2. This is a blocking
* function, if the transmit buffer is full, we will wait until the
* data in the buffer has been sent out before we move in the new data.
*
*******************************************************************************/
void uart2_transmit(unsigned char uc_data)
{
	// Wait until the transmit buffer is ready for new data.
	while (U2STAbits.UTXBF == 1);
	
	// Transmit the data.
	U2TXREG = uc_data;
}

/*******************************************************************************
* PUBLIC FUNCTION: uc_uart1_receive
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ The data received from the UART1.
*
* DESCRIPTIONS:
* This function will receive one byte of data using UART1. This is a blocking
* function because if the receive buffer is empty, we will wait until the
* data is received.
*
*******************************************************************************/
unsigned char uc_uart1_receive(void)
{
	// Wait until there is data available in the receive buffer.
	while (U1STAbits.URXDA == 0);
	
	// Clear the overflow bit and return the received data.
	U1STAbits.OERR = 0;
	return U1RXREG;
}

/*******************************************************************************
* PUBLIC FUNCTION: uc_uart2_receive
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ The data received from the UART2.
*
* DESCRIPTIONS:
* This function will receive one byte of data using UART2. This is a blocking
* function because if the receive buffer is empty, we will wait until the
* data is received.
*
*******************************************************************************/
unsigned char uc_uart2_receive(void)
{
	// Wait until there is data available in the receive buffer.
	while (U2STAbits.URXDA == 0);
	
	// Clear the overflow bit and return the received data.
	U2STAbits.OERR = 0;
	return U2RXREG;
}


/*******************************************************************************
* PUBLIC FUNCTION: uart1_putstr
*
* PARAMETERS:
* ~ csz_string	- The null terminated string to transmit.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Transmit a string using the UART1.
*
*******************************************************************************/
void uart1_putstr(const char* csz_string)
{
	// Loop until the end of string.
	while (*csz_string != '\0') {
		uart1_transmit(*csz_string);
			
		// Point to next character.
		csz_string++;
	}
}

/*******************************************************************************
* PUBLIC FUNCTION: uart2_putstr
*
* PARAMETERS:
* ~ csz_string	- The null terminated string to transmit.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Transmit a string using the UART2.
*
*******************************************************************************/
void uart2_putstr(const char* csz_string)
{
	// Loop until the end of string.
	while (*csz_string != '\0') {
		uart2_transmit(*csz_string);
			
		// Point to next character.
		csz_string++;
	}
}
