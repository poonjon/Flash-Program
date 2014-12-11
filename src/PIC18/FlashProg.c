#include "../18c.h"
#include "stdio.h"
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

void flashSetAddress(uint32 address){
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

void writeToBuffer(uint16 data){
  writeICSP(0xd, data);
}

void flashWriteAndProgram(uint16 data){
  int i;


  writeICSP(0xf, data);

  writeBits(0x0, 3);
  PGC_high();
  PGD_low();
  for(i = 0; i < 25 ; i++){} //p9 minimum 1ms
  PGC_low();
  for(i = 0; i < 25 ; i++){} //p10 minimum 100us
  writeBits(0x0, 16);

}

void flashWrite8Bits(uint8 data){
  int i;

  writeICSP(0xf, data);

  writeBits(0x0, 3);
  PGC_high();
  PGD_low();
  for(i = 0; i < 25 ; i++){} //p9 minimum 1ms
  PGC_low();
  for(i = 0; i < 25 ; i++){} //p10 minimum 100us
  writeBits(0x0, 16);

}

uint16 flashRead16Bits(){
    uint16 data;
    uint16 firstData;

    data = readICSP();
    firstData = readFirstByte();
    
    data = firstData|data;
    
    return data;
}

uint8 flashRead8Bits(){
    uint16 data;

    data = readICSP();
    
    return data;
}

//size in bits
void flashReadBlock(uint16 *data, uint16 size, uint32 blockNumber){
  int i;
  uint32 blockSelect;

  blockSelect = (blockNumber-1)*64;
  
  flashSetAddress(blockSelect);
  for(i = 0; i < size/2 ; i++){
    data[i] = flashRead16Bits();
  }
}

void flashWriteBlock(uint16 *firstHalf, uint16 *secondHalf, uint32 blockNumber){
  int i;
  uint32 blockSelect;

  blockSelect = (blockNumber-1)*64;
  
  flashSetAddress(blockSelect);
  for(i = 0 ; i < 15 ; i++){
    writeToBuffer(firstHalf[i]);
  }
  flashWriteAndProgram(firstHalf[15]);
  
  flashSetAddress(blockSelect+32);
  for(i = 0 ; i < 15 ; i++){
    writeToBuffer(secondHalf[i]);
  }
  flashWriteAndProgram(secondHalf[15]);
}

void flashWriteHalfBlock(uint16 *data, uint16 size, uint32 halfBlockNumber){
  int i;
  uint32 blockSelect;

  blockSelect = (halfBlockNumber-1)*32;
  flashSetAddress(blockSelect);

  for(i = 0 ; i < (size/2)-1 ; i++){
    
    writeToBuffer(data[i]);
    
  }

  flashWriteAndProgram(data[15]);
}

void rowErase(uint32 address){
  int i;
  writeICSP(0x0, 0x8ea6);
  writeICSP(0x0, 0x9ca6);
  writeICSP(0x0, 0x84a6);


  writeICSP(0x0, 0x6af8);
  writeICSP(0x0, 0x6af7);
  writeICSP(0x0, 0x6af6);
  flashSetAddress(address);

  writeICSP(0x0, 0x88a6);
  writeICSP(0x0, 0x82a6);
  writeBits(0x0, 3);
  PGC_high();
  PGD_low();
  for(i = 0; i < 25 ; i++){} //p9 minimum 1ms
  PGC_low();
  for(i = 0; i < 25 ; i++){} //p10 minimum 100us
  writeBits(0x0, 16);
}
