
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

#define MAX_DUTY    4       // Max:40%

// Main Function
void main(void)
{
    int tsw1Status, tsw2Status;
    int dcmStatus;
    int dcmDuty;
    int dcmCnt;

    // Initialize Clock,I/O
    init();

    // Init Data;
    tsw1Status = 0;
    tsw2Status = 0;
    dcmStatus = 0;
    dcmDuty = 1;
    dcmCnt = 0;

    // Main Loop
    while(1){

        // TactSW1
        if(TSW1 == 0){
            if(tsw1Status == 0){
                tsw1Status = 1;
                // Change DCMotor Status
                dcmStatus = (dcmStatus==0) ? 1 : 0;
            }
        }
        else{
            tsw1Status = 0;
        }

        // TactSW2
        if(TSW2 == 0){
            if(tsw2Status == 0){
                tsw2Status = 1;

                // Change Duty
                dcmDuty++;                  // Duty +10%
                if(dcmDuty > MAX_DUTY){     // Duty 10~40%
                    dcmDuty = 1;
                }
            }
        }
        else{
            tsw2Status = 0;
        }

        // DCMotor
        if(dcmStatus){
            // DCMotor Cycle Countup
            dcmCnt++;

            // DCMotor CycleTime: 10ms
            if(dcmCnt > 10){
                dcmCnt = 0;
            }

            if(dcmCnt <= dcmDuty){
                // DCMotor: CW
                IN1_DCM = 0;
                IN2_DCM = 1;
            }
            else{
                // DCMotor: Stop
                IN1_DCM = 0;
                IN2_DCM = 0;
            }
        }
        else{
            // DCMotor: Stop
            IN1_DCM = 0;
            IN2_DCM = 0;
        }

        // Loop CycleTime: 1ms
        __delay_ms(1);
    }

    return;
}
