#ifndef __ROM_H__
#define __ROM_H__

#include <stdio.h>
#include "types.h"
#include "bus.h"

#define ROM_MAX 0x8000
uint8_t rom[ROM_MAX];

void printRom();
void initRom(uint16_t *PC);


#endif