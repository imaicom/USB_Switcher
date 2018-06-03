#include <xc.h>
#include "mono_con.h"

// SPMotor OutData
const unsigned char spmData[] = {
    0b00000001,     // Aphase
    0b00000010,     // Bphase
    0b00000100,     // nAphase
    0b00001000      // nBphase
};

// Segment Data
const unsigned char segData[] = {
    0b00111111,     // 0
    0b00000110,     // 1
    0b01011011,     // 2
    0b01001111,     // 3
    0b01100110,     // 4
    0b01101101,     // 5
    0b01111101,     // 6
    0b00100111,     // 7
    0b01111111,     // 8
    0b01101111,     // 9
    0b01110111,     // A
    0b01111100,     // b
    0b00111001,     // C
    0b01011110,     // d
    0b01111001,     // E
    0b01110001,     // F
};

// Initialize Clock,I/O Function
void init(void)
{
    // Internal RC Oscillator Frequency
    OSCCON = 0b01110010;    // Internal Oscilletor: 8MHz

    // I/O Setting
    PORTA = 0b00000000;         // PORTA: Clear
    PORTB = 0b00000000;         // PORTB: Clear
    PORTC = 0b00000000;
    TRISA = 0b00001111;         // TRISA: SW
    TRISB = 0b00000000;         // TRISB: LED, DCMotor, 7SegSel
    TRISC = 0b00000000;         // TRISC: SPMotor, 7SegDat
    ANSELA = 0b00000000;        // RA: Digital I/O
    ANSELB = 0b00000000;        // RB: Digital I/O
}

// Internal OSC: 8MHz
#define _XTAL_FREQ 8000000      //  __delay_ms(), __delay_us()

// Software Timer 1ms
void wait1ms(unsigned int n)
{
    int i;

    for(i=0; i<n; i++){
        __delay_ms(1);
    }
}
