#ifndef FlashWrite_H
#define FlashWrite_H
#include "Type.h"

extern uint16 halfBuffer1[16];
extern uint16 halfBuffer2[16];
extern uint16 blockBuffer[32];

int flashWriteData(uint16 *data, uint16 size, uint32 address);
int overwriteBufferData(uint16 *data, uint16 sizeToWrite, uint16 bufferStartPoint);

#endif // FlashWrite_H
