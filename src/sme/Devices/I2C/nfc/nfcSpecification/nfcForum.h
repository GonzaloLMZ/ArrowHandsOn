/*
 * nfcForum.h
 *
 * Created: 3/23/2015 10:30:22 PM
 *  Author: smkk
 */ 



#ifndef NFCFORUM.H_H_
#define NFCFORUM.H_H_

#include <stdint-gcc.h>
#include <stdbool.h>

#include "ndefTypes.h"

#define NDEF_START_BYTE 0x03
#define NDEF_END_BYTE 	0xFE

typedef struct {
	uint8_t startByte;
	uint8_t payloadLength;
}NDEFHeaderStr;

#define BIT_MB (1<<7)
#define BIT_ME (1<<6)
#define BIT_CF (1<<5)
#define BIT_SR (1<<4)
#define BIT_IL (1<<3)
#define BIT_TNF (1<<0)
#define MASK_MB  0x80
#define MASK_ME  0x40
#define MASK_CF  0x20
#define MASK_SR  0x10
#define MASK_IL  0x08
#define MASK_TNF 0x07

typedef union {
	NDEFTextTypeStr text;
	NDEFUriTypeStr uri;
} NDEFTypeUnion;

typedef struct {
	uint8_t typeCode;
	NDEFTypeUnion typePayload;
}NDEFTypeStr;

typedef struct {
	uint8_t     header;
	uint8_t		typeLength;
	uint8_t		payloadLength;
	NDEFTypeStr type;
}NDEFRecordStr;

uint8_t composeNDEFText(uint8_t bodyLength, NDEFRecordStr *ndefRecord);
void composeNDEFMBME(bool isFirstRecord, bool isLastRecord, NDEFRecordStr *ndefRecord);

#endif /* NFCFORUM.H_H_ */x
