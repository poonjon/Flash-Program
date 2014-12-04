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

void test_flashWriteAndProgram_4bytes_of_data(){

  writeICSP_Expect(0xd, 0xac23);
  writeICSP_Expect(0xe, 0x5342);
  writeBits_Expect(0x0, 3);
  writeBits_Expect(0x0, 16);
  
  flashWriteAndProgram(0x5342ac23);
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

void test_flashReadData_should_read_8bits_and_store_to_buffer(){
  uint8 buffer[32];
  uint16 writeSize; 
  uint16 size = 8;
  uint32 address = 0x168b5a;
  
  writeICSP_Expect(0x0, 0x0e16);
  writeICSP_Expect(0x0, 0x6ef8);
  writeICSP_Expect(0x0, 0x0e8b);
  writeICSP_Expect(0x0, 0x6ef7);
  writeICSP_Expect(0x0, 0x0e5a);
  writeICSP_Expect(0x0, 0x6ef6);
  readICSP_ExpectAndReturn(0x56);
  
  writeSize = flashReadData(&buffer[0], size, address);
  TEST_ASSERT_EQUAL(8, writeSize);
  TEST_ASSERT_EQUAL(0x56, buffer[0]);
}

void test_flashReadData_should_read_16bits_and_store_to_buffer(){
  uint8 buffer[32];
  uint16 writeSize; 
  uint16 size = 16;
  uint32 address = 0x168b5a;
  
  writeICSP_Expect(0x0, 0x0e16);
  writeICSP_Expect(0x0, 0x6ef8);
  writeICSP_Expect(0x0, 0x0e8b);
  writeICSP_Expect(0x0, 0x6ef7);
  writeICSP_Expect(0x0, 0x0e5a);
  writeICSP_Expect(0x0, 0x6ef6);
  readICSP_ExpectAndReturn(0x32);
  readICSP_ExpectAndReturn(0x56);
  
  writeSize = flashReadData(&buffer[0], size, address);
  TEST_ASSERT_EQUAL(16, writeSize);
  TEST_ASSERT_EQUAL(0x32, buffer[0]);
  TEST_ASSERT_EQUAL(0x56, buffer[1]);
}

void test_flashReadData_should_read_32bits_and_store_to_buffer(){
  uint8 buffer[32];
  uint16 writeSize; 
  uint16 size = 32;
  uint32 address = 0x168b5a;
  
  writeICSP_Expect(0x0, 0x0e16);
  writeICSP_Expect(0x0, 0x6ef8);
  writeICSP_Expect(0x0, 0x0e8b);
  writeICSP_Expect(0x0, 0x6ef7);
  writeICSP_Expect(0x0, 0x0e5a);
  writeICSP_Expect(0x0, 0x6ef6);
  readICSP_ExpectAndReturn(0x32);
  readICSP_ExpectAndReturn(0x56);
  readICSP_ExpectAndReturn(0xba);
  readICSP_ExpectAndReturn(0xba);
  
  writeSize = flashReadData(&buffer[0], size, address);
  TEST_ASSERT_EQUAL(32, writeSize);
  TEST_ASSERT_EQUAL(0x32, buffer[0]);
  TEST_ASSERT_EQUAL(0x56, buffer[1]);
  TEST_ASSERT_EQUAL(0xba, buffer[2]);
  TEST_ASSERT_EQUAL(0xba, buffer[3]);
}

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

void eraseMock(uint32 address){
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

void write16Mock(uint16 data){
  writeICSP_Expect(0xe, data);
  writeBits_Expect(0x0, 3);
  writeBits_Expect(0x0, 16);  
}

void test_flashWriteBlock_should_write_at_point_20(){
  uint32 address = 0x000010;
  uint16 writeSize; 
  uint8 incoming[38];
  uint8 buffer[38];
  uint16 ableToWrite;
  int i =0;
  incoming[0] = 0x12;
  while(i != 20){
    readICSP_ExpectAndReturn(&buffer[i]);
  }
  eraseMock(0x000000);
  
  writeSize = flashReadData(&buffer[0], 80, 0x000000);
  while(i != 10){
    write16Mock(incoming[0]);
  }
  
  printf("start\n");
  
  ableToWrite = flashWriteBlock(&incoming[0], 8, address);
  
  TEST_ASSERT_EQUAL(1, ableToWrite);
  
}

void test_flashWriteBlock_should_write_at_point_31_return_1(){
  uint32 address = 0x00001f;
  uint16 writeSize; 
  uint8 incoming[32];
  uint16 ableToWrite;
  
  writeICSP_Expect(0x0, 0x0e00);
  writeICSP_Expect(0x0, 0x6ef8);
  writeICSP_Expect(0x0, 0x0e00);
  writeICSP_Expect(0x0, 0x6ef7);
  writeICSP_Expect(0x0, 0x0e1f);
  writeICSP_Expect(0x0, 0x6ef6);
  writeICSP_Expect(0xd, 0x12);
  writeICSP_Expect(0xe, 0x00);
  writeBits_Expect(0x0, 3);
  writeBits_Expect(0x0, 16);  
  
  printf("start\n");
  incoming[0] = 0x12;
  incoming[1] = 0x32;
  
  ableToWrite = flashWriteBlock(&incoming[0], 16, address);
  
  TEST_ASSERT_EQUAL(1, ableToWrite);
  
}

void test_memRange_address_0x8_should_get_24(){
  uint32 address;
  uint32 inputAddress = 0x8;
  
  address = memRange(inputAddress);
  
  TEST_ASSERT_EQUAL(24, address);

}

void test_memRange_address_0x1d_should_get_3(){
  uint32 address;
  uint32 inputAddress = 0x1d;
  
  address = memRange(inputAddress);
  
  TEST_ASSERT_EQUAL(3, address);

}

void test_memRange_address_0x2c_should_get_20(){
  uint32 address;
  uint32 inputAddress = 0x2c;
  
  address = memRange(inputAddress);
  
  TEST_ASSERT_EQUAL(20, address);

}
