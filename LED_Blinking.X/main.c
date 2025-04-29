/*
 * File:   main.c
 * Author: crazy
 *
 * Created on 22 March, 2025, 8:59 PM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000
void main(void) {
  TRISB = 0;
  PORTBbits.RB0 = 1;
  __delay_ms(1000);
   PORTBbits.RB0 = 0;
    __delay_ms(1000);
    return;
}

