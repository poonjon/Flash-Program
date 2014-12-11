#include "unity.h"
#include "FlashWrite.h"
#include "mock_FlashProg.h"
#include "p18f4520.h"

void setUp(){}
void tearDown(){}

void test_overwriteBufferData_should_overwrite_array_2_to_6(){
  uint16 incomingData[5];
  int i;
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
  
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  
  incomingData[0] = 0x1234;
  incomingData[1] = 0x5568;
  incomingData[2] = 0x3265;
  incomingData[3] = 0x4895;
  incomingData[4] = 0xa568;
  
  TEST_ASSERT_EQUAL(5, overwriteBufferData(incomingData, 5, 2));
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[0]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(0x1234, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(0x5568, halfBuffer1[3]);
  TEST_ASSERT_EQUAL(0x3265, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(0x4895, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(0xa568, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[8]);
}

void test_overwriteBufferData_should_overwrite_array_0_to_32(){
  int i, data = 0;
  int incomingData[32];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
  
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 32 ; i++){
    incomingData[i] = data;
    data++;
  }
  
  TEST_ASSERT_EQUAL(32, overwriteBufferData(incomingData, 32, 0));
  TEST_ASSERT_EQUAL(0, halfBuffer1[0]);
  TEST_ASSERT_EQUAL(1, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(2, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(3, halfBuffer1[3]);
  TEST_ASSERT_EQUAL(4, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(5, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(6, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(7, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(8, halfBuffer1[8]); 
  TEST_ASSERT_EQUAL(9, halfBuffer1[9]);
  TEST_ASSERT_EQUAL(10, halfBuffer1[10]);
  TEST_ASSERT_EQUAL(11, halfBuffer1[11]);
  TEST_ASSERT_EQUAL(12, halfBuffer1[12]);
  TEST_ASSERT_EQUAL(13, halfBuffer1[13]);
  TEST_ASSERT_EQUAL(14, halfBuffer1[14]);
  TEST_ASSERT_EQUAL(15, halfBuffer1[15]);  
  TEST_ASSERT_EQUAL(16, halfBuffer2[0]);
  TEST_ASSERT_EQUAL(17, halfBuffer2[1]);
  TEST_ASSERT_EQUAL(18, halfBuffer2[2]);
  TEST_ASSERT_EQUAL(19, halfBuffer2[3]);
  TEST_ASSERT_EQUAL(20, halfBuffer2[4]);
  TEST_ASSERT_EQUAL(21, halfBuffer2[5]);
  TEST_ASSERT_EQUAL(22, halfBuffer2[6]);
  TEST_ASSERT_EQUAL(23, halfBuffer2[7]);
  TEST_ASSERT_EQUAL(24, halfBuffer2[8]); 
  TEST_ASSERT_EQUAL(25, halfBuffer2[9]);
  TEST_ASSERT_EQUAL(26, halfBuffer2[10]);
  TEST_ASSERT_EQUAL(27, halfBuffer2[11]);
  TEST_ASSERT_EQUAL(28, halfBuffer2[12]);
  TEST_ASSERT_EQUAL(29, halfBuffer2[13]);
  TEST_ASSERT_EQUAL(30, halfBuffer2[14]);
  TEST_ASSERT_EQUAL(31, halfBuffer2[15]);
  
}

void test_overwriteBufferData_should_overwrite_array_0_to_32_and_overflow(){
  int i, data = 0;
  int incomingData[40];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
  
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 40 ; i++){
    incomingData[i] = data;
    data++;
  }
  
  TEST_ASSERT_EQUAL(32, overwriteBufferData(incomingData, 40, 0));
  TEST_ASSERT_EQUAL(0, halfBuffer1[0]);
  TEST_ASSERT_EQUAL(1, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(2, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(3, halfBuffer1[3]);
  TEST_ASSERT_EQUAL(4, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(5, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(6, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(7, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(8, halfBuffer1[8]); 
  TEST_ASSERT_EQUAL(9, halfBuffer1[9]);
  TEST_ASSERT_EQUAL(10, halfBuffer1[10]);
  TEST_ASSERT_EQUAL(11, halfBuffer1[11]);
  TEST_ASSERT_EQUAL(12, halfBuffer1[12]);
  TEST_ASSERT_EQUAL(13, halfBuffer1[13]);
  TEST_ASSERT_EQUAL(14, halfBuffer1[14]);
  TEST_ASSERT_EQUAL(15, halfBuffer1[15]);  
  TEST_ASSERT_EQUAL(16, halfBuffer2[0]);
  TEST_ASSERT_EQUAL(17, halfBuffer2[1]);
  TEST_ASSERT_EQUAL(18, halfBuffer2[2]);
  TEST_ASSERT_EQUAL(19, halfBuffer2[3]);
  TEST_ASSERT_EQUAL(20, halfBuffer2[4]);
  TEST_ASSERT_EQUAL(21, halfBuffer2[5]);
  TEST_ASSERT_EQUAL(22, halfBuffer2[6]);
  TEST_ASSERT_EQUAL(23, halfBuffer2[7]);
  TEST_ASSERT_EQUAL(24, halfBuffer2[8]); 
  TEST_ASSERT_EQUAL(25, halfBuffer2[9]);
  TEST_ASSERT_EQUAL(26, halfBuffer2[10]);
  TEST_ASSERT_EQUAL(27, halfBuffer2[11]);
  TEST_ASSERT_EQUAL(28, halfBuffer2[12]);
  TEST_ASSERT_EQUAL(29, halfBuffer2[13]);
  TEST_ASSERT_EQUAL(30, halfBuffer2[14]);
  TEST_ASSERT_EQUAL(31, halfBuffer2[15]);
  
}

void test_overwriteBufferData_should_overwrite_array_15_to_21(){
  int i, data = 0;
  int incomingData[6];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
  
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 6 ; i++){
    incomingData[i] = data;
    data++;
  }
  
  TEST_ASSERT_EQUAL(6, overwriteBufferData(incomingData, 6, 15));
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[13]);  
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[14]);  
  TEST_ASSERT_EQUAL(0, halfBuffer1[15]);  
  TEST_ASSERT_EQUAL(1, halfBuffer2[0]);
  TEST_ASSERT_EQUAL(2, halfBuffer2[1]);
  TEST_ASSERT_EQUAL(3, halfBuffer2[2]);
  TEST_ASSERT_EQUAL(4, halfBuffer2[3]);
  TEST_ASSERT_EQUAL(5, halfBuffer2[4]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer2[5]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer2[6]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer2[7]);
  
}

void test_overwriteBufferData_should_overwrite_array_28_to_32_and_overflow(){
  int i, data = 0;
  int incomingData[10];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
  
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 10 ; i++){
    incomingData[i] = data;
    data++;
  }
  
  TEST_ASSERT_EQUAL(4, overwriteBufferData(incomingData, 10, 28));
  TEST_ASSERT_EQUAL(3, halfBuffer2[15]);  
  TEST_ASSERT_EQUAL(2, halfBuffer2[14]);
  TEST_ASSERT_EQUAL(1, halfBuffer2[13]);
  TEST_ASSERT_EQUAL(0, halfBuffer2[12]);
  
}

/*
** 0__4__8__________________________
** |  ///                           |
** |  ///                           |
** |________________________________|
*/
void test_flashWriteData_should_write_data_from_address_4_to_8_should_return_3(){
  int i, bytesWritten;
  uint16 incomingData[3];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
  
  incomingData[0] = 0x1234;
  incomingData[1] = 0x5445;
  incomingData[2] = 0x6677;
  
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  flashReadBlock_Expect(blockBuffer, 64, 1);
  
  rowErase_Expect(0x000000);
  flashSetAddress_Expect(0);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 1);

  bytesWritten = flashWriteData(incomingData, 3, 4);
  
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[0]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(0x1234, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(0x5445, halfBuffer1[3]);
  TEST_ASSERT_EQUAL(0x6677, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(3, bytesWritten);
}

/*
** 0______14______30________________
** |       ////////                 |
** |       ////////                 |
** |________________________________|
*/
void test_flashWriteData_should_write_0_to_8_from_address_14_to_30_should_return_9(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[9];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 9 ; i++){
    incomingData[i] = data;
    data++;
  }
  flashReadBlock_Expect(blockBuffer, 64, 1);
  
  rowErase_Expect(0x000000);
  flashSetAddress_Expect(0);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 1);

  bytesWritten = flashWriteData(incomingData, 9, 14);
  
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[0]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(0, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(1, halfBuffer1[8]);
  TEST_ASSERT_EQUAL(2, halfBuffer1[9]);
  TEST_ASSERT_EQUAL(3, halfBuffer1[10]);
  TEST_ASSERT_EQUAL(4, halfBuffer1[11]);
  TEST_ASSERT_EQUAL(5, halfBuffer1[12]);
  TEST_ASSERT_EQUAL(6, halfBuffer1[13]);
  TEST_ASSERT_EQUAL(7, halfBuffer1[14]);
  TEST_ASSERT_EQUAL(8, halfBuffer1[15]);
  TEST_ASSERT_EQUAL(9, bytesWritten);
}

/*
** 0______________30________________
** |///////////////                 |
** |///////////////                 |
** |________________________________|
*/
void test_flashWriteData_should_write_0_to_15_from_address_0_to_30_should_return_16(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[16];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 16 ; i++){
    incomingData[i] = data;
    data++;
  }
  flashReadBlock_Expect(blockBuffer, 64, 1);
  
  rowErase_Expect(0x000000);
  flashSetAddress_Expect(0);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 1);

  bytesWritten = flashWriteData(incomingData, 16, 0);
  
  TEST_ASSERT_EQUAL(0, halfBuffer1[0]);
  TEST_ASSERT_EQUAL(1, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(2, halfBuffer1[2]);  
  TEST_ASSERT_EQUAL(3, halfBuffer1[3]);
  TEST_ASSERT_EQUAL(4, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(5, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(6, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(7, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(8, halfBuffer1[8]);
  TEST_ASSERT_EQUAL(9, halfBuffer1[9]);
  TEST_ASSERT_EQUAL(10, halfBuffer1[10]);
  TEST_ASSERT_EQUAL(11, halfBuffer1[11]);
  TEST_ASSERT_EQUAL(12, halfBuffer1[12]);
  TEST_ASSERT_EQUAL(13, halfBuffer1[13]);
  TEST_ASSERT_EQUAL(14, halfBuffer1[14]);
  TEST_ASSERT_EQUAL(15, halfBuffer1[15]);
  TEST_ASSERT_EQUAL(16, bytesWritten);
}

/*
** 0______________28______42________
** |               ////////         |
** |               ////////         |
** |________________________________|
*/
void test_flashWriteData_should_write_0_to_7_from_address_28_to_42_should_return_8(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[8];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 8 ; i++){
    incomingData[i] = data;
    data++;
  }
  flashReadBlock_Expect(blockBuffer, 64, 1);
  
  rowErase_Expect(0x000000);
  flashSetAddress_Expect(0);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 1);

  bytesWritten = flashWriteData(incomingData, 8, 28);
  
  TEST_ASSERT_EQUAL(0, halfBuffer1[14]);
  TEST_ASSERT_EQUAL(1, halfBuffer1[15]);
  TEST_ASSERT_EQUAL(2, halfBuffer2[0]);  
  TEST_ASSERT_EQUAL(3, halfBuffer2[1]);
  TEST_ASSERT_EQUAL(4, halfBuffer2[2]);
  TEST_ASSERT_EQUAL(5, halfBuffer2[3]);
  TEST_ASSERT_EQUAL(6, halfBuffer2[4]);
  TEST_ASSERT_EQUAL(7, halfBuffer2[5]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer2[7]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer2[8]);
  TEST_ASSERT_EQUAL(8, bytesWritten);
}

/*
** 64_66_________88_________________
** |  ////////////                  |
** |  ////////////                  |
** |________________________________|
*/
void test_flashWriteData_should_write_0_to_10_from_address_66_to_88_should_return_11(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[11];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 11 ; i++){
    incomingData[i] = data;
    data++;
  }
  flashReadBlock_Expect(blockBuffer, 64, 2);
  
  rowErase_Expect(64);
  flashSetAddress_Expect(64);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 2);
  bytesWritten = flashWriteData(incomingData, 11, 66);
  
  TEST_ASSERT_EQUAL(0, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(1, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(2, halfBuffer1[3]);  
  TEST_ASSERT_EQUAL(3, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(4, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(5, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(6, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(7, halfBuffer1[8]);
  TEST_ASSERT_EQUAL(8, halfBuffer1[9]);
  TEST_ASSERT_EQUAL(9, halfBuffer1[10]);
  TEST_ASSERT_EQUAL(10, halfBuffer1[11]);
  TEST_ASSERT_EQUAL(11, bytesWritten);
}

/*
** 0_______________________________62
** |////////////////////////////////|
** |////////////////////////////////|
** |________________________________|
*/
void test_flashWriteData_should_write_0_to_31_from_address_0_to_62_should_return_32(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[32];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 32 ; i++){
    incomingData[i] = data;
    data++;
  }
  flashReadBlock_Expect(blockBuffer, 64, 1);
  
  rowErase_Expect(0x000000);
  flashSetAddress_Expect(0);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 1);

  bytesWritten = flashWriteData(incomingData, 32, 0);
  
  TEST_ASSERT_EQUAL(0, halfBuffer1[0]);
  TEST_ASSERT_EQUAL(1, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(2, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(3, halfBuffer1[3]);
  TEST_ASSERT_EQUAL(4, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(5, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(6, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(7, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(8, halfBuffer1[8]); 
  TEST_ASSERT_EQUAL(9, halfBuffer1[9]);
  TEST_ASSERT_EQUAL(10, halfBuffer1[10]);
  TEST_ASSERT_EQUAL(11, halfBuffer1[11]);
  TEST_ASSERT_EQUAL(12, halfBuffer1[12]);
  TEST_ASSERT_EQUAL(13, halfBuffer1[13]);
  TEST_ASSERT_EQUAL(14, halfBuffer1[14]);
  TEST_ASSERT_EQUAL(15, halfBuffer1[15]);  
  TEST_ASSERT_EQUAL(16, halfBuffer2[0]);
  TEST_ASSERT_EQUAL(17, halfBuffer2[1]);
  TEST_ASSERT_EQUAL(18, halfBuffer2[2]);
  TEST_ASSERT_EQUAL(19, halfBuffer2[3]);
  TEST_ASSERT_EQUAL(20, halfBuffer2[4]);
  TEST_ASSERT_EQUAL(21, halfBuffer2[5]);
  TEST_ASSERT_EQUAL(22, halfBuffer2[6]);
  TEST_ASSERT_EQUAL(23, halfBuffer2[7]);
  TEST_ASSERT_EQUAL(24, halfBuffer2[8]); 
  TEST_ASSERT_EQUAL(25, halfBuffer2[9]);
  TEST_ASSERT_EQUAL(26, halfBuffer2[10]);
  TEST_ASSERT_EQUAL(27, halfBuffer2[11]);
  TEST_ASSERT_EQUAL(28, halfBuffer2[12]);
  TEST_ASSERT_EQUAL(29, halfBuffer2[13]);
  TEST_ASSERT_EQUAL(30, halfBuffer2[14]);
  TEST_ASSERT_EQUAL(31, halfBuffer2[15]);
  TEST_ASSERT_EQUAL(32, bytesWritten);
}

/*
** 0_____________________________62_64_68___
** |////////////////////////////////|///
** |////////////////////////////////|///
** |________________________________|________
*/
void test_flashWriteData_should_write_0_to_31_from_address_0_to_68_should_return_35(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[35];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 35 ; i++){
    incomingData[i] = data;
    data++;
  }
  flashReadBlock_Expect(blockBuffer, 64, 1);
  rowErase_Expect(0x000000);
  flashSetAddress_Expect(0);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 1);
  
  flashReadBlock_Expect(blockBuffer, 64, 2);
  rowErase_Expect(64);
  flashSetAddress_Expect(64);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 2);
  bytesWritten = flashWriteData(incomingData, 35, 0);
  
  TEST_ASSERT_EQUAL(32, halfBuffer1[0]);
  TEST_ASSERT_EQUAL(33, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(34, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(35, bytesWritten);
}

/*
** 0______________________________62_64___________________________126
** |////////////////////////////////|////////////////////////////////|
** |////////////////////////////////|////////////////////////////////|
** |________________________________|________________________________
*/
void test_flashWriteData_should_write_0_to_63_from_address_0_to_126_should_return_64(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[64];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 64 ; i++){
    incomingData[i] = data;
    data++;
  }
  flashReadBlock_Expect(blockBuffer, 64, 1);
  rowErase_Expect(0x000000);
  flashSetAddress_Expect(0);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 1);
  
  flashReadBlock_Expect(blockBuffer, 64, 2);
  rowErase_Expect(64);
  flashSetAddress_Expect(64);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 2);
  bytesWritten = flashWriteData(incomingData, 64, 0);
  
  TEST_ASSERT_EQUAL(32, halfBuffer1[0]);  
  TEST_ASSERT_EQUAL(33, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(34, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(35, halfBuffer1[3]);
  TEST_ASSERT_EQUAL(36, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(37, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(38, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(39, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(40, halfBuffer1[8]); 
  TEST_ASSERT_EQUAL(41, halfBuffer1[9]);
  TEST_ASSERT_EQUAL(42, halfBuffer1[10]);
  TEST_ASSERT_EQUAL(43, halfBuffer1[11]);
  TEST_ASSERT_EQUAL(44, halfBuffer1[12]);
  TEST_ASSERT_EQUAL(45, halfBuffer1[13]);
  TEST_ASSERT_EQUAL(46, halfBuffer1[14]);
  TEST_ASSERT_EQUAL(47, halfBuffer1[15]);  
  TEST_ASSERT_EQUAL(48, halfBuffer2[0]);
  TEST_ASSERT_EQUAL(49, halfBuffer2[1]);
  TEST_ASSERT_EQUAL(50, halfBuffer2[2]);
  TEST_ASSERT_EQUAL(51, halfBuffer2[3]);
  TEST_ASSERT_EQUAL(52, halfBuffer2[4]);
  TEST_ASSERT_EQUAL(53, halfBuffer2[5]);
  TEST_ASSERT_EQUAL(54, halfBuffer2[6]);
  TEST_ASSERT_EQUAL(55, halfBuffer2[7]);
  TEST_ASSERT_EQUAL(56, halfBuffer2[8]); 
  TEST_ASSERT_EQUAL(57, halfBuffer2[9]);
  TEST_ASSERT_EQUAL(58, halfBuffer2[10]);
  TEST_ASSERT_EQUAL(59, halfBuffer2[11]);
  TEST_ASSERT_EQUAL(60, halfBuffer2[12]);
  TEST_ASSERT_EQUAL(61, halfBuffer2[13]);
  TEST_ASSERT_EQUAL(62, halfBuffer2[14]);
  TEST_ASSERT_EQUAL(63, halfBuffer2[15]);
  TEST_ASSERT_EQUAL(64, bytesWritten);
}

/*
** 0___________________________62_64_________________________126_128_________
** |                            //|//////////////////////////////|
** |                            //|//////////////////////////////|
** |______________________________|______________________________|____________
*/
void test_flashWriteData_should_write_0_to_33_from_address_60_to_126_should_return_34(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[34];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 34 ; i++){
    incomingData[i] = data;
    data++;
  }
  
  flashReadBlock_Expect(blockBuffer, 64, 1);
  rowErase_Expect(0x000000);
  flashSetAddress_Expect(0);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 1);
  
  flashReadBlock_Expect(blockBuffer, 64, 2);
  rowErase_Expect(64);
  flashSetAddress_Expect(64);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 2);
  
  bytesWritten = flashWriteData(incomingData, 34, 60);
  
  TEST_ASSERT_EQUAL(2, halfBuffer1[0]);  
  TEST_ASSERT_EQUAL(3, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(4, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(5, halfBuffer1[3]);
  TEST_ASSERT_EQUAL(6, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(7, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(8, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(9, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(10, halfBuffer1[8]); 
  TEST_ASSERT_EQUAL(11, halfBuffer1[9]);
  TEST_ASSERT_EQUAL(12, halfBuffer1[10]);
  TEST_ASSERT_EQUAL(13, halfBuffer1[11]);
  TEST_ASSERT_EQUAL(14, halfBuffer1[12]);
  TEST_ASSERT_EQUAL(15, halfBuffer1[13]);
  TEST_ASSERT_EQUAL(16, halfBuffer1[14]);
  TEST_ASSERT_EQUAL(17, halfBuffer1[15]);  
  TEST_ASSERT_EQUAL(18, halfBuffer2[0]);
  TEST_ASSERT_EQUAL(19, halfBuffer2[1]);
  TEST_ASSERT_EQUAL(20, halfBuffer2[2]);
  TEST_ASSERT_EQUAL(21, halfBuffer2[3]);
  TEST_ASSERT_EQUAL(22, halfBuffer2[4]);
  TEST_ASSERT_EQUAL(23, halfBuffer2[5]);
  TEST_ASSERT_EQUAL(24, halfBuffer2[6]);
  TEST_ASSERT_EQUAL(25, halfBuffer2[7]);
  TEST_ASSERT_EQUAL(26, halfBuffer2[8]); 
  TEST_ASSERT_EQUAL(27, halfBuffer2[9]);
  TEST_ASSERT_EQUAL(28, halfBuffer2[10]);
  TEST_ASSERT_EQUAL(29, halfBuffer2[11]);
  TEST_ASSERT_EQUAL(30, halfBuffer2[12]);
  TEST_ASSERT_EQUAL(31, halfBuffer2[13]);
  TEST_ASSERT_EQUAL(32, halfBuffer2[14]);
  TEST_ASSERT_EQUAL(33, halfBuffer2[15]);
  TEST_ASSERT_EQUAL(34, bytesWritten);
}

/*
** 0____________________________62_64_________________________126_128_________________________192
** |//////////////////////////////|//////////////////////////////|//////////////////////////////|
** |//////////////////////////////|//////////////////////////////|//////////////////////////////|
** |______________________________|______________________________|______________________________|
*/
void test_flashWriteData_should_write_0_to_95_from_address_0_to_192_should_return_96(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[96];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 96 ; i++){
    incomingData[i] = data;
    data++;
  }

  flashReadBlock_Expect(blockBuffer, 64, 1);
  rowErase_Expect(0x000000);
  flashSetAddress_Expect(0);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 1);
  
  flashReadBlock_Expect(blockBuffer, 64, 2);
  rowErase_Expect(64);
  flashSetAddress_Expect(64);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 2);
  
  flashReadBlock_Expect(blockBuffer, 64, 3);
  rowErase_Expect(128);
  flashSetAddress_Expect(128);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 3);
  
  bytesWritten = flashWriteData(incomingData, 96, 0);
  
  TEST_ASSERT_EQUAL(64, halfBuffer1[0]);  
  TEST_ASSERT_EQUAL(65, halfBuffer1[1]);
  TEST_ASSERT_EQUAL(66, halfBuffer1[2]);
  TEST_ASSERT_EQUAL(67, halfBuffer1[3]);
  TEST_ASSERT_EQUAL(68, halfBuffer1[4]);
  TEST_ASSERT_EQUAL(69, halfBuffer1[5]);
  TEST_ASSERT_EQUAL(70, halfBuffer1[6]);
  TEST_ASSERT_EQUAL(71, halfBuffer1[7]);
  TEST_ASSERT_EQUAL(72, halfBuffer1[8]); 
  TEST_ASSERT_EQUAL(73, halfBuffer1[9]);
  TEST_ASSERT_EQUAL(74, halfBuffer1[10]);
  TEST_ASSERT_EQUAL(75, halfBuffer1[11]);
  TEST_ASSERT_EQUAL(76, halfBuffer1[12]);
  TEST_ASSERT_EQUAL(77, halfBuffer1[13]);
  TEST_ASSERT_EQUAL(78, halfBuffer1[14]);
  TEST_ASSERT_EQUAL(79, halfBuffer1[15]);  
  TEST_ASSERT_EQUAL(80, halfBuffer2[0]);
  TEST_ASSERT_EQUAL(81, halfBuffer2[1]);
  TEST_ASSERT_EQUAL(82, halfBuffer2[2]);
  TEST_ASSERT_EQUAL(83, halfBuffer2[3]);
  TEST_ASSERT_EQUAL(84, halfBuffer2[4]);
  TEST_ASSERT_EQUAL(85, halfBuffer2[5]);
  TEST_ASSERT_EQUAL(86, halfBuffer2[6]);
  TEST_ASSERT_EQUAL(87, halfBuffer2[7]);
  TEST_ASSERT_EQUAL(88, halfBuffer2[8]); 
  TEST_ASSERT_EQUAL(89, halfBuffer2[9]);
  TEST_ASSERT_EQUAL(90, halfBuffer2[10]);
  TEST_ASSERT_EQUAL(91, halfBuffer2[11]);
  TEST_ASSERT_EQUAL(92, halfBuffer2[12]);
  TEST_ASSERT_EQUAL(93, halfBuffer2[13]);
  TEST_ASSERT_EQUAL(94, halfBuffer2[14]);
  TEST_ASSERT_EQUAL(95, halfBuffer2[15]);
  TEST_ASSERT_EQUAL(96, bytesWritten);
}

/*
** 64____________96____________126_128________
** |              ////////////////|
** |              ////////////////|
** |______________________________|___________
*/
void test_flashWriteData_should_write_0_to_14_from_address_96_to_126_16(){
  int i, bytesWritten, data = 0;
  uint16 incomingData[16];
  *halfBuffer1 = 0;
  *halfBuffer2 = 0;
  *blockBuffer = 0;
   
  for(i = 0 ; i < 32 ; i++){
    blockBuffer[i] = 0xaabb;
  }
  for(i = 0 ; i < 16 ; i++){
    incomingData[i] = data;
    data++;
  }
  
  flashReadBlock_Expect(blockBuffer, 64, 2);
  rowErase_Expect(64);
  flashSetAddress_Expect(64);
  flashWriteBlock_Expect(halfBuffer1, halfBuffer2, 2);

  bytesWritten = flashWriteData(incomingData, 16, 96);
  
  TEST_ASSERT_EQUAL(0, halfBuffer2[0]);
  TEST_ASSERT_EQUAL(1, halfBuffer2[1]);
  TEST_ASSERT_EQUAL(2, halfBuffer2[2]);  
  TEST_ASSERT_EQUAL(3, halfBuffer2[3]);
  TEST_ASSERT_EQUAL(4, halfBuffer2[4]);
  TEST_ASSERT_EQUAL(5, halfBuffer2[5]);
  TEST_ASSERT_EQUAL(6, halfBuffer2[6]);
  TEST_ASSERT_EQUAL(7, halfBuffer2[7]);
  TEST_ASSERT_EQUAL(8, halfBuffer2[8]);
  TEST_ASSERT_EQUAL(9, halfBuffer2[9]);
  TEST_ASSERT_EQUAL(10, halfBuffer2[10]);
  TEST_ASSERT_EQUAL(11, halfBuffer2[11]);
  TEST_ASSERT_EQUAL(12, halfBuffer2[12]);
  TEST_ASSERT_EQUAL(13, halfBuffer2[13]);
  TEST_ASSERT_EQUAL(14, halfBuffer2[14]);
  TEST_ASSERT_EQUAL(15, halfBuffer2[15]);
  TEST_ASSERT_EQUAL(0xaabb, halfBuffer1[0]);
  TEST_ASSERT_EQUAL(16, bytesWritten);

}
