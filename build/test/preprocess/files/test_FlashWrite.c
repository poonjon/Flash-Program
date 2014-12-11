#include "unity.h"
#include "p18f4520.h"
#include "mock_FlashProg.h"
#include "FlashWrite.h"


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



  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((overwriteBufferData(incomingData, 5, 2))), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x1234)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x5568)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x3265)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x4895)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xa568)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((overwriteBufferData(incomingData, 32, 0))), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((halfBuffer1[9])), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((halfBuffer1[10])), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((halfBuffer1[11])), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((halfBuffer1[12])), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((halfBuffer1[13])), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((halfBuffer2[0])), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((17)), (_U_SINT)((halfBuffer2[1])), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((18)), (_U_SINT)((halfBuffer2[2])), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((19)), (_U_SINT)((halfBuffer2[3])), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((halfBuffer2[4])), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((21)), (_U_SINT)((halfBuffer2[5])), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((halfBuffer2[6])), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((23)), (_U_SINT)((halfBuffer2[7])), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((24)), (_U_SINT)((halfBuffer2[8])), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((25)), (_U_SINT)((halfBuffer2[9])), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((26)), (_U_SINT)((halfBuffer2[10])), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((27)), (_U_SINT)((halfBuffer2[11])), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((28)), (_U_SINT)((halfBuffer2[12])), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((29)), (_U_SINT)((halfBuffer2[13])), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((halfBuffer2[14])), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((31)), (_U_SINT)((halfBuffer2[15])), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);



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



  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((overwriteBufferData(incomingData, 40, 0))), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((halfBuffer1[9])), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((halfBuffer1[10])), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((halfBuffer1[11])), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((halfBuffer1[12])), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((halfBuffer1[13])), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((halfBuffer2[0])), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((17)), (_U_SINT)((halfBuffer2[1])), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((18)), (_U_SINT)((halfBuffer2[2])), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((19)), (_U_SINT)((halfBuffer2[3])), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((halfBuffer2[4])), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((21)), (_U_SINT)((halfBuffer2[5])), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((halfBuffer2[6])), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((23)), (_U_SINT)((halfBuffer2[7])), (((void *)0)), (_U_UINT)128, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((24)), (_U_SINT)((halfBuffer2[8])), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((25)), (_U_SINT)((halfBuffer2[9])), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((26)), (_U_SINT)((halfBuffer2[10])), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((27)), (_U_SINT)((halfBuffer2[11])), (((void *)0)), (_U_UINT)132, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((28)), (_U_SINT)((halfBuffer2[12])), (((void *)0)), (_U_UINT)133, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((29)), (_U_SINT)((halfBuffer2[13])), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((halfBuffer2[14])), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((31)), (_U_SINT)((halfBuffer2[15])), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_INT);



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



  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((overwriteBufferData(incomingData, 6, 15))), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[13])), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer2[0])), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer2[1])), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer2[2])), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer2[3])), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer2[4])), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer2[5])), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer2[6])), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer2[7])), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);



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



  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((overwriteBufferData(incomingData, 10, 28))), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer2[15])), (((void *)0)), (_U_UINT)186, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer2[14])), (((void *)0)), (_U_UINT)187, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer2[13])), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer2[12])), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);



}















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

  flashReadBlock_CMockExpect(213, blockBuffer, 64, 1);



  rowErase_CMockExpect(215, 0x000000);

  flashSetAddress_CMockExpect(216, 0);

  flashWriteBlock_CMockExpect(217, halfBuffer1, halfBuffer2, 1);



  bytesWritten = flashWriteData(incomingData, 3, 4);



  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x1234)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x5445)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x6677)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)225, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)227, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);

}















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

  flashReadBlock_CMockExpect(251, blockBuffer, 64, 1);



  rowErase_CMockExpect(253, 0x000000);

  flashSetAddress_CMockExpect(254, 0);

  flashWriteBlock_CMockExpect(255, halfBuffer1, halfBuffer2, 1);



  bytesWritten = flashWriteData(incomingData, 9, 14);



  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)260, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer1[9])), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer1[10])), (((void *)0)), (_U_UINT)265, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer1[11])), (((void *)0)), (_U_UINT)266, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer1[12])), (((void *)0)), (_U_UINT)267, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((halfBuffer1[13])), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)269, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)270, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_INT);

}















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

  flashReadBlock_CMockExpect(294, blockBuffer, 64, 1);



  rowErase_CMockExpect(296, 0x000000);

  flashSetAddress_CMockExpect(297, 0);

  flashWriteBlock_CMockExpect(298, halfBuffer1, halfBuffer2, 1);



  bytesWritten = flashWriteData(incomingData, 16, 0);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)302, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)303, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)304, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)305, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)306, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)307, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)308, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)309, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((halfBuffer1[9])), (((void *)0)), (_U_UINT)311, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((halfBuffer1[10])), (((void *)0)), (_U_UINT)312, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((halfBuffer1[11])), (((void *)0)), (_U_UINT)313, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((halfBuffer1[12])), (((void *)0)), (_U_UINT)314, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((halfBuffer1[13])), (((void *)0)), (_U_UINT)315, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)316, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)317, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)318, UNITY_DISPLAY_STYLE_INT);

}















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

  flashReadBlock_CMockExpect(341, blockBuffer, 64, 1);



  rowErase_CMockExpect(343, 0x000000);

  flashSetAddress_CMockExpect(344, 0);

  flashWriteBlock_CMockExpect(345, halfBuffer1, halfBuffer2, 1);



  bytesWritten = flashWriteData(incomingData, 8, 28);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)349, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer2[0])), (((void *)0)), (_U_UINT)351, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer2[1])), (((void *)0)), (_U_UINT)352, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer2[2])), (((void *)0)), (_U_UINT)353, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer2[3])), (((void *)0)), (_U_UINT)354, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((halfBuffer2[4])), (((void *)0)), (_U_UINT)355, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((halfBuffer2[5])), (((void *)0)), (_U_UINT)356, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer2[7])), (((void *)0)), (_U_UINT)357, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer2[8])), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)359, UNITY_DISPLAY_STYLE_INT);

}















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

  flashReadBlock_CMockExpect(382, blockBuffer, 64, 2);



  rowErase_CMockExpect(384, 64);

  flashSetAddress_CMockExpect(385, 64);

  flashWriteBlock_CMockExpect(386, halfBuffer1, halfBuffer2, 2);

  bytesWritten = flashWriteData(incomingData, 11, 66);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)390, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)392, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)393, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)394, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)395, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)396, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((halfBuffer1[9])), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((halfBuffer1[10])), (((void *)0)), (_U_UINT)398, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((halfBuffer1[11])), (((void *)0)), (_U_UINT)399, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)400, UNITY_DISPLAY_STYLE_INT);

}















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

  flashReadBlock_CMockExpect(423, blockBuffer, 64, 1);



  rowErase_CMockExpect(425, 0x000000);

  flashSetAddress_CMockExpect(426, 0);

  flashWriteBlock_CMockExpect(427, halfBuffer1, halfBuffer2, 1);



  bytesWritten = flashWriteData(incomingData, 32, 0);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)431, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)432, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)433, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)434, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)435, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)436, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)437, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)438, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)439, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((halfBuffer1[9])), (((void *)0)), (_U_UINT)440, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((halfBuffer1[10])), (((void *)0)), (_U_UINT)441, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((halfBuffer1[11])), (((void *)0)), (_U_UINT)442, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((halfBuffer1[12])), (((void *)0)), (_U_UINT)443, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((halfBuffer1[13])), (((void *)0)), (_U_UINT)444, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)445, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)446, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((halfBuffer2[0])), (((void *)0)), (_U_UINT)447, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((17)), (_U_SINT)((halfBuffer2[1])), (((void *)0)), (_U_UINT)448, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((18)), (_U_SINT)((halfBuffer2[2])), (((void *)0)), (_U_UINT)449, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((19)), (_U_SINT)((halfBuffer2[3])), (((void *)0)), (_U_UINT)450, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((halfBuffer2[4])), (((void *)0)), (_U_UINT)451, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((21)), (_U_SINT)((halfBuffer2[5])), (((void *)0)), (_U_UINT)452, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((halfBuffer2[6])), (((void *)0)), (_U_UINT)453, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((23)), (_U_SINT)((halfBuffer2[7])), (((void *)0)), (_U_UINT)454, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((24)), (_U_SINT)((halfBuffer2[8])), (((void *)0)), (_U_UINT)455, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((25)), (_U_SINT)((halfBuffer2[9])), (((void *)0)), (_U_UINT)456, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((26)), (_U_SINT)((halfBuffer2[10])), (((void *)0)), (_U_UINT)457, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((27)), (_U_SINT)((halfBuffer2[11])), (((void *)0)), (_U_UINT)458, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((28)), (_U_SINT)((halfBuffer2[12])), (((void *)0)), (_U_UINT)459, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((29)), (_U_SINT)((halfBuffer2[13])), (((void *)0)), (_U_UINT)460, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((halfBuffer2[14])), (((void *)0)), (_U_UINT)461, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((31)), (_U_SINT)((halfBuffer2[15])), (((void *)0)), (_U_UINT)462, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)463, UNITY_DISPLAY_STYLE_INT);

}















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

  flashReadBlock_CMockExpect(486, blockBuffer, 64, 1);

  rowErase_CMockExpect(487, 0x000000);

  flashSetAddress_CMockExpect(488, 0);

  flashWriteBlock_CMockExpect(489, halfBuffer1, halfBuffer2, 1);



  flashReadBlock_CMockExpect(491, blockBuffer, 64, 2);

  rowErase_CMockExpect(492, 64);

  flashSetAddress_CMockExpect(493, 64);

  flashWriteBlock_CMockExpect(494, halfBuffer1, halfBuffer2, 2);

  bytesWritten = flashWriteData(incomingData, 35, 0);



  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)497, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((33)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)498, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((34)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)499, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((35)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)500, UNITY_DISPLAY_STYLE_INT);

}















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

  flashReadBlock_CMockExpect(523, blockBuffer, 64, 1);

  rowErase_CMockExpect(524, 0x000000);

  flashSetAddress_CMockExpect(525, 0);

  flashWriteBlock_CMockExpect(526, halfBuffer1, halfBuffer2, 1);



  flashReadBlock_CMockExpect(528, blockBuffer, 64, 2);

  rowErase_CMockExpect(529, 64);

  flashSetAddress_CMockExpect(530, 64);

  flashWriteBlock_CMockExpect(531, halfBuffer1, halfBuffer2, 2);

  bytesWritten = flashWriteData(incomingData, 64, 0);



  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)534, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((33)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)535, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((34)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)536, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((35)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)537, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((36)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)538, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((37)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)539, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((38)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)540, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((39)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)541, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)542, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((41)), (_U_SINT)((halfBuffer1[9])), (((void *)0)), (_U_UINT)543, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((42)), (_U_SINT)((halfBuffer1[10])), (((void *)0)), (_U_UINT)544, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((43)), (_U_SINT)((halfBuffer1[11])), (((void *)0)), (_U_UINT)545, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((44)), (_U_SINT)((halfBuffer1[12])), (((void *)0)), (_U_UINT)546, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((45)), (_U_SINT)((halfBuffer1[13])), (((void *)0)), (_U_UINT)547, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)548, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((47)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)549, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((48)), (_U_SINT)((halfBuffer2[0])), (((void *)0)), (_U_UINT)550, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((49)), (_U_SINT)((halfBuffer2[1])), (((void *)0)), (_U_UINT)551, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((halfBuffer2[2])), (((void *)0)), (_U_UINT)552, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((51)), (_U_SINT)((halfBuffer2[3])), (((void *)0)), (_U_UINT)553, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((52)), (_U_SINT)((halfBuffer2[4])), (((void *)0)), (_U_UINT)554, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((53)), (_U_SINT)((halfBuffer2[5])), (((void *)0)), (_U_UINT)555, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((54)), (_U_SINT)((halfBuffer2[6])), (((void *)0)), (_U_UINT)556, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((55)), (_U_SINT)((halfBuffer2[7])), (((void *)0)), (_U_UINT)557, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((56)), (_U_SINT)((halfBuffer2[8])), (((void *)0)), (_U_UINT)558, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((57)), (_U_SINT)((halfBuffer2[9])), (((void *)0)), (_U_UINT)559, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((58)), (_U_SINT)((halfBuffer2[10])), (((void *)0)), (_U_UINT)560, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((59)), (_U_SINT)((halfBuffer2[11])), (((void *)0)), (_U_UINT)561, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((halfBuffer2[12])), (((void *)0)), (_U_UINT)562, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((61)), (_U_SINT)((halfBuffer2[13])), (((void *)0)), (_U_UINT)563, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((62)), (_U_SINT)((halfBuffer2[14])), (((void *)0)), (_U_UINT)564, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((63)), (_U_SINT)((halfBuffer2[15])), (((void *)0)), (_U_UINT)565, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((64)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)566, UNITY_DISPLAY_STYLE_INT);

}















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



  flashReadBlock_CMockExpect(590, blockBuffer, 64, 1);

  rowErase_CMockExpect(591, 0x000000);

  flashSetAddress_CMockExpect(592, 0);

  flashWriteBlock_CMockExpect(593, halfBuffer1, halfBuffer2, 1);



  flashReadBlock_CMockExpect(595, blockBuffer, 64, 2);

  rowErase_CMockExpect(596, 64);

  flashSetAddress_CMockExpect(597, 64);

  flashWriteBlock_CMockExpect(598, halfBuffer1, halfBuffer2, 2);



  bytesWritten = flashWriteData(incomingData, 34, 60);



  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)602, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)603, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)604, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)605, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)606, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)607, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)608, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)609, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)610, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((halfBuffer1[9])), (((void *)0)), (_U_UINT)611, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((halfBuffer1[10])), (((void *)0)), (_U_UINT)612, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((halfBuffer1[11])), (((void *)0)), (_U_UINT)613, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((halfBuffer1[12])), (((void *)0)), (_U_UINT)614, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((halfBuffer1[13])), (((void *)0)), (_U_UINT)615, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)616, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((17)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)617, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((18)), (_U_SINT)((halfBuffer2[0])), (((void *)0)), (_U_UINT)618, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((19)), (_U_SINT)((halfBuffer2[1])), (((void *)0)), (_U_UINT)619, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((halfBuffer2[2])), (((void *)0)), (_U_UINT)620, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((21)), (_U_SINT)((halfBuffer2[3])), (((void *)0)), (_U_UINT)621, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((22)), (_U_SINT)((halfBuffer2[4])), (((void *)0)), (_U_UINT)622, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((23)), (_U_SINT)((halfBuffer2[5])), (((void *)0)), (_U_UINT)623, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((24)), (_U_SINT)((halfBuffer2[6])), (((void *)0)), (_U_UINT)624, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((25)), (_U_SINT)((halfBuffer2[7])), (((void *)0)), (_U_UINT)625, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((26)), (_U_SINT)((halfBuffer2[8])), (((void *)0)), (_U_UINT)626, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((27)), (_U_SINT)((halfBuffer2[9])), (((void *)0)), (_U_UINT)627, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((28)), (_U_SINT)((halfBuffer2[10])), (((void *)0)), (_U_UINT)628, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((29)), (_U_SINT)((halfBuffer2[11])), (((void *)0)), (_U_UINT)629, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((halfBuffer2[12])), (((void *)0)), (_U_UINT)630, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((31)), (_U_SINT)((halfBuffer2[13])), (((void *)0)), (_U_UINT)631, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((halfBuffer2[14])), (((void *)0)), (_U_UINT)632, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((33)), (_U_SINT)((halfBuffer2[15])), (((void *)0)), (_U_UINT)633, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((34)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)634, UNITY_DISPLAY_STYLE_INT);

}















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



  flashReadBlock_CMockExpect(658, blockBuffer, 64, 1);

  rowErase_CMockExpect(659, 0x000000);

  flashSetAddress_CMockExpect(660, 0);

  flashWriteBlock_CMockExpect(661, halfBuffer1, halfBuffer2, 1);



  flashReadBlock_CMockExpect(663, blockBuffer, 64, 2);

  rowErase_CMockExpect(664, 64);

  flashSetAddress_CMockExpect(665, 64);

  flashWriteBlock_CMockExpect(666, halfBuffer1, halfBuffer2, 2);



  flashReadBlock_CMockExpect(668, blockBuffer, 64, 3);

  rowErase_CMockExpect(669, 128);

  flashSetAddress_CMockExpect(670, 128);

  flashWriteBlock_CMockExpect(671, halfBuffer1, halfBuffer2, 3);



  bytesWritten = flashWriteData(incomingData, 96, 0);



  UnityAssertEqualNumber((_U_SINT)((64)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)675, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((65)), (_U_SINT)((halfBuffer1[1])), (((void *)0)), (_U_UINT)676, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((66)), (_U_SINT)((halfBuffer1[2])), (((void *)0)), (_U_UINT)677, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((67)), (_U_SINT)((halfBuffer1[3])), (((void *)0)), (_U_UINT)678, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((68)), (_U_SINT)((halfBuffer1[4])), (((void *)0)), (_U_UINT)679, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((69)), (_U_SINT)((halfBuffer1[5])), (((void *)0)), (_U_UINT)680, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((halfBuffer1[6])), (((void *)0)), (_U_UINT)681, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((71)), (_U_SINT)((halfBuffer1[7])), (((void *)0)), (_U_UINT)682, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((72)), (_U_SINT)((halfBuffer1[8])), (((void *)0)), (_U_UINT)683, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((73)), (_U_SINT)((halfBuffer1[9])), (((void *)0)), (_U_UINT)684, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((74)), (_U_SINT)((halfBuffer1[10])), (((void *)0)), (_U_UINT)685, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((75)), (_U_SINT)((halfBuffer1[11])), (((void *)0)), (_U_UINT)686, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((76)), (_U_SINT)((halfBuffer1[12])), (((void *)0)), (_U_UINT)687, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((77)), (_U_SINT)((halfBuffer1[13])), (((void *)0)), (_U_UINT)688, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((78)), (_U_SINT)((halfBuffer1[14])), (((void *)0)), (_U_UINT)689, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((79)), (_U_SINT)((halfBuffer1[15])), (((void *)0)), (_U_UINT)690, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((halfBuffer2[0])), (((void *)0)), (_U_UINT)691, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((81)), (_U_SINT)((halfBuffer2[1])), (((void *)0)), (_U_UINT)692, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((82)), (_U_SINT)((halfBuffer2[2])), (((void *)0)), (_U_UINT)693, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((83)), (_U_SINT)((halfBuffer2[3])), (((void *)0)), (_U_UINT)694, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((84)), (_U_SINT)((halfBuffer2[4])), (((void *)0)), (_U_UINT)695, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((85)), (_U_SINT)((halfBuffer2[5])), (((void *)0)), (_U_UINT)696, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((86)), (_U_SINT)((halfBuffer2[6])), (((void *)0)), (_U_UINT)697, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((87)), (_U_SINT)((halfBuffer2[7])), (((void *)0)), (_U_UINT)698, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((88)), (_U_SINT)((halfBuffer2[8])), (((void *)0)), (_U_UINT)699, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((89)), (_U_SINT)((halfBuffer2[9])), (((void *)0)), (_U_UINT)700, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((halfBuffer2[10])), (((void *)0)), (_U_UINT)701, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((91)), (_U_SINT)((halfBuffer2[11])), (((void *)0)), (_U_UINT)702, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((92)), (_U_SINT)((halfBuffer2[12])), (((void *)0)), (_U_UINT)703, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((93)), (_U_SINT)((halfBuffer2[13])), (((void *)0)), (_U_UINT)704, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((94)), (_U_SINT)((halfBuffer2[14])), (((void *)0)), (_U_UINT)705, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((95)), (_U_SINT)((halfBuffer2[15])), (((void *)0)), (_U_UINT)706, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((96)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)707, UNITY_DISPLAY_STYLE_INT);

}















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



  flashReadBlock_CMockExpect(731, blockBuffer, 64, 2);

  rowErase_CMockExpect(732, 64);

  flashSetAddress_CMockExpect(733, 64);

  flashWriteBlock_CMockExpect(734, halfBuffer1, halfBuffer2, 2);



  bytesWritten = flashWriteData(incomingData, 16, 96);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((halfBuffer2[0])), (((void *)0)), (_U_UINT)738, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((halfBuffer2[1])), (((void *)0)), (_U_UINT)739, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((halfBuffer2[2])), (((void *)0)), (_U_UINT)740, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((halfBuffer2[3])), (((void *)0)), (_U_UINT)741, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((halfBuffer2[4])), (((void *)0)), (_U_UINT)742, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((halfBuffer2[5])), (((void *)0)), (_U_UINT)743, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((halfBuffer2[6])), (((void *)0)), (_U_UINT)744, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((halfBuffer2[7])), (((void *)0)), (_U_UINT)745, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((halfBuffer2[8])), (((void *)0)), (_U_UINT)746, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((halfBuffer2[9])), (((void *)0)), (_U_UINT)747, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((halfBuffer2[10])), (((void *)0)), (_U_UINT)748, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((halfBuffer2[11])), (((void *)0)), (_U_UINT)749, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((halfBuffer2[12])), (((void *)0)), (_U_UINT)750, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((halfBuffer2[13])), (((void *)0)), (_U_UINT)751, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((halfBuffer2[14])), (((void *)0)), (_U_UINT)752, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((halfBuffer2[15])), (((void *)0)), (_U_UINT)753, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xaabb)), (_U_SINT)((halfBuffer1[0])), (((void *)0)), (_U_UINT)754, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((bytesWritten)), (((void *)0)), (_U_UINT)755, UNITY_DISPLAY_STYLE_INT);



}
