/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      CMock_Init(); \
      setUp(); \
      TestFunc(); \
      CMock_Verify(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  CMock_Destroy(); \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"
#include "mock_FlashProg.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_overwriteBufferData_should_overwrite_array_2_to_6(void);
extern void test_overwriteBufferData_should_overwrite_array_0_to_32(void);
extern void test_overwriteBufferData_should_overwrite_array_0_to_32_and_overflow(void);
extern void test_overwriteBufferData_should_overwrite_array_15_to_21(void);
extern void test_overwriteBufferData_should_overwrite_array_28_to_32_and_overflow(void);
extern void test_flashWriteData_should_write_data_from_address_4_to_8_should_return_3(void);
extern void test_flashWriteData_should_write_0_to_8_from_address_14_to_30_should_return_9(void);
extern void test_flashWriteData_should_write_0_to_15_from_address_0_to_30_should_return_16(void);
extern void test_flashWriteData_should_write_0_to_7_from_address_28_to_42_should_return_8(void);
extern void test_flashWriteData_should_write_0_to_10_from_address_66_to_88_should_return_11(void);
extern void test_flashWriteData_should_write_0_to_31_from_address_0_to_62_should_return_32(void);
extern void test_flashWriteData_should_write_0_to_31_from_address_0_to_68_should_return_35(void);
extern void test_flashWriteData_should_write_0_to_63_from_address_0_to_126_should_return_64(void);
extern void test_flashWriteData_should_write_0_to_33_from_address_60_to_126_should_return_34(void);
extern void test_flashWriteData_should_write_0_to_95_from_address_0_to_192_should_return_96(void);
extern void test_flashWriteData_should_write_0_to_14_from_address_96_to_126_16(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_FlashProg_Init();
}
static void CMock_Verify(void)
{
  mock_FlashProg_Verify();
}
static void CMock_Destroy(void)
{
  mock_FlashProg_Destroy();
}

//=======Test Reset Option=====
void resetTest()
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_FlashWrite.c";
  UnityBegin();
  RUN_TEST(test_overwriteBufferData_should_overwrite_array_2_to_6, 9);
  RUN_TEST(test_overwriteBufferData_should_overwrite_array_0_to_32, 38);
  RUN_TEST(test_overwriteBufferData_should_overwrite_array_0_to_32_and_overflow, 89);
  RUN_TEST(test_overwriteBufferData_should_overwrite_array_15_to_21, 140);
  RUN_TEST(test_overwriteBufferData_should_overwrite_array_28_to_32_and_overflow, 170);
  RUN_TEST(test_flashWriteData_should_write_data_from_address_4_to_8_should_return_3, 199);
  RUN_TEST(test_flashWriteData_should_write_0_to_8_from_address_14_to_30_should_return_9, 237);
  RUN_TEST(test_flashWriteData_should_write_0_to_15_from_address_0_to_30_should_return_16, 280);
  RUN_TEST(test_flashWriteData_should_write_0_to_7_from_address_28_to_42_should_return_8, 327);
  RUN_TEST(test_flashWriteData_should_write_0_to_10_from_address_66_to_88_should_return_11, 368);
  RUN_TEST(test_flashWriteData_should_write_0_to_31_from_address_0_to_62_should_return_32, 409);
  RUN_TEST(test_flashWriteData_should_write_0_to_31_from_address_0_to_68_should_return_35, 472);
  RUN_TEST(test_flashWriteData_should_write_0_to_63_from_address_0_to_126_should_return_64, 509);
  RUN_TEST(test_flashWriteData_should_write_0_to_33_from_address_60_to_126_should_return_34, 575);
  RUN_TEST(test_flashWriteData_should_write_0_to_95_from_address_0_to_192_should_return_96, 643);
  RUN_TEST(test_flashWriteData_should_write_0_to_14_from_address_96_to_126_16, 716);

  return (UnityEnd());
}
