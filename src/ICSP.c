#include "ICSP.h"
#include <stdio.h>

void writeICSP(uint16 commandByte, uint16 dataBytes){
  writeBits(commandByte, COMMAND);
  writeBits(dataBytes, DATA);
}

void writeBit(uint16 bitToWrite){
  writePGD(bitToWrite);
  PGC_high();
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
  data = readBits(8);
  return data;
}

uint16 readBit(){
  uint16 data = 0;
  data = readPGD();
  PGC_high();
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