
// PIC16F1938 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

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

#include "mono_con.h"

// Internal OSC: 8MHz
#define _XTAL_FREQ 8000000      //  __delay_ms(), __delay_us()

// Main Function
void main(void)
{
    // Initialize Clock,I/O
    init();

    // Main Loop
    while(1){
        if(TGLSW == 0){             // ToggleSW: ON
            if(TSW1 == 0){              // TactSW1: ON
                FCLED = BLUE<<5;        // FCLED: BLUE
            }
            else if(TSW2 == 0){         // TactSW2: ON
                FCLED = GREEN<<5;       // FCLED: GREEN
            }
            else if(PTINT == 1){        // PhotoInterrupter: OFF
                FCLED = BLUEGREEN<<5;   // FCLED: BLUEGREEN
            }
            else{                       // TSW1,TSW2: OFF,PhotoInterrupter: ON
                FCLED = RED<<5;         // FCLED: RED
            }
        }
        else{                       // ToggleSW: OFF
            if(TSW1 == 0){              // TactSW1: ON
                FCLED = PURPLE<<5;      // FCLED: PURPLE
            }
            else if(TSW2 == 0){         // TactSW2: ON
                FCLED = YELLOW<<5;      // FCLED: YELLOW
            }
            else if(PTINT == 1){        // PhotoInterrupter: OFF
                FCLED = WHITE<<5;       // FCLED: WHITE
            }
            else{                       // TSW1,TSW2: OFF,PhotoInterrupter: ON
                FCLED = OFF<<5;         // FCLED: OFF
            }
        }
    }

    return;
}
