#include "rom.h"

void initRom(uint16_t resetVecPtr){
    FILE *romBin = fopen("EEPROM.bin", "rb");

    fread(rom, sizeof(rom), 1, romBin);

    uint8_t hi = resetVecPtr >> 8;
    uint8_t lo = resetVecPtr & 0x00FF;

    rom[0xfffc] = lo;
    rom[0xfffd] = hi;
}