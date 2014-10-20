#ifndef flash_H
#define flash_H

#define PIN_LOW 0
#define PIN_HIGH 1

#define PGD PORTCbits.RC4 
#define PGC PORTCbits.RC3
#define MCLR PORTEbits.RE3

void PGD_high();
void PGD_low();
void PGC_high();
void PGC_low();
void MCLR_low();
void MCLR_high();
void enter_LVP();
void exit_LVP();
#endif // flash_H
