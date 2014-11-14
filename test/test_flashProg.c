#include "unity.h"
#include "mock_ICSP.h"
#include "FlashProg.h"
#include "p18f4520.h"

void setUp(){}
void tearDown(){}

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

void test_writeTableThenIncremeant_4bytes_of_data(){

  writeICSP_Expect(0xd, 0x5342);
  writeICSP_Expect(0xe, 0xac23);
  writeBits_Expect(0x0, 3);
  writeBits_Expect(0x0, 16);
  
  writeTableThenIncremeant(0x5342, 0xac23);
}

void test_tableSelect_should_select_0x102030(){

  writeICSP_Expect(0x0, 0x0e00|0x10);
  writeICSP_Expect(0x0, 0x6ef8);
  writeICSP_Expect(0x0, 0x0e00|0x20);
  writeICSP_Expect(0x0, 0x6ef7);
  writeICSP_Expect(0x0, 0x0e00|0x30);
  writeICSP_Expect(0x0, 0x6ef6);
  tableSelect(0x102030);
  
}

