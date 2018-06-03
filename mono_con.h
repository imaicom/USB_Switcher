/* 
 * File:   mono_con.h
 * Author: user
 *
 * Created on 2016/11/29, 10:30
 */

#ifndef MONO_CON_H
#define	MONO_CON_H

#ifdef	__cplusplus
extern "C" {
#endif

// FullColorLED
#define FCLED       PORTB           // (PORTB & 0b11100000)
#define BLUE_FCLED  PORTBbits.RB7
#define GREEN_FCLED PORTBbits.RB6
#define RED_FCLED   PORTBbits.RB5

// DCMotor
#define DCM         PORTB           // (PORTB & 0b00011000)
#define IN1_DCM     PORTBbits.RB4
#define IN2_DCM     PORTBbits.RB3

// Ctrl SPM,7SegmentLED
#define CK_SPM      PORTBbits.RB2
#define SEL_7SEG10  PORTBbits.RB1
#define SEL_7SEG01  PORTBbits.RB0

// 7SegmentLED
#define DAT_7SEG    PORTC
#define DP_7SEG     PORTCbits.RC7
#define G_7SEG      PORTCbits.RC6
#define F_7SEG      PORTCbits.RC5
#define E_7SEG      PORTCbits.RC4
#define D_7SEG      PORTCbits.RC3
#define C_7SEG      PORTCbits.RC2
#define B_7SEG      PORTCbits.RC1
#define A_7SEG      PORTCbits.RC0

// SteppingMotor
#define PHASE_SPM   PORTC           // (PORTC & 0b11110000)
#define nB_SPM      PORTCbits.RC3
#define nA_SPM      PORTCbits.RC2
#define B_SPM       PORTCbits.RC1
#define A_SPM       PORTCbits.RC0

// Input Circuit
#define TGLSW       PORTAbits.RA0
#define TSW1        PORTAbits.RA1
#define TSW2        PORTAbits.RA2
#define PTINT       PORTAbits.RA3

// FullColorData
enum tgColor { OFF, RED, GREEN, YELLOW, BLUE, PURPLE, BLUEGREEN, WHITE };
//          0b 000, 001,   010,    011,  100,    101,       110,   111

// Global Variable
extern const unsigned char spmData[];
extern const unsigned char segData[];

// Prototype
void init(void);
void wait1ms(unsigned int n);

#ifdef	__cplusplus
}
#endif

#endif	/* MONO_CON_H */

