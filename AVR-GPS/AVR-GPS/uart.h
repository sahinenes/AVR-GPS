


#define F_CPU 16000000
#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include <avr/interrupt.h>


//volatile static voidFuncPtru08 UartRxFunc;
//typedef void (*tUARTReceiverFunc)(unsigned char);

class UART {
	
	private:
		int m_index, //0 for UART0, 1 for UART1 and so on
			m_nBaudRate,
			m_nBaudRateRegister;
	//static tUARTReceiverFunc m_UARTReceiverFunc;
	public:
	
	/*
	 * Initiates UART serial communication
	 * uartindex: the UART index, for microcontrollers that have more than one (eg. atmega128 has too)
	 * baud: an integer representing the baud rate
	 * use_interrupt: receive data as interrupt, in ISR(USART0_RX_vect)/ISR(USART1_RX_vect) or by polling, using RecvPoll
	 */
	void Init(int uartindex, int baud, bool use_interrupt );
	
	/*
	 * send one byte, b
	 */
	void Send(unsigned char b);
	
	/*
	 * send a byte array (data) of given size (len)
	 */
	void Send(const unsigned char *data, int len);
	
	/*
	 * send a formated string
	 */
	void Send(char *szFormat, ...);
	
	/*
	 * wait until one byte is received, and return: blocking function
	 */
	unsigned char RecvPoll();
	
	};
