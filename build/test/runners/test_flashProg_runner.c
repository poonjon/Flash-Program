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
#include "mock_ICSP.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_PGD_high(void);
extern void test_PGD_low(void);
extern void test_PGC_high(void);
extern void test_PGC_low(void);
extern void test_enter_HVP(void);
extern void test_exit_HVP(void);
extern void test_MCLR_low(void);
extern void test_MCLR_high(void);
extern void test_PGM_high(void);
extern void test_PGM_low(void);
extern void test_enableWrite(void);
extern void test_flashSetAddress_should_select_0x102030(void);
extern void test_flashWriteToBuffer_2bytes_of_data(void);
extern void test_flashWriteAndProgram_2bytes_of_data(void);
extern void test_flashRead16Bits_should_read_2bytes_and_return_0x1001(void);
extern void test_flashReadBlock_should_read_64bits(void);
extern void test_flashWriteBlock_should_write(void);
extern void test_rowErase_should_erase_row(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_ICSP_Init();
}
static void CMock_Verify(void)
{
  mock_ICSP_Verify();
}
static void CMock_Destroy(void)
{
  mock_ICSP_Destroy();
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
  Unity.TestFile = "test_flashProg.c";
  UnityBegin();
  RUN_TEST(test_PGD_high, 54);
  RUN_TEST(test_PGD_low, 60);
  RUN_TEST(test_PGC_high, 66);
  RUN_TEST(test_PGC_low, 72);
  RUN_TEST(test_enter_HVP, 78);
  RUN_TEST(test_exit_HVP, 87);
  RUN_TEST(test_MCLR_low, 102);
  RUN_TEST(test_MCLR_high, 109);
  RUN_TEST(test_PGM_high, 116);
  RUN_TEST(test_PGM_low, 123);
  RUN_TEST(test_enableWrite, 130);
  RUN_TEST(test_flashSetAddress_should_select_0x102030, 136);
  RUN_TEST(test_flashWriteToBuffer_2bytes_of_data, 148);
  RUN_TEST(test_flashWriteAndProgram_2bytes_of_data, 155);
  RUN_TEST(test_flashRead16Bits_should_read_2bytes_and_return_0x1001, 164);
  RUN_TEST(test_flashReadBlock_should_read_64bits, 174);
  RUN_TEST(test_flashWriteBlock_should_write, 185);
  RUN_TEST(test_rowErase_should_erase_row, 203);

  return (UnityEnd());
}
