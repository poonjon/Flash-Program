#ifndef ICSP_H
#define ICSP_H
#include "Type.h"

#define LSB(pattern, type, i) ((pattern>>i)&0x1)
#define COMMAND 4
#define DATA  16

void writeICSP(uint16 commandByte, uint16 dataBytes);
void writeBit(uint16 bitToWrite);
void writeBits(uint16 pattern, uint16 bitsToWrite);
uint16 readICSP();
uint16 readFirstByte();
uint16 readBit();
uint16 readBits(int bitsToRead);
#endif // ICSP_H
