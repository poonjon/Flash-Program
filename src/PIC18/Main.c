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
  trisInit();

  enter_HVP();
  
  bulkErase();
  tableSelect(0x001232);
  enableWrite();
  writeTableThenIncremeant(0x25d6, 0x58a6);
  writeTableThenIncremeant(0x2fdf, 0x58ff);
  tableSelect(0x001232);
  a = read2Byte();
  b = read2Byte();
  c = read2Byte();
  d = read2Byte();
  
  i = i;
  exit_HVP();

  while(1){

  }
}

