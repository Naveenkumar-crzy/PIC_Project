/*
 * File:   main.c
 * Author: crazy
 *
 * Created on 22 March, 2025, 9:31 PM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000
#define RS PORTBbits.RB0 
#define RW PORTBbits.RB1
#define EN PORTBbits.RB2 
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

void main(void) {
    TRISB = 0; // port B out put declaration 
    TRISD = 0;   // port D out put declaration 

    char con[]= "HIII";
    lcd_init();
    lcd_cmd(0x80);    // print first row
   
    lcd_string(con,4);  // con data passing in function
    
    while (1)
    {
        
    }
    
    return;
}
