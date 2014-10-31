#include "../18c.h"
#include "FlashProg.h"
#include "ICSP.h"

void writeICSP(uint16 commandByte, uint16 dataBytes){
  writeBits(commandByte, COMMAND);
  writeBits(dataBytes, DATA);
}

void writeBit(uint16 bitToWrite){
  PGC_high();
  writePGD(bitToWrite);
  PGC_low();
}

void writeBits(uint16 pattern, uint16 bitsToWrite){
  int i=0;
  while(i < bitsToWrite){
    writeBit(MSB(pattern, bitsToWrite, i));
    i++;
  }
}

uint16 readICSP(){
  uint16 data = 0;
  writeBits(9, 4);
  writeBits(0, 8);
  setICSPDataPinAsInput;
  data = readBits(8);
  setICSPDataPinAsOutput;
  return data;
}

uint16 readBit(){
  uint16 data=0;
  PGC_high();
  data = readPGD();
  PGC_low();
  return data;
}

uint16 readBits(int bitsToRead){
  int i=0;
  uint16 data=0;
  
  while(i < bitsToRead){
    data = (data<<1)|readBit();
    i++;
  }
  return data;
}