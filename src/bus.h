#ifndef __BUS_H__
#define __BUS_H__

#include "types.h"

#include "mem.h"
#include "rom.h"

#define RAM_START 0x0
#define RAM_END 0x3fff
#define VIA_START 0x6000
#define VIA_END 0x600f
#define ROM_START 0x8000
#define ROM_END 0xffff


void writeBus(uint16_t addr, uint8_t _data);
uint8_t readBus(uint16_t addr);

#endif