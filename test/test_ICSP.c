#include "unity.h"
#include "ICSP.h"
#include "mock_flash.h"

void setUp(void){}
void tearDown(void){}

void test_write_ICSP_write_0x08_command_bit(){
  //command
  PGD_high_Expect();
  PGC_high_Expect();
  PGC_low_Expect();
  PGD_low_Expect();
  PGC_high_Expect();
  PGC_low_Expect();
  PGD_low_Expect();
  PGC_high_Expect();
  PGC_low_Expect();
  PGD_low_Expect();
  PGC_high_Expect();
  PGC_low_Expect();

  writeICSP(0x08, 4); 
}
