#include "ICSP.h"
#include <stdio.h>
void writeICSP(unsigned int data, char number){
  int i;
  
  for(i = 0 ; i < number ; i++){
    
    if(((data>>(3-i))&0x1) == 1){
      PGD_high();
    }
    else if(((data>>(3-i))&0x1) == 0){
      PGD_low();
    }
      
    PGC_high();
    PGC_low();
  }
}

void readICSP(){

}