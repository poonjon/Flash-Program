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
  uint16 data0 = 0x0000;
  uint16 data1 = 0x1000;
  uint16 data2 = 0x2000;
  uint16 data3 = 0x3000;
  uint16 data4 = 0x1000;
  uint16 data5 = 0x5000;
  uint32 address = 0x000000;
  uint16 blockRead[32];
  uint16 blockWrite0[16];
  uint16 blockWrite1[16];
  uint16 blockWrite2[16];
  uint16 blockWrite3[16];
  uint16 blockWrite5[64];
  uint16 incomingData[4];

  for(i = 0 ; i < 16 ; i++){
      blockWrite0[i] = data0;
      data0++;
  }
  for(i = 0 ; i < 16 ; i++){
      blockWrite1[i] = data1;
      data1++;
  }

  for(i = 0 ; i < 16 ; i++){
      blockWrite2[i] = data2;
      data2++;
  }
  for(i = 0 ; i < 16 ; i++){
      blockWrite3[i] = data3;
      data3++;
  }
  for(i = 0 ; i < 64 ; i++){
      blockWrite5[i] = data5;
      data5++;
  }

  trisInit();
  enter_HVP();
  
  bulkErase();
  enableWrite();
 
  flashWriteBlock(blockWrite0, blockWrite1, 1);
  flashWriteBlock(blockWrite2, blockWrite3, 2);
  flashReadBlock(blockRead, 64, 1);
  flashReadBlock(blockRead, 64, 2);
  flashWriteData(blockWrite5, 64, 0);
  flashReadBlock(blockRead, 64, 1);
  flashReadBlock(blockRead, 64, 2);
  exit_HVP();

  while(1){}
}
