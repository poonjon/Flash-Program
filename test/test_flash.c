#include "unity.h"
#include "p18f4520.h"
#include "ICSP.h"
#include "flash.h"

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

// void test_bulkErase_should_pass(){
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x0e3c, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x6ef8, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x0e00, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x6ef7, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x0e05, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x6ef6, 16);  
  // mockBitsWriting(0xc, 8);
  // mockBitsWriting(0x3f3f, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x0e3c, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x6ef8, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x0e00, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x6ef7, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x0e04, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x6ef6, 16);
  // mockBitsWriting(0xc, 8);
  // mockBitsWriting(0x8f8f, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x0e00, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x0, 16);
  // mockBitsWriting(0x0, 8);
  // mockBitsWriting(0x0, 16);
  
  // bulkErase();

// }