/*	Author: jshwe001
 *      Partner(s) Name: Ryan Giron
 *	Lab Section: 024
 *	Assignment:1 Lab #2  Exercise # 4
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void)
{
    /* Insert DDR and PORT initializations */
    /* Insert your solution below */
    DDRA = 0x00;
    PORTA = 0xFF;
    DDRB = 0x00;
    PORTB = 0xFF;
    DDRC = 0x00;
    PORTC = 0xFF;
    DDRD = 0xFF;
    PORTD = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char total = 0x00;
    while (1)
    {
        tmpA = 0;
        unsigned char weight_A = PINA;
        unsigned char weight_B = PINB;
        unsigned char weight_C = PINC;
        total = weight_A + weight_B + weight_C;

        if (total > 140)
        {
            tmpA = 0x01;
        }
        if ((weight_A - weight_C) > 80 || (weight_A - weight_C) < -80)
        {
            tmpA |= 0x02;
        }
        PORTD = (total >> 2 & 0xFC) | tmpA;
    }
    return 0;
}