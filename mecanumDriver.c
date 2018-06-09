
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
    OSCCON     = 0b01110010 ; // 内部クロックは８ＭＨｚとする
    OPTION_REG = 0b00000000 ; // デジタルI/Oに内部プルアップ抵抗を使用する
    ANSELA     = 0b00000000 ; // AN0-AN4は使用しない全てデジタルI/Oとする
    ANSELB     = 0b00000000 ; // AN8-AN13は使用しない全てデジタルI/Oとする
    TRISA      = 0b00000000 ; // ピン(RA)は全て出力に割当てる(0:出力 1:入力)
    TRISB      = 0b00111111 ; // ピン(RB)はRB0-5のみ入力、他は全て出力に割当てる
    TRISC      = 0b00000000 ; // ピン(RC)は全て出力に割当てる
    WPUB       = 0b00111111 ; // RB0-5は内部プルアップ抵抗を指定する
     
    PORTA      = 0b00000000 ; // RA出力ピンの初期化(全てLOWにする)
    PORTB      = 0b00000000 ; // RB出力ピンの初期化(全てLOWにする)
    PORTC      = 0b00000000 ; // RC出力ピンの初期化(全てLOWにする)

     while(1) { // 左前　右前　左後　左後
        while(!RB0) PORTC = 0b10101010; // 前進　１０　１０　１０　１０
        while(!RB1) PORTC = 0b01010101; // 後進　０１　０１　０１　０１
        while(!RB2) PORTC = 0b10011001; // 右転　１０　０１　１０　０１
        while(!RB3) PORTC = 0b01100110; // 左転　０１　１０　０１　１０
        while(!RB4) PORTC = 0b10010110; // 右進　１０　０１　０１　１０
        while(!RB5) PORTC = 0b01101001; // 左進　０１　１０　１０　０１
        PORTC = 0;
    }
}
