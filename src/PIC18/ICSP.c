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
  setICSPDataPinAsOutput;
  while(i < bitsToWrite){
    writeBit(LSB(pattern, bitsToWrite, i));
    i++;
  }
}

uint16 readICSP(){
  uint16 data;
  writeBits(9, 4);
  writeBits(0, 8);
  data = readBits(8);

  return data;
}

uint16 readFirstByte(){
  uint16 data;
  writeBits(9, 4);
  writeBits(0, 8);
  data = readBits(8);
  data = data<<8;
  return data;

}

uint16 readBit(){
  uint16 data;
  PGC_high();
  data = readPGD();
  PGC_low();
  return data;
}

uint16 readBits(int bitsToRead){
  int i=0;
  uint16 data = 0;

  setICSPDataPinAsInput;

  while(i < bitsToRead){
    data = (readBit()<< i)|data;
    i++;
  }
  return data;
}