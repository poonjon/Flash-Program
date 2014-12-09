/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_ICSP_H
#define _MOCK_ICSP_H

#include "ICSP.h"
#include "CException.h"

void mock_ICSP_Init(void);
void mock_ICSP_Destroy(void);
void mock_ICSP_Verify(void);




#define writeICSP_Ignore() writeICSP_CMockIgnore()
void writeICSP_CMockIgnore(void);
#define writeICSP_Expect(commandByte, dataBytes) writeICSP_CMockExpect(__LINE__, commandByte, dataBytes)
void writeICSP_CMockExpect(UNITY_LINE_TYPE cmock_line, uint16 commandByte, uint16 dataBytes);
typedef void (* CMOCK_writeICSP_CALLBACK)(uint16 commandByte, uint16 dataBytes, int cmock_num_calls);
void writeICSP_StubWithCallback(CMOCK_writeICSP_CALLBACK Callback);
#define writeICSP_ExpectAndThrow(commandByte, dataBytes, cmock_to_throw) writeICSP_CMockExpectAndThrow(__LINE__, commandByte, dataBytes, cmock_to_throw)
void writeICSP_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, uint16 commandByte, uint16 dataBytes, CEXCEPTION_T cmock_to_throw);
#define writeBit_Ignore() writeBit_CMockIgnore()
void writeBit_CMockIgnore(void);
#define writeBit_Expect(bitToWrite) writeBit_CMockExpect(__LINE__, bitToWrite)
void writeBit_CMockExpect(UNITY_LINE_TYPE cmock_line, uint16 bitToWrite);
typedef void (* CMOCK_writeBit_CALLBACK)(uint16 bitToWrite, int cmock_num_calls);
void writeBit_StubWithCallback(CMOCK_writeBit_CALLBACK Callback);
#define writeBit_ExpectAndThrow(bitToWrite, cmock_to_throw) writeBit_CMockExpectAndThrow(__LINE__, bitToWrite, cmock_to_throw)
void writeBit_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, uint16 bitToWrite, CEXCEPTION_T cmock_to_throw);
#define writeBits_Ignore() writeBits_CMockIgnore()
void writeBits_CMockIgnore(void);
#define writeBits_Expect(pattern, bitsToWrite) writeBits_CMockExpect(__LINE__, pattern, bitsToWrite)
void writeBits_CMockExpect(UNITY_LINE_TYPE cmock_line, uint16 pattern, uint16 bitsToWrite);
typedef void (* CMOCK_writeBits_CALLBACK)(uint16 pattern, uint16 bitsToWrite, int cmock_num_calls);
void writeBits_StubWithCallback(CMOCK_writeBits_CALLBACK Callback);
#define writeBits_ExpectAndThrow(pattern, bitsToWrite, cmock_to_throw) writeBits_CMockExpectAndThrow(__LINE__, pattern, bitsToWrite, cmock_to_throw)
void writeBits_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, uint16 pattern, uint16 bitsToWrite, CEXCEPTION_T cmock_to_throw);
#define readICSP_IgnoreAndReturn(cmock_retval) readICSP_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void readICSP_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint16 cmock_to_return);
#define readICSP_ExpectAndReturn(cmock_retval) readICSP_CMockExpectAndReturn(__LINE__, cmock_retval)
void readICSP_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint16 cmock_to_return);
typedef uint16 (* CMOCK_readICSP_CALLBACK)(int cmock_num_calls);
void readICSP_StubWithCallback(CMOCK_readICSP_CALLBACK Callback);
#define readICSP_ExpectAndThrow(cmock_to_throw) readICSP_CMockExpectAndThrow(__LINE__, cmock_to_throw)
void readICSP_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, CEXCEPTION_T cmock_to_throw);
#define readFirstByte_IgnoreAndReturn(cmock_retval) readFirstByte_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void readFirstByte_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint16 cmock_to_return);
#define readFirstByte_ExpectAndReturn(cmock_retval) readFirstByte_CMockExpectAndReturn(__LINE__, cmock_retval)
void readFirstByte_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint16 cmock_to_return);
typedef uint16 (* CMOCK_readFirstByte_CALLBACK)(int cmock_num_calls);
void readFirstByte_StubWithCallback(CMOCK_readFirstByte_CALLBACK Callback);
#define readFirstByte_ExpectAndThrow(cmock_to_throw) readFirstByte_CMockExpectAndThrow(__LINE__, cmock_to_throw)
void readFirstByte_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, CEXCEPTION_T cmock_to_throw);
#define readBit_IgnoreAndReturn(cmock_retval) readBit_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void readBit_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint16 cmock_to_return);
#define readBit_ExpectAndReturn(cmock_retval) readBit_CMockExpectAndReturn(__LINE__, cmock_retval)
void readBit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint16 cmock_to_return);
typedef uint16 (* CMOCK_readBit_CALLBACK)(int cmock_num_calls);
void readBit_StubWithCallback(CMOCK_readBit_CALLBACK Callback);
#define readBit_ExpectAndThrow(cmock_to_throw) readBit_CMockExpectAndThrow(__LINE__, cmock_to_throw)
void readBit_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, CEXCEPTION_T cmock_to_throw);
#define readBits_IgnoreAndReturn(cmock_retval) readBits_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void readBits_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint16 cmock_to_return);
#define readBits_ExpectAndReturn(bitsToRead, cmock_retval) readBits_CMockExpectAndReturn(__LINE__, bitsToRead, cmock_retval)
void readBits_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int bitsToRead, uint16 cmock_to_return);
typedef uint16 (* CMOCK_readBits_CALLBACK)(int bitsToRead, int cmock_num_calls);
void readBits_StubWithCallback(CMOCK_readBits_CALLBACK Callback);
#define readBits_ExpectAndThrow(bitsToRead, cmock_to_throw) readBits_CMockExpectAndThrow(__LINE__, bitsToRead, cmock_to_throw)
void readBits_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, int bitsToRead, CEXCEPTION_T cmock_to_throw);

#endif