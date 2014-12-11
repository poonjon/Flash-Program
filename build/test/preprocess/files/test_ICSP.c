#include "unity.h"
#include "p18f4520.h"
#include "mock_FlashProg.h"
#include "Type.h"
#include "ICSP.h"


void setUp(void){}

void tearDown(void){}



void mockBitsWriting(uint16 pattern, uint16 bitsToWrite){

  int i = 0;

  while(i < bitsToWrite){



    PGC_high_CMockExpect(14);

    writePGD_CMockExpect(15, ((pattern>>i)&0x1));

    PGC_low_CMockExpect(16);

    i++;

  }

}



void mockBitsReading(uint16 pattern, uint16 bitsToRead){

  int i=0;

  while(i < bitsToRead){



    PGC_high_CMockExpect(25);

    readPGD_CMockExpectAndReturn(26, ((pattern>>i)&0x1));



    PGC_low_CMockExpect(28);

    i++;

  }



}



void test_write_bit_1(){

  PGC_high_CMockExpect(35);

  writePGD_CMockExpect(36, 1);

  PGC_low_CMockExpect(37);



  writeBit(1);

}



void test_write_bit_0(){

  PGC_high_CMockExpect(43);

  writePGD_CMockExpect(44, 0);

  PGC_low_CMockExpect(45);



  writeBit(0);

}



void test_write_bits_0x50(){

  mockBitsWriting(0x50, 8);

  writeBits(0x50, 8);

}



void test_write_bits_0xf9(){

  mockBitsWriting(0xf9, 8);

  writeBits(0xf9, 8);

}



void test_write_bits_0x3c40(){

  mockBitsWriting(0x5df9, 16);

  writeBits(0x5df9, 16);

}



void test_writeICSP_write_0xd_command_0x3c40_data(){

  mockBitsWriting(0xd, 4);

  mockBitsWriting(0x3c40, 16);



  writeICSP(0xd, 0x3c40);



}



void test_readBit_should_return_1(){

  PGC_high_CMockExpect(74);

  readPGD_CMockExpectAndReturn(75, 1);

  PGC_low_CMockExpect(76);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((readBit())), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);



}



void test_readBit_should_return_0(){

  PGC_high_CMockExpect(83);

  readPGD_CMockExpectAndReturn(84, 0);

  PGC_low_CMockExpect(85);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((readBit())), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);



}



void test_readBits_should_return_0x11(){

  mockBitsReading(0x11, 8);

  UnityAssertEqualNumber((_U_SINT)((0x11)), (_U_SINT)((readBits(8))), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);



}



void test_readBits_should_return_0xf6(){



  mockBitsReading(0xf6, 8);

  UnityAssertEqualNumber((_U_SINT)((0xf6)), (_U_SINT)((readBits(8))), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);



}



void test_readBits_should_return_0x35f6(){



  mockBitsReading(0x35f6, 16);

  UnityAssertEqualNumber((_U_SINT)((0x35f6)), (_U_SINT)((readBits(16))), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);



}



void test_readICSP_should_read_0x34(){

  mockBitsWriting(0x9, 4);

  mockBitsWriting(0x0, 8);

  mockBitsReading(0x34, 8);



  UnityAssertEqualNumber((_U_SINT)((0x34)), (_U_SINT)((readICSP(0x34))), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);



}
