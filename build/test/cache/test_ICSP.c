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



    printf("%d", ((pattern>>i)&0x1));

    PGC_high_CMockExpect(15);

    writePGD_CMockExpect(16, ((pattern>>i)&0x1));

    PGC_low_CMockExpect(17);

    i++;

  }

}



void mockBitsReading(uint16 pattern, uint16 bitsToRead){

  int i=0;

  while(i < bitsToRead){



    printf("%d", ((pattern>>i)&0x1));

    PGC_high_CMockExpect(27);

    readPGD_CMockExpectAndReturn(28, ((pattern>>i)&0x1));



    PGC_low_CMockExpect(30);

    i++;

  }



}



void test_write_bit_1(){

  PGC_high_CMockExpect(37);

  writePGD_CMockExpect(38, 1);

  PGC_low_CMockExpect(39);



  writeBit(1);

}



void test_write_bit_0(){

  PGC_high_CMockExpect(45);

  writePGD_CMockExpect(46, 0);

  PGC_low_CMockExpect(47);



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

  PGC_high_CMockExpect(76);

  readPGD_CMockExpectAndReturn(77, 1);

  PGC_low_CMockExpect(78);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((readBit())), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);



}



void test_readBit_should_return_0(){

  PGC_high_CMockExpect(85);

  readPGD_CMockExpectAndReturn(86, 0);

  PGC_low_CMockExpect(87);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((readBit())), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);



}



void test_readBits_should_return_0x11(){

  mockBitsReading(0x11, 8);

  UnityAssertEqualNumber((_U_SINT)((0x11)), (_U_SINT)((readBits(8))), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);



}



void test_readBits_should_return_0xf6(){



  mockBitsReading(0xf6, 8);

  UnityAssertEqualNumber((_U_SINT)((0xf6)), (_U_SINT)((readBits(8))), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);



}



void test_readBits_should_return_0x35f6(){



  mockBitsReading(0x35f6, 16);

  UnityAssertEqualNumber((_U_SINT)((0x35f6)), (_U_SINT)((readBits(16))), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);



}



void test_readICSP_should_read_0x34(){

  mockBitsWriting(0x9, 4);

  mockBitsWriting(0x0, 8);

  mockBitsReading(0x34, 8);



  UnityAssertEqualNumber((_U_SINT)((0x34)), (_U_SINT)((readICSP(0x34))), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);



}
