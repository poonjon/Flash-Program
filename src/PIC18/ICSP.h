#ifndef ICSP_H
#define ICSP_H
#include "Type.h"

//#define MSB(pattern, type, i) ((pattern>>((type - 1)-i))&0x1)
#define MSB(pattern, type, i) ((pattern>>i)&0x1)
#define COMMAND 4
#define DATA  16

void writeICSP(uint16 commandByte, uint16 dataBytes);
void writeBit(uint16 bitToWrite);
void writeBits(uint16 pattern, uint16 bitsToWrite);
uint16 readICSP(); ///
uint16 readBit();
uint16 readBits(int bitsToRead);
#endif // ICSP_H
