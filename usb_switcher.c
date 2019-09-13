// PICKIT3 Setting
//
// Program Options
//   Erase All Before Program [*]
//   Program Speed [3]
//   Enable Low Voltage Programming [ ]
//   Programming Method [Apply Vdd before Vpp]->[Apply Vpp before Vdd(Recommended)]->[Apply Vdd before Vpp]
//
// Power
//   Power target circuit from PICkit3 [*]
//   Voltage Level [4.875]or[5.000]
//
// USB port cut and plug... RESET

// Pin Layout

// /MCLR  1    28 RB7
// RA0    2    27 RB6
// RA1    3    26 RB5
// RA2    4    25 RB4
// RA3    5    24 RB3
// RA4    6    23 RB2
// RA5    7    22 RB1
// Vss    8    21 RB0
// RA7    9    20 Vdd
// RA6   10    19 Vss
// RC0   11    18 RC7
// RC1   12    17 RC6
// RC2   13    16 RC5
// RC3   14    15 RC4

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

static void Delay_ms(unsigned int DELAY_CNT) {
    for (unsigned int i = 0; i < DELAY_CNT; i++) {
        __delay_ms(1);
    }
}

void main(void)
{
    
    int i = 0;
    int t = 0;
    OSCCON     = 0b01110010 ; // Set the internal clock to 8 MHz
    OPTION_REG = 0b00000000 ; // Use internal pull-up resistor for digital I / O
    ANSELA     = 0b00000000 ; // AN0 to AN4 are not used. Make it all digital I / O
    ANSELB     = 0b00000000 ; // AN8 to AN13 are not used. Make it all digital I / O
    TRISA      = 0b00000000 ; // All pins (RA) are assigned to outputs (0: output 1: input)
    TRISB      = 0b10000000 ; // Pin (RB) inputs only RB7, all others assign output
    TRISC      = 0b00000000 ; // All pins (RC) are assigned to outputs
    WPUB       = 0b10000000 ; // RB7 designates an internal pull-up resistor
     
    PORTA      = 0b00000001 ; // LED (It is good without it. However, only if the relay has a light)
    PORTB      = 0b00000000 ;
    PORTC      = 0b00000001 ; // RELAY

     while(1) {
         
        while(!RB7) { 
            while(!RB7) Delay_ms(10);
//            Delay_ms(5); RB6 = 1;Delay_ms(5); RB6 = 0;
//            RB6=1;Delay_ms(5);RB6=0;Delay_ms(5);
//            i++; if(i>=4) i = 0;
            i++; if(i>=8) i = 0;
            t = 1;
            
            if(i==0) PORTA = 0b00000001;
            if(i==1) PORTA = 0b00000010;
            if(i==2) PORTA = 0b00000100;
            if(i==3) PORTA = 0b00001000;
            if(i==4) PORTA = 0b00010000;
            if(i==5) PORTA = 0b00100000;
            if(i==6) PORTA = 0b01000000;
            if(i==7) PORTA = 0b10000000;
        }; // while(!RB7)    
        
        if(t>=1) {Delay_ms(10); t++; PORTC = 0b00000000;};
        
        if(t>=100) { // after 1sec (10ms x 100 times)
            t = 0;
            if(i==0) PORTC = 0b00000001;
            if(i==1) PORTC = 0b00000010;
            if(i==2) PORTC = 0b00000100;
            if(i==3) PORTC = 0b00001000;
            if(i==4) PORTC = 0b00010000;
            if(i==5) PORTC = 0b00100000;
            if(i==6) PORTC = 0b01000000;
            if(i==7) PORTC = 0b10000000;
        }; // if(t>=100)
        
    }; // while(1)
    
} // main
