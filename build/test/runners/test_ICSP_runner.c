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
extern void test_write_bit_1(void);
extern void test_write_bit_0(void);
extern void test_write_bits_0x50(void);
extern void test_write_bits_0xf9(void);
extern void test_write_bits_0x3c40(void);
extern void test_writeICSP_write_0xd_command_0x3c40_data(void);
extern void test_readBit_should_return_1(void);
extern void test_readBit_should_return_0(void);
extern void test_readBits_should_return_0x11(void);
extern void test_readBits_should_return_0xf6(void);
extern void test_readBits_should_return_0x35f6(void);
extern void test_readICSP_should_read_0x34(void);


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
  Unity.TestFile = "test_ICSP.c";
  UnityBegin();
  RUN_TEST(test_write_bit_1, 36);
  RUN_TEST(test_write_bit_0, 44);
  RUN_TEST(test_write_bits_0x50, 52);
  RUN_TEST(test_write_bits_0xf9, 57);
  RUN_TEST(test_write_bits_0x3c40, 62);
  RUN_TEST(test_writeICSP_write_0xd_command_0x3c40_data, 67);
  RUN_TEST(test_readBit_should_return_1, 75);
  RUN_TEST(test_readBit_should_return_0, 84);
  RUN_TEST(test_readBits_should_return_0x11, 93);
  RUN_TEST(test_readBits_should_return_0xf6, 99);
  RUN_TEST(test_readBits_should_return_0x35f6, 106);
  RUN_TEST(test_readICSP_should_read_0x34, 113);

  return (UnityEnd());
}
