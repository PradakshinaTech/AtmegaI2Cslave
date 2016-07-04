
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#include "I2C_slave.h"

// buffer used to convert integer to string
char buffer[3];

int main(void){
	
	//init_uart(57600);
	int i;
	I2C_init(0x32); // initalize as slave with address 0x32
	DDRD=0x0F;
	DDRC=0x00;
	PORTC|=0x0F;
	PORTD=0x0F;
	rxbuffer[0]=0x0F;
	// allow interrupts
	sei();
	txbuffer[1]=0x0F;
	txbuffer[2]=0xF0;
	txbuffer[3]=0x55;
	
	while(1){
			txbuffer[2]=(0x0F&PINC);
			PORTD&=0xF0;
/*			PORTD|=0x01;
			_delay_ms(2000);
			PORTD&=0xF0;
			PORTD|=0x02;
			_delay_ms(2000);
			PORTD&=0xF0;
			PORTD|=(last_status&0x0F);
			_delay_ms(1000);
			PORTD&=0xF0;
			PORTD|=((last_status>>4)&0x0F);
			_delay_ms(1000);*/
//			PORTD|=(0x0F&PINC);
			PORTD|=(0x0F&rxbuffer[0]);
		// convert receiver buffer index 0 to character array and send it via UART
	//	itoa(rxbuffer[0], buffer, 10);
	//	uart_puts(buffer);
	//	txbuffer[0]=0;
//		txbuffer[1]=1;
//		txbuffer[2]=2;
//		txbuffer[3]=3;
//		txbuffer[4]=4;
//		PORTD=rxbuffer[0]&0x0F;
//		PORTD=(PINC&0x0F);
/*		for(i=0;i<dataloglevel;i++)
		{
			PORTD=0x00;
			_delay_ms(100);
			PORTD=0x01;
			_delay_ms(100);
			PORTD=0x00;
			_delay_ms(100);
			PORTD=datalog[i]&0x07;
			_delay_ms(1000);
			PORTD=0x00;
			_delay_ms(100);
			PORTD=0x02;
			_delay_ms(100);
			PORTD=0x00;
			_delay_ms(100);
			PORTD=(datalog[i]&0x38)>>3;
			_delay_ms(1000);
			PORTD=0x00;
			_delay_ms(100);
			PORTD=0x04;
			_delay_ms(100);
			PORTD=0x00;
			_delay_ms(100);
			PORTD=(datalog[i]&0xC0)>>6;
			_delay_ms(1000);
		}
		_delay_ms(2000);*/

	}
	
	return 0;
}

/*
void init_uart(uint16_t baudrate){

	uint16_t UBRR_val = (F_CPU/16)/(baudrate-1);

	UBRR0H = UBRR_val >> 8;
	UBRR0L = UBRR_val;

	UCSR0B |= (1<<TXEN0) | (1<<RXEN0) | (1<<RXCIE0); // UART TX (Transmit - senden) einschalten
	UCSR0C |= (1<<USBS0) | (3<<UCSZ00); //Modus Asynchron 8N1 (8 Datenbits, No Parity, 1 Stopbit)
}

void uart_putc(unsigned char c){

	while(!(UCSR0A & (1<<UDRE0))); // wait until sending is possible
	UDR0 = c; // output character saved in c
}

void uart_puts(char *s){
	while(*s){
		uart_putc(*s);
		s++;
	}
}
*/
