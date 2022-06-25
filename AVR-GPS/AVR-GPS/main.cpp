/*
 * AVR-GPS.cpp
 *
 * Created: 25.06.2022 21:19:50
 * Author : Enes
 */ 


#include "nmea/nmea.h"
#include "uart.h"

#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>

char buffer[20], float_[15];

NMEA nmea; //nmea module
UART uart0; // uart module

float speed;


int main(void)
{
	 uart0.Init(0, 9600, true); /* Initialize UART */
    /* Replace with your application code */
    while (1) 
    {
		
            if (nmea.isdataready()) {
	            speed = nmea.getSpeed();
                dtostrf(speed, 3, 2, float_);
                sprintf(buffer, "speed = %s g\t", float_);
                uart0.Send(buffer);
                uart0.Send("\n");

	            } else {
	              uart0.Send("waiting...\n");
            }
			_delay_ms(1000);
			
    }
}

ISR(USART_RX_vect) {
	volatile char c = UDR0; //Read the value out of the UART buffer
	nmea.fusedata(c);
}