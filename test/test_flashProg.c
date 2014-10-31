#include "unity.h"
#include "FlashProg.h"
#include "p18f4520.h"
#include "ICSP.h"

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

void test_enter_LVP(){
  _MCLR = PIN_LOW;
  _PGM = PIN_LOW;
  enter_LVP();
  TEST_ASSERT_EQUAL(PIN_HIGH, _MCLR);
  TEST_ASSERT_EQUAL(PIN_HIGH, _PGM);
}

void test_exit_LVP(){
  _MCLR = PIN_HIGH;
  _PGM = PIN_HIGH;
  _PGC = PIN_HIGH;
  _PGD = PIN_HIGH;
  exit_LVP();
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