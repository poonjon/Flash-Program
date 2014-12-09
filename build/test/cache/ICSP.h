#include "Type.h"














void writeICSP(uint16 commandByte, uint16 dataBytes);

void writeBit(uint16 bitToWrite);

void writeBits(uint16 pattern, uint16 bitsToWrite);

uint16 readICSP();

uint16 readFirstByte();

uint16 readBit();

uint16 readBits(int bitsToRead);
