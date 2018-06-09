
// PIC16F1938 Configuration Bit Settings

#include <xc.h>

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// Internal OSC: 8MHz
#define _XTAL_FREQ 8000000      //  __delay_ms(), __delay_us()

void main(void)
{
     OSCCON     = 0b01110010 ; // ??????????????
     OPTION_REG = 0b00000000 ; // ????I/O???????????????
     ANSELA     = 0b00000000 ; // AN0-AN4????????????I/O???
     ANSELB     = 0b00000000 ; // AN8-AN13????????????I/O???
     TRISA      = 0b00000000 ; // ??(RA)??????????(0:?? 1:??)
     TRISB      = 0b00111111 ; // ??(RB)?RB0-5??????????????
     TRISC      = 0b00000000 ; // ??(RC)??????????
     WPUB       = 0b00111111 ; // RB0-5???????????????
     PORTA      = 0b00000000 ; // RA????????(??LOW???)
     PORTB      = 0b00000000 ; // RB????????(??LOW???)
     PORTC      = 0b00000000 ; // RC????????(??LOW???)

     int a;
    
 
     while(1) {
          if (RB0 == 0) {      // ???????????????????
               RC3 = 1 ;       // ??????HIGH?????(LED ??)
          } else {
               RC3 = 0 ;       // ??????LOW?????(LED ??)
          }
     }

    return;
}
