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

  writePGD(0);
  _PGC = 0;
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
  int i = 0;
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
  writeBits(0, 4);
  for(i = 0; i < 200 ; i++){}
  writeBits(0, 16);
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

void enableWrite(){
  writeICSP(0x0, 0x8ea6);
  writeICSP(0x0, 0x9ca6);
}

void tableSelect(uint32 address){
  uint32 upperAddr;
  uint32 highAddr;
  uint32 lowAddr;
  
  lowAddr = (address&0x0000ff);
  highAddr = ((address>>8)&0x0000ff);
  upperAddr = ((address>>16)&0x0000ff);

  writeICSP(0x0, 0x0e00|upperAddr);
  writeICSP(0x0, 0x6ef8);
  writeICSP(0x0, 0x0e00|highAddr);
  writeICSP(0x0, 0x6ef7);
  writeICSP(0x0, 0x0e00|lowAddr);
  writeICSP(0x0, 0x6ef6);
}

void writeTableThenIncremeant(uint16 first2Byte, uint16 second2Byte){
  int i;

  writeICSP(0xd, first2Byte);
  writeICSP(0xe, second2Byte);

  writeBits(0x0, 3);
  PGC_high();
  PGD_low();
  for(i = 0; i < 25 ; i++){} //p9 minimum 1ms
  PGC_low();
  for(i = 0; i < 25 ; i++){} //p10 minimum 100us
  writeBits(0x0, 16);

}

uint16 read2Byte(){
    uint16 data;
    uint16 firstData;

    data = readICSP();
    firstData = readFirstByte();
    
    data = firstData|data;
    
    return data;
}