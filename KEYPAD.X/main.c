/*
 * File:   main.c
 * Author: crazy
 *
 * Created on 22 March, 2025, 9:31 PM
 */
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = ON          // Flash Program Memory Code Protection bit (All program memory code-protected)

#include <xc.h>
#define _XTAL_FREQ 20000000
#define RS PORTBbits.RB0 
#define RW PORTBbits.RB1
#define EN PORTBbits.RB2
#define C1 PORTBbits.RB3
#define C2 PORTBbits.RB4
#define C3 PORTBbits.RB5
#define R1 PORTCbits.RC0
#define R2 PORTCbits.RC1
#define R3 PORTCbits.RC2
#define R4 PORTCbits.RC3




void lcd_data(unsigned char data)
{
    PORTD = data;
    RS = 1;
    RW = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0; 
}
void lcd_cmd(unsigned char cmd)
{
    PORTD = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0; 
}
void lcd_string(unsigned char *str,unsigned char num)
{
    for(unsigned int i = 0; i <num ; i++)
    {
        lcd_data(str[i]);
    }
}
void lcd_init()
{
    lcd_cmd(0x38); // 5*7 matrix 8-bit mode 16*2
    lcd_cmd(0x06);   // string cursor Right movement
    lcd_cmd(0x0C);   // cursor off display ON
    lcd_cmd(0x01);   // display clear
}

void keypad(){
    C1 = 1; C2 = 0; C3 = 0;
    if (R1 ==1 ){ lcd_data('1');while (R1 ==1);  }
     if (R2 ==1 ){ lcd_data('4');while (R2 ==1);  }
     if (R3 ==1){ lcd_data('7');while (R3==1);  }
     if (R4 ==1 ){ lcd_data('*');while (R4 ==1);  }
     C1 = 0; C2 = 1; C3 = 0;
    if (R1 ==1){ lcd_data('2');while (R1 ==1);  }
     if (R2 ==1 ){ lcd_data('5');while (R2 ==1);  }
     if (R3 ==1 ){ lcd_data('8');while (R3 ==1);  }
     if (R4 ==1 ){ lcd_data('0');while (R4 ==1);  }
      C1 = 0; C2 = 0; C3 = 1;
    if (R1 ==1 ){ lcd_data('3');while (R1==1);  }
     if (R2 ==1 ){ lcd_data('6');while (R2 ==1);  }
     if (R3 ==1 ){ lcd_data('9');while (R3 ==1);  }
     if (R4 ==1 ){ lcd_data('#');while (R4==1);  }
}



void main(void) {
    TRISB = 0; // port B out put declaration 
    TRISD = 0;   // port D out put declaration 
    TRISC = 0xFF;  // C Prot 4 bits input
    
    lcd_init();
    lcd_cmd(0x80);    // print first row
   
    while (1)
    {
        keypad();
    }
    
    return;
}
