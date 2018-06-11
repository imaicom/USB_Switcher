
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
    OSCCON     = 0b01110010 ; // Set the internal clock to 8 MHz
    OPTION_REG = 0b00000000 ; // Use internal pull-up resistor for digital I / O
    ANSELA     = 0b00000000 ; // AN0 to AN4 are not used. Make it all digital I / O
    ANSELB     = 0b00000000 ; // AN8 to AN13 are not used. Make it all digital I / O
    TRISA      = 0b00000000 ; // All pins (RA) are assigned to outputs (0: output 1: input)
    TRISB      = 0b00111111 ; // Pin (RB) inputs only RB 0 - 5, all others assign output
    TRISC      = 0b00000000 ; // All pins (RC) are assigned to outputs
    WPUB       = 0b00111111 ; // RB0-5 designates an internal pull-up resistor
     
    PORTA      = 0b00000000 ; // Initialization of RA output pin (all set to LOW)
    PORTB      = 0b00000000 ; // Initialization of RB output pin (all set to LOW)
    PORTC      = 0b00000000 ; // Initialization of RC output pin (all set to LOW)

     while(1) { // LeftFront RightFront LeftRear RightRear
        while(!RB0) PORTA = 0b10101010; // Forward    10 10 10 10
        while(!RB1) PORTA = 0b01010101; // Back       01 01 01 01
        while(!RB2) PORTA = 0b10011001; // Right Turn 10 01 10 01
        while(!RB3) PORTA = 0b01100110; // Left Turn  01 10 01 10
        while(!RB4) PORTA = 0b10010110; // Right      10 01 01 10
        while(!RB5) PORTA = 0b01101001; // Left       01 10 10 01
        PORTA = 0;
    }
}
