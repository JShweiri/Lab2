/*	Author: jshwe001
 *      Partner(s) Name: Ryan Giron
 *	Lab Section: 024
 *	Assignment:1 Lab #2  Exercise # 3
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
    PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF;
    PORTB = 0x00;

    unsigned char tmpA = 0x00;

    while (1)
    {
        tmpA = 0;
        tmpA += PINA & 1;
        tmpA += (PINA >> 1) & 1;
        tmpA += (PINA >> 2) & 1;
        tmpA += (PINA >> 3) & 1;

        tmpA = 4 - tmpA;

        if (tmpA == 0)
        {
            tmpA |= 128;
        }

        PORTB = (PORTA & 120) | tmpA;
    }
    return 0;
}