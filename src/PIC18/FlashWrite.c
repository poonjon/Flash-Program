#include "../18c.h"
#include "stdio.h"
#include "FlashWrite.h"
#include "FlashProg.h"

uint16 halfBuffer1[16];
uint16 halfBuffer2[16];
uint16 blockBuffer[32];

//size is in 2bytes of data
int flashWriteData(uint16 *data, uint16 size, uint32 address){
  int i, bytesWritten, startPoint;
  int j = 16;
  uint32 newAddress;
  uint16 newSize, memoryBlock;
  uint16 newData[size];
  
  memoryBlock = (address/64)+1; 
  
  flashReadBlock(blockBuffer, 64, memoryBlock);
  for(i = 0 ; i < 16 ; i++){
    halfBuffer1[i] = blockBuffer[i]; 
  }
  for(i = 0 ; i < 16 ; i++){
    halfBuffer2[i] = blockBuffer[j];
    j++;
  }
  
  startPoint = (address - ((address/64)*64))/2;
  bytesWritten = overwriteBufferData(data, size, startPoint);
  
  rowErase((address/64)*64);
  flashSetAddress((address/64)*64);
  flashWriteBlock(halfBuffer1, halfBuffer2, memoryBlock);
  
  if(bytesWritten < size){
    newAddress = (memoryBlock*64);
    newSize = size - bytesWritten;
    for(i = 0 ; i < newSize ; i++){
      newData[i] = data[bytesWritten];
      bytesWritten++;
    }
    flashWriteData(newData, newSize, newAddress);
  }
  
  return bytesWritten;
}

int overwriteBufferData(uint16 *data, uint16 sizeToWrite, uint16 bufferStartPoint){
  int bytesWritten, availableWriteSpace, bytesLeft, start;
  int i, j = 16;
  
  start = bufferStartPoint;
  for(i = 0 ; i < sizeToWrite ; i++){
    blockBuffer[start] = data[i];
    start++;
  }
  
  availableWriteSpace = 32 - bufferStartPoint;

  if(sizeToWrite > availableWriteSpace){
    bytesLeft = sizeToWrite - availableWriteSpace;
    bytesWritten = sizeToWrite - bytesLeft;
  }
  else
    bytesWritten = sizeToWrite; 
  
  for(i = 0 ; i < 16 ; i++){
    halfBuffer1[i] = blockBuffer[i];
  }
  for(i = 0 ; i < 16 ; i++){
    halfBuffer2[i] = blockBuffer[j];
    j++;
  }
  
  return bytesWritten;
  
}




