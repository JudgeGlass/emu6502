#include "bus.h"

void writeBus(uint16_t addr, uint8_t _data){
    if(addr <= RAM_END && addr >= RAM_START){
        data[addr] = _data;
    }

    if(addr <= ROM_END && addr >= ROM_START){
        rom[addr - ROM_START] = _data;
    }
}

uint8_t readBus(uint16_t addr){
    if(addr <= RAM_END && addr >= RAM_START){
        return data[addr];
    }

    if(addr <= ROM_END && addr >= ROM_START){
        return rom[addr - ROM_START];
    }

    return 0x00;
}