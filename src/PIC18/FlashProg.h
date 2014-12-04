#ifndef FlashProg_H
#define FlashProg_H
#include "Type.h"


#if defined PIC1C8 || X8
  #define readPGD() (_PGD)
  #define writePGD(x) (_PGD = x)
#else
  uint16 readPGD();
  void writePGD(int data);
#endif

#if defined PIC1C8 || X8
  #define PGC_high() (_PGC)
  #define PGC_low() (_PGC)
#else
  void PGC_high();
  void PGC_low();
#endif

#if defined PIC1C8 || X8
  #define MCLR_low() (_MCLR)
  #define MCLR_high() (_MCLR)
#else
  void MCLR_low();
  void MCLR_high();
#endif

#if defined PIC1C8 || X8
  #define PGM_low() (_PGM)
  #define PGM_high() (_PGM)
#else
  void PGM_low();
  void PGM_high();
#endif

#define PIN_LOW 0
#define PIN_HIGH 1
#define _PGD PORTDbits.RD4
#define _PGC PORTDbits.RD5
#define _PGM PORTDbits.RD6
#define _MCLR PORTDbits.RD7
#define setICSPDataPinAsInput (TRISDbits.TRISD4 = 1)
#define setICSPDataPinAsOutput (TRISDbits.TRISD4 = 0)
#define defaultTable flashSetAddress(0x00, 0x00, 0x00)

uint16 readPGD();
void writePGD(int data);
void PGC_high();
void PGC_low();
void PGD_high();
void PGD_low();
void PGM_high();
void PGM_low();
void MCLR_low();
void MCLR_high();
void enter_HVP();
void exit_HVP();
void bulkErase();
void readDeviceID1();
void readDeviceID2();
void enableWrite();
void flashSetAddress(uint32 address);
void flashWriteAndProgram(uint32 data);
void flashWrite8Bits(uint8 data);
uint16 flashRead16Bits();
uint8 flashRead8Bits();
int flashWriteBlock(uint8 *data, uint16 size, uint32 address);
int flashReadData(uint8 *data, uint16 size, uint32 address);
int memRange(uint32 address);
void rowErase(uint32 address);
void flashWriteData(uint32 data);
#endif // FlashProg_H
