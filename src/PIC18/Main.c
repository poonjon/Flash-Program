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


void main(){
    TRISD = 0;
    PGC_low();
    _PGD = 0;
    enter_LVP();
readDeviceID();
exit_LVP();
    while(1){
            
    }
}

