#include "Type.h"














  uint16 readPGD();

  void writePGD(int data);













  void PGC_high();

  void PGC_low();













  void MCLR_low();

  void MCLR_high();













  void PGM_low();

  void PGM_high();

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

void writeToBuffer(uint16 data);

void flashWriteAndProgram(uint16 data);

void flashWrite8Bits(uint8 data);

uint16 flashRead16Bits();

uint8 flashRead8Bits();

void flashWriteHalfBlock(uint16 *data, uint16 size, uint32 halfBlockNumber);

void flashWriteBlock(uint16 *firstHalf, uint16 *secondHalf, uint32 blockNumber);

void flashReadBlock(uint16 *data, uint16 size, uint32 blockNumber);

void rowErase(uint32 address);
