#include "ICSP.h"
#include <stdio.h>
void writeICSP(unsigned int data, char number){
  int i, MSB;
  
  for(i = 0 ; i < number ; i++){
    MSB = ((data>>((number - 1)-i))&0x1);
    if(MSB == 1){
      PGD_high();
    }
    else if(MSB == 0){
      PGD_low();
    }
      
    PGC_high();
    PGC_low();
  }
}

void readICSP(){

}