#include "unity.h"
#include "ICSP.h"
#include "mock_flash.h"
#include "Type.h"

void setUp(void){}
void tearDown(void){}

void mockBitsWriting(uint16 pattern, uint16 bitsToWrite){
  int i = 0;
  while(i < bitsToWrite){
    printf("%d", MSB(pattern, bitsToWrite, i));
    writePGD_Expect(MSB(pattern, bitsToWrite, i));
    PGC_high_Expect();
    PGC_low_Expect(); 
    i++;
  }
}

void mockBitsReading(uint16 pattern, uint16 bitsToRead){
  int i=0;
  while(i < bitsToRead){
    printf("%d", MSB(pattern, bitsToRead, i));
    readPGD_ExpectAndReturn(MSB(pattern, bitsToRead, i));
    PGC_high_Expect();
    PGC_low_Expect(); 
    i++;
  }
  
}

void test_write_bit_1(){
  writePGD_Expect(1);
  PGC_high_Expect();
  PGC_low_Expect();  
  
  writeBit(1);
}

void test_write_bit_0(){
  writePGD_Expect(0);
  PGC_high_Expect();
  PGC_low_Expect();  
  
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

void test_writeICSP_write_0xd_command_0x4de3_data(){
  mockBitsWriting(0xd, 4);
  mockBitsWriting(0x3c40, 16);
  
  writeICSP(0xd, 0x3c40);

}

void test_readBit_should_return_1(){
  readPGD_ExpectAndReturn(1);
  PGC_high_Expect();
  PGC_low_Expect();  
  
  TEST_ASSERT_EQUAL(1, readBit());
  
}

void test_readBit_should_return_0(){
  readPGD_ExpectAndReturn(0);
  PGC_high_Expect();
  PGC_low_Expect();  
  
  TEST_ASSERT_EQUAL(0, readBit());
  
}

void test_readBits_should_return_0x11(){
  mockBitsReading(0x11, 8);
  TEST_ASSERT_EQUAL(0x11, readBits(8));
  
}

void test_readBits_should_return_0xf6(){
  
  mockBitsReading(0xf6, 8);
  TEST_ASSERT_EQUAL(0xf6, readBits(8));
  
}

void test_readBits_should_return_0x35f6(){
  
  mockBitsReading(0x35f6, 16);
  TEST_ASSERT_EQUAL(0x35f6, readBits(16));
  
}

void test_readICSP_should_read_0x34(){
  mockBitsWriting(0x9, 4);
  mockBitsReading(0x34, 8);
  TEST_ASSERT_EQUAL(0x34, readICSP(0x34));
  
}


