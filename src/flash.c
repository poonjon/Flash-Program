#include <stdio.h>
#include <stdlib.h>
#include "p18f4520.h"
#include "flash.h"

void start_i2c(){
    SCL_TRIS = 0; //clock output
    SDA_TRIS = 1; //SDA high
    SCL = 1;      //clock high
    SDA_TRIS = 0; //SDA output
    SDA = 0;      //data 0
//   _delay(15);   //delay 3 instruction cycles
    SCL = 0;      //clock low
}

void stop_i2c(){
    SCL = 0;      //clock low
    SDA_TRIS = 0; //SDA output
    SDA = 0;      //data 0
//    _delay(1);   //delay 3 instruction cycles
    SCL = 1;      //clock high
    SDA = 1;      //data 1
    SCL = 0;      //clock low
}

//output bit to i2c
void bit_out(unsigned char data){
    SCL = 0;         //clock low
    SDA_TRIS = 0;    //SDA output
    SCL = 1;         //clock high
    SDA = (data&0x01); //data LSB (causes long delay)
//    _delay(1);      //delay 1 instruction cycles, 10us
    SCL = 0;         //clock low
//   _delay(1);      //delay 1 instruction cycles 10us
    
    
}

//input bit from i2c
void bit_in(unsigned char *data){
    SCL = 0;      //clock low
    SDA_TRIS = 1; //SDA input
    SCL = 1;      //clock high
//    _delay3(1);   //delay 3 instruction cycle
    *data |= SDA; //OR old data with new data
    SCL = 0;      //clock low
}

unsigned char write_command(unsigned char data){
    int i;
    for(i = 0 ; i < 4 ; i++){ //wirte 4 bits of data for command
        data = (data>>i);
        bit_out(data);
        
    }
}

