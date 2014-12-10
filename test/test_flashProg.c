#include "unity.h"
#include "mock_ICSP.h"
#include "FlashProg.h"
#include "p18f4520.h"

void setUp(){}
void tearDown(){}

void addressMock(uint32 address){
  uint32 upperAddr;
  uint32 highAddr;
  uint32 lowAddr;
  
  lowAddr = (address&0x0000ff);
  highAddr = ((address>>8)&0x0000ff);
  upperAddr = ((address>>16)&0x0000ff);

  writeICSP_Expect(0x0, 0x0e00|upperAddr);
  writeICSP_Expect(0x0, 0x6ef8);
  writeICSP_Expect(0x0, 0x0e00|highAddr);
  writeICSP_Expect(0x0, 0x6ef7);
  writeICSP_Expect(0x0, 0x0e00|lowAddr);
  writeICSP_Expect(0x0, 0x6ef6);
}

void eraseMock(uint16 address){
	writeICSP_Expect(0x0, 0x8ea6);
  writeICSP_Expect(0x0, 0x9ca6);
  writeICSP_Expect(0x0, 0x84a6);

  writeICSP_Expect(0x0, 0x6af8);
  writeICSP_Expect(0x0, 0x6af7);
  writeICSP_Expect(0x0, 0x6af6);
  addressMock(address);

  writeICSP_Expect(0x0, 0x88a6);
  writeICSP_Expect(0x0, 0x82a6);
  writeICSP_Expect(0x0, 3);

  writeBits_Expect(0x0, 16);
}

void writeMock(uint16 data){
  writeICSP_Expect(0xd, data);
}

void writeProgramMock(uint16 data){
  
  writeICSP_Expect(0xf, data);
  writeBits_Expect(0x0, 3);
  writeBits_Expect(0x0, 16);  
}

void test_PGD_high(){
  _PGD = PIN_LOW;
  PGD_high();
  TEST_ASSERT_EQUAL(PIN_HIGH, _PGD);
}

void test_PGD_low(){
  _PGD = PIN_HIGH;
  PGD_low();
  TEST_ASSERT_EQUAL(PIN_LOW, _PGD);
}

void test_PGC_high(){
  _PGC = PIN_LOW;
  PGC_high();
  TEST_ASSERT_EQUAL(PIN_HIGH, _PGC);
}

void test_PGC_low(){
  _PGC = PIN_HIGH;
  PGC_low();
  TEST_ASSERT_EQUAL(PIN_LOW, _PGC);
}

void test_enter_HVP(){
  _MCLR = PIN_LOW;
  _PGM = PIN_LOW;
  enter_HVP();

  TEST_ASSERT_EQUAL(PIN_HIGH, _MCLR);
  TEST_ASSERT_EQUAL(PIN_HIGH, _PGM);
}

void test_exit_HVP(){

  _MCLR = PIN_HIGH;
  _PGM = PIN_HIGH;
  _PGC = PIN_HIGH;
  _PGD = PIN_HIGH;

  exit_HVP();

  TEST_ASSERT_EQUAL(PIN_LOW, _MCLR);
  TEST_ASSERT_EQUAL(PIN_LOW, _PGD);
  TEST_ASSERT_EQUAL(PIN_LOW, _PGC);
  TEST_ASSERT_EQUAL(PIN_LOW, _PGM);
}

void test_MCLR_low(){
	_MCLR = PIN_HIGH;
  MCLR_low();
  TEST_ASSERT_EQUAL(PIN_LOW, _MCLR);
	
}

void test_MCLR_high(){
	_MCLR = PIN_LOW;
  MCLR_high();
  TEST_ASSERT_EQUAL(PIN_HIGH, _MCLR);
	
}

void test_PGM_high(){
	_PGM = PIN_LOW;
  PGM_high();
  TEST_ASSERT_EQUAL(PIN_HIGH, _PGM);
	
}

void test_PGM_low(){
	_PGM = PIN_HIGH;
  PGM_low();
  TEST_ASSERT_EQUAL(PIN_LOW, _PGM);
	
}

void test_enableWrite(){
  writeICSP_Expect(0x0, 0x8ea6);
  writeICSP_Expect(0x0, 0x9ca6);
  enableWrite();
}

void test_flashSetAddress_should_select_0x102030(){

  writeICSP_Expect(0x0, 0x0e00|0x10);
  writeICSP_Expect(0x0, 0x6ef8);
  writeICSP_Expect(0x0, 0x0e00|0x20);
  writeICSP_Expect(0x0, 0x6ef7);
  writeICSP_Expect(0x0, 0x0e00|0x30);
  writeICSP_Expect(0x0, 0x6ef6);
  flashSetAddress(0x102030);
  
}

void test_flashWriteToBuffer_2bytes_of_data(){

  writeICSP_Expect(0xd, 0x5342);
  
  writeToBuffer(0x5342);
}

void test_flashWriteAndProgram_2bytes_of_data(){

  writeICSP_Expect(0xf, 0x5342);
  writeBits_Expect(0x0, 3);
  writeBits_Expect(0x0, 16);
  
  flashWriteAndProgram(0x5342);
}

void test_flashRead16Bits_should_read_2bytes_and_return_0x1001(){
  uint16 data;
  
  readICSP_ExpectAndReturn(0x0001);
  readFirstByte_ExpectAndReturn(0x1000);
  
  data = flashRead16Bits();
  TEST_ASSERT_EQUAL(0x1001, data);
}

void test_flashReadBlock_should_read_64bits(){
  uint16 i, read[32];
  
  addressMock(0x000000);
  for(i = 0 ; i < 32 ; i++){
    readICSP_ExpectAndReturn(0x0000);
    readFirstByte_ExpectAndReturn(0x0000);
  }
  flashReadBlock(read, 64, 1);
}

void test_flashWriteBlock_should_write(){
  int i, first[16] = {0}, second[16] = {0};
  
  addressMock(0);
  for(i = 0 ; i < 15 ; i++){
    writeMock(first[i]);
  }
  writeProgramMock(first[15]);
  
  addressMock(32);
  for(i = 0 ; i < 15 ; i++){
    writeMock(second[i]);
  }
  writeProgramMock(second[15]);
  
  flashWriteBlock(first, second, 1);
}

void test_rowErase_should_erase_row(){

  uint32 address = 0x000000;
  writeICSP_Expect(0x0, 0x8ea6);
  writeICSP_Expect(0x0, 0x9ca6);
  writeICSP_Expect(0x0, 0x84a6);


  writeICSP_Expect(0x0, 0x6af8);
  writeICSP_Expect(0x0, 0x6af7);
  writeICSP_Expect(0x0, 0x6af6);
  addressMock(address);

  writeICSP_Expect(0x0, 0x88a6);
  writeICSP_Expect(0x0, 0x82a6);
  writeBits_Expect(0x0, 3);
  writeBits_Expect(0x0, 16);
  
  rowErase(0x000000);

}
