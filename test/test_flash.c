#include "unity.h"
#include "p18f4520.h"
#include "flash.h"
#include "mock_fprogrammer.h"

void setUp(){}
void tearDown(){}

void test_PGD_high(){
  PGD = PIN_LOW;
  PGD_high();
	
  TEST_ASSERT_EQUAL(PIN_HIGH, PGD);
}

void test_PGD_low(){
  PGD = PIN_HIGH;
  PGD_low();
  TEST_ASSERT_EQUAL(PIN_LOW, PGD);
}

void test_PGC_high(){
  PGC = PIN_LOW;
  PGC_high();
  TEST_ASSERT_EQUAL(PIN_HIGH, PGC);
}

void test_PGC_low(){
  PGC = PIN_HIGH;
  PGC_low();
  TEST_ASSERT_EQUAL(PIN_LOW, PGC);
}

void test_enter_LVP(){
  MCLR = PIN_LOW;
  enter_LVP();
  TEST_ASSERT_EQUAL(PIN_HIGH, MCLR);
}

void test_exit_LVP(){
  MCLR = PIN_HIGH;
  exit_LVP();
  TEST_ASSERT_EQUAL(PIN_LOW, MCLR);
}