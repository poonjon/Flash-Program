#include "unity.h"
#include "p18f4520.h"
#include "mock_ICSP.h"
#include "FlashProg.h"


void setUp(){}

void tearDown(){}



void addressMock(uint32 address){

  uint32 upperAddr;

  uint32 highAddr;

  uint32 lowAddr;



  lowAddr = (address&0x0000ff);

  highAddr = ((address>>8)&0x0000ff);

  upperAddr = ((address>>16)&0x0000ff);



  writeICSP_CMockExpect(18, 0x0, 0x0e00|upperAddr);

  writeICSP_CMockExpect(19, 0x0, 0x6ef8);

  writeICSP_CMockExpect(20, 0x0, 0x0e00|highAddr);

  writeICSP_CMockExpect(21, 0x0, 0x6ef7);

  writeICSP_CMockExpect(22, 0x0, 0x0e00|lowAddr);

  writeICSP_CMockExpect(23, 0x0, 0x6ef6);

}



void eraseMock(uint16 address){

 writeICSP_CMockExpect(27, 0x0, 0x8ea6);

  writeICSP_CMockExpect(28, 0x0, 0x9ca6);

  writeICSP_CMockExpect(29, 0x0, 0x84a6);



  writeICSP_CMockExpect(31, 0x0, 0x6af8);

  writeICSP_CMockExpect(32, 0x0, 0x6af7);

  writeICSP_CMockExpect(33, 0x0, 0x6af6);

  addressMock(address);



  writeICSP_CMockExpect(36, 0x0, 0x88a6);

  writeICSP_CMockExpect(37, 0x0, 0x82a6);

  writeICSP_CMockExpect(38, 0x0, 3);



  writeBits_CMockExpect(40, 0x0, 16);

}



void writeMock(uint16 data){

  writeICSP_CMockExpect(44, 0xd, data);

}



void write8Mock(uint16 data){



  writeICSP_CMockExpect(49, 0xf, data);

  writeBits_CMockExpect(50, 0x0, 3);

  writeBits_CMockExpect(51, 0x0, 16);

}



void test_PGD_high(){

  PORTDbits.RD4 = 0;

  PGD_high();

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((PORTDbits.RD4)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

}



void test_PGD_low(){

  PORTDbits.RD4 = 1;

  PGD_low();

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((PORTDbits.RD4)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

}



void test_PGC_high(){

  PORTDbits.RD5 = 0;

  PGC_high();

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((PORTDbits.RD5)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

}



void test_PGC_low(){

  PORTDbits.RD5 = 1;

  PGC_low();

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((PORTDbits.RD5)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

}



void test_enter_HVP(){

  PORTDbits.RD7 = 0;

  PORTDbits.RD6 = 0;

  enter_HVP();



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((PORTDbits.RD7)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((PORTDbits.RD6)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

}



void test_exit_HVP(){



  PORTDbits.RD7 = 1;

  PORTDbits.RD6 = 1;

  PORTDbits.RD5 = 1;

  PORTDbits.RD4 = 1;



  exit_HVP();



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((PORTDbits.RD7)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((PORTDbits.RD4)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((PORTDbits.RD5)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((PORTDbits.RD6)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

}



void test_MCLR_low(){

 PORTDbits.RD7 = 1;

  MCLR_low();

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((PORTDbits.RD7)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);



}



void test_MCLR_high(){

 PORTDbits.RD7 = 0;

  MCLR_high();

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((PORTDbits.RD7)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);



}



void test_PGM_high(){

 PORTDbits.RD6 = 0;

  PGM_high();

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((PORTDbits.RD6)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);



}



void test_PGM_low(){

 PORTDbits.RD6 = 1;

  PGM_low();

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((PORTDbits.RD6)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);



}



void test_enableWrite(){

  writeICSP_CMockExpect(131, 0x0, 0x8ea6);

  writeICSP_CMockExpect(132, 0x0, 0x9ca6);

  enableWrite();

}



void test_flashWriteAndProgram_2bytes_of_data(){



  writeICSP_CMockExpect(138, 0xf, 0x5342);

  writeBits_CMockExpect(139, 0x0, 3);

  writeBits_CMockExpect(140, 0x0, 16);



  flashWriteAndProgram(0x5342);

}



void test_flashWriteToBuffer_2bytes_of_data(){



  writeICSP_CMockExpect(147, 0xd, 0x5342);



  writeToBuffer(0x5342);

}



void test_flashSetAddress_should_select_0x102030(){



  writeICSP_CMockExpect(154, 0x0, 0x0e00|0x10);

  writeICSP_CMockExpect(155, 0x0, 0x6ef8);

  writeICSP_CMockExpect(156, 0x0, 0x0e00|0x20);

  writeICSP_CMockExpect(157, 0x0, 0x6ef7);

  writeICSP_CMockExpect(158, 0x0, 0x0e00|0x30);

  writeICSP_CMockExpect(159, 0x0, 0x6ef6);

  flashSetAddress(0x102030);



}



void test_rowErase_should_erase_row(){



  uint32 address = 0x000000;

  writeICSP_CMockExpect(167, 0x0, 0x8ea6);

  writeICSP_CMockExpect(168, 0x0, 0x9ca6);

  writeICSP_CMockExpect(169, 0x0, 0x84a6);





  writeICSP_CMockExpect(172, 0x0, 0x6af8);

  writeICSP_CMockExpect(173, 0x0, 0x6af7);

  writeICSP_CMockExpect(174, 0x0, 0x6af6);

  addressMock(address);



  writeICSP_CMockExpect(177, 0x0, 0x88a6);

  writeICSP_CMockExpect(178, 0x0, 0x82a6);

  writeBits_CMockExpect(179, 0x0, 3);

  writeBits_CMockExpect(180, 0x0, 16);



  rowErase(0x000000);



}
