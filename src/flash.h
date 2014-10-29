#ifndef flash_H
#define flash_H
#include "Type.h"

#define _PGD PORTCbits.RC4
#if defined PIC1C8 || X8
  #define readPGD() (_PGD)
  #define writePGD(x) (_PGD = x)
#else
  int readPGD();
  void writePGD(int bit);
#endif

#define PIN_LOW 0
#define PIN_HIGH 1
#define PGC PORTCbits.RC3
#define MCLR PORTEbits.RE3

int readPGD();
void writePGD(int bit);
void PGD_high();
void PGD_low();
void PGD_low();
void PGC_high();
void PGC_low();
void MCLR_low();
void MCLR_high();
void enter_LVP();
void exit_LVP();
void bulkErase();
#endif // flash_H
