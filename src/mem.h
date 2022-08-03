#ifndef __MEM_H__
#define __MEM_H__

#include "types.h"

#define MEM_SIZE  64 * 1024 // 65536
uint8_t data[MEM_SIZE];


void initMemory(uint16_t resetVecPtr);

#endif