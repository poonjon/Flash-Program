/* 
 * File:   main.c
 * Author: D300-01
 *
 * Created on October 31, 2014, 9:51 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../18c.h"
#include "FlashProg.h"
#include "FlashWrite.h"
#include "ICSP.h"

/*
 * 
 */

#pragma config OSC = INTIO67, PWRT = ON, WDT = OFF, LVP = OFF, DEBUG = ON


void trisInit(){
  TRISDbits.TRISD4 = 0;
  TRISDbits.TRISD5 = 0;
  TRISDbits.TRISD6 = 0;
  TRISDbits.TRISD7 = 0;
}

void main(){
  int i;
  uint16 data = 0x0000;
  uint16 newData = 0x1000;
  uint16 newData2 = 0x1000;
  uint16 newData3 = 0x1000;
  uint16 newData4 = 0x1000;
  uint16 newData5 = 0x5000;
  uint32 address = 0x000000;
  uint16 blockRead[32];
  uint16 blockWrite[16];
  uint16 blockWrite2[16];
  uint16 blockWrite3[16];
  uint16 blockWrite4[16];
  uint16 blockWrite5[32];
  uint16 incomingData[4];

  for(i = 0 ; i < 16 ; i++){
      blockWrite[i] = data;
      data++;
  }
  for(i = 0 ; i < 16 ; i++){
      blockWrite2[i] = newData;
      newData++;
  }

  for(i = 0 ; i < 16 ; i++){
      blockWrite3[i] = newData2;
      newData2++;
  }
  for(i = 0 ; i < 16 ; i++){
      blockWrite4[i] = newData3;
      newData3++;
  }
  for(i = 0 ; i < 32 ; i++){
      blockWrite5[i] = newData4;
      newData4++;
  }

  trisInit();
  enter_HVP();
  
  bulkErase();
  enableWrite();
  flashWriteBlock(blockWrite, blockWrite2, 1);
  flashWriteBlock(blockWrite3, blockWrite4, 2);

  flashWriteData(blockWrite5, 62, 0);
  flashReadBlock(blockRead, 62, 0);
  exit_HVP();

  while(1){}
}
