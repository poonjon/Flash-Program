#include <stdio.h>
#include <stdlib.h>
#include "p18f4520.h"
#include "flash.h"

int readPGD(){
  return _PGD;
}

void writePGD(int bit){
  _PGD = bit;
}

void PGD_high(){
  writePGD(1);
}

void PGD_low(){
  writePGD(0);
}

void PGC_high(){
  PGC = 1;
}

void PGC_low(){
  PGC = 0;
}

void MCLR_low(){
  MCLR = 0;
  writePGD(0);
  PGC = 0;
}

void MCLR_high(){
  MCLR = 1;
}

void enter_LVP(){
  MCLR_low();
  //delay for >2us
  MCLR_high();
  //delay >2us
}

void exit_LVP(){
  MCLR_high();
  //delay >0s
  MCLR_low();
  //delay >0s
}