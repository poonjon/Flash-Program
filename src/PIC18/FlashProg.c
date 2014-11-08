#include "../18c.h"
#include "FlashProg.h"
#include "ICSP.h"


uint16 readPGD(){
  return _PGD;
}

void writePGD(int data){
  _PGD = data;
}

void PGD_high(){
  writePGD(1);
}

void PGD_low(){
  writePGD(0);
}

void PGC_high(){
  _PGC = 1;
}

void PGC_low(){
  _PGC = 0;
}

void PGM_low(){
  _PGM = 0;
}

void PGM_high(){
  _PGM = 1;
}

void MCLR_low(){
  _MCLR = 0;
}

void MCLR_high(){
  _MCLR = 1;
}

void enter_HVP(){
  MCLR_low();
  PGC_low();
  PGD_low();
  PGM_high();
  MCLR_high();
}

void exit_HVP(){
  PGC_low();
  PGD_low();
  PGM_low();
  MCLR_low();
}

void bulkErase(){
  writeICSP(0x0, 0x0e3c);
  writeICSP(0x0, 0x6ef8);
  writeICSP(0x0, 0x0e00);
  writeICSP(0x0, 0x6ef7);
  writeICSP(0x0, 0x0e05);
  writeICSP(0x0, 0x6ef6);
  writeICSP(0xc, 0x3f3f);
  writeICSP(0x0, 0x0e3c);
  writeICSP(0x0, 0x6ef8);
  writeICSP(0x0, 0x0e00);
  writeICSP(0x0, 0x6ef7);
  writeICSP(0x0, 0x0e04);
  writeICSP(0x0, 0x6ef6);
  writeICSP(0xc, 0x8f8f);
  writeICSP(0x0, 0);
  writeICSP(0x0, 0);

}

void readDeviceID1(){
  uint16 value = 0;
  writeICSP(0x0, 0x0e3f);
  writeICSP(0x0, 0x6ef8);
  writeICSP(0x0, 0x0eff);
  writeICSP(0x0, 0x6ef7);
  writeICSP(0x0, 0x0eff);
  writeICSP(0x0, 0x6ef6);
  value = readICSP();
  value = value;
}

void readDeviceID2(){
  uint16 value = 0;
  writeICSP(0x0, 0x0e3f);
  writeICSP(0x0, 0x6ef8);
  writeICSP(0x0, 0x0eff);
  writeICSP(0x0, 0x6ef7);
  writeICSP(0x0, 0x0efe);
  writeICSP(0x0, 0x6ef6);
  value = readICSP();
  value = value;
}