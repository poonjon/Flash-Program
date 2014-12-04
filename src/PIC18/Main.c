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
  uint16 i = 0;
  uint16 a = 0;
  uint16 b = 0;
  uint16 c = 0;
  uint16 d = 0;
  uint16 e = 0;
  uint16 data = 0x0000;
  uint32 address = 0x000000;
  trisInit();

  enter_HVP();
  
  bulkErase();
  enableWrite();
  
  flashSetAddress(0x000000);
  for(i = 0 ; i < 15 ; i++){
    flashWriteData(data);
    data++;
  }
  flashWriteAndProgram(data);
  data++;
  //rowErase(0x000000);
  flashSetAddress(0x000032);
  for(i = 0 ; i < 14 ; i++){
    flashWriteData(data);
    data++;
  }
  flashWriteAndProgram(data);


  flashSetAddress(0x000000);
  for(i = 0 ; i < 16 ; i++){
    a = flashRead16Bits();
    b = flashRead16Bits();
    c = flashRead16Bits();
    d = flashRead16Bits();
    e = flashRead16Bits();

  }
  flashSetAddress(address);
  writeICSP(0x0, 0x84a6);
  writeICSP(0x0, 0x88a6);
  writeICSP(0x0, 0x82a6);
  writeBits(0x0, 3);
  PGC_high();
  PGD_low();
  for(i = 0; i < 25 ; i++){} //p9 minimum 1ms
  PGC_low();
  for(i = 0; i < 25 ; i++){} //p10 minimum 100us
  writeBits(0x0, 16);
  flashSetAddress(address);
  for(i = 0 ; i <15 ; i++){
    flashWriteData(0x6666);
  }
  flashWriteAndProgram(0x8778);
  writeBits(0x0, 3);
  PGC_high();
  PGD_low();
  for(i = 0; i < 25 ; i++){} //p9 minimum 1ms
  PGC_low();
  for(i = 0; i < 25 ; i++){} //p10 minimum 100us
  writeICSP(0x0, 0x94a6);

  flashSetAddress(0x000000);
  for(i = 0 ; i < 17 ; i++){
    a = flashRead16Bits();
  }

  i = i;

  exit_HVP();

  while(1){}
}

/*  flashSetAddress(address);
  flashWriteData(0x2934);
  flashWriteAndProgram(0x8a95);

  flashSetAddress(0x000038);
  for(i = 0 ; i < 17 ; i++){
    a = flashRead16Bits();
  }

  rowErase(0x000000);
*/