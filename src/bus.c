/**
 * @file bus.c
 * @author Hunter Wilcox (hunter.wilcox@judgeglass.net)
 * @brief 
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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