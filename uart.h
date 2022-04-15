/*******************************************************************************
* This file provides the functions for the UART module.
*
* Author: Kong Wai Weng @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#ifndef _UART_H
#define _UART_H



/*******************************************************************************
* PUBLIC FUNCTION PROTOTYPES                                                   *
*******************************************************************************/

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
extern void uart1_initialize(void);

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
extern void uart1a_initialize(void);

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
extern void uart2_initialize(void);


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
extern void uart1_transmit(unsigned char uc_data);


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
extern void uart2_transmit(unsigned char uc_data);


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
extern unsigned char uc_uart1_receive(void);


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
extern unsigned char uc_uart2_receive(void);


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
extern void uart1_putstr(const char* csz_string);

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
extern void uart2_putstr(const char* csz_string);



#endif
