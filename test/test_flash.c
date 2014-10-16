#include "unity.h"
#include "p18f4520.h"
#include "flash.h"

void setUp(){}
void tearDown(){}

void test_start_bit(){
  start_i2c();
	TEST_ASSERT_EQUAL(PIN_LOW, SDA_TRIS);
	TEST_ASSERT_EQUAL(PIN_LOW, SCL);
	TEST_ASSERT_EQUAL(PIN_LOW, SDA);
}

void test_stop_bit(){
  stop_i2c();
	TEST_ASSERT_EQUAL(PIN_LOW, SDA_TRIS);
	TEST_ASSERT_EQUAL(PIN_LOW, SCL);
	TEST_ASSERT_EQUAL(PIN_HIGH, SDA);
}
