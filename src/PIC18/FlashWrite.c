#include "../18c.h"
#include "stdio.h"
#include "FlashWrite.h"
#include "FlashProg.h"

uint16 halfBuffer1[16];
uint16 halfBuffer2[16];
uint16 blockBuffer[32];

//size is in 2bytes of data
int flashWriteData(uint16 *data, uint16 size, uint32 address){
  int i, k, bytesWritten = 0, timesToWrite = 1, nextDataSet = 0;
  int j = 16;
  uint32 newAddress = address;
  uint16 newSize = size;
  uint16 memoryBlock, currentStartPoint = 0;
  uint16 newData[32], availableWriteSpace;
  
  // currentStartPoint = (address - ((address/64)*64))/2; //to determine the current start point in the array
  //availableWriteSpace = currentStartPoint - (address/2); //to determine how many address can be written until the next block
  currentStartPoint = newStartPoint(address);
  if((size+currentStartPoint) > 32){
    i = (size+currentStartPoint) - 32;
    timesToWrite++;
    while(i > 32){
      i = i - 32;
      timesToWrite++;
    }
  }
  
  for(i = 0 ; i < timesToWrite ; i++){

    for(k = 0 ; k < 32 ; k++){ //fill data with incoming data
      newData[k] = data[nextDataSet];
      nextDataSet++;
    }
   
    memoryBlock = blockSelect(newAddress); //first block to be written on
    flashReadBlock(blockBuffer, 64, memoryBlock); 
    loadHalfBuffer();
    bytesWritten = bytesWritten + (overwriteBufferData(newData, newSize, currentStartPoint));

    rowErase((newAddress/64)*64);
    flashSetAddress((newAddress/64)*64);
    flashWriteBlock(halfBuffer1, halfBuffer2, memoryBlock);
    
    if(bytesWritten < size){ //replace old values with a new set of values that should be written on the next block
      nextDataSet = bytesWritten;
      newAddress = (memoryBlock*64);
      newSize = size - bytesWritten;
      currentStartPoint = newStartPoint(newAddress);
    }
  }
  return bytesWritten;
}

int overwriteBufferData(uint16 *data, uint16 sizeToWrite, uint16 bufferStartPoint){
  uint16 bytesWritten, availableWriteSpace = 0, bytesLeft, start;
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
  
  loadHalfBuffer();
  
  return bytesWritten;
  
}

void loadHalfBuffer(){
  int i, j = 16;
  
  for(i = 0 ; i < 16 ; i++){
    halfBuffer1[i] = blockBuffer[i]; 
  }
  for(i = 0 ; i < 16 ; i++){
    halfBuffer2[i] = blockBuffer[j];
    j++;
  }

}


