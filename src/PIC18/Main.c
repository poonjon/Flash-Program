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

  trisInit();

  enter_HVP();


  readDeviceID1();
  exit_HVP();

  while(1){
  
  }
}

