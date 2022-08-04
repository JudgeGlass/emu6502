#include "rom.h"


void printRom(){
    for(int i = 0; i < ROM_MAX; i++){
        printf("(%x)0x%x ", i, rom[i]);
        if(i % (0xF + 1) == 0) printf("\n");
    }
    printf("\n");
}

void initRom(uint16_t *PC){
    FILE *romBin = fopen("/home/judgeglass/Projects/emu6502/bin/EEPROM.bin", "rb");
    
    fread(rom, sizeof(rom), 1, romBin);

    uint8_t hi = rom[0xfffd - ROM_START];
    uint8_t lo = rom[0xfffc - ROM_START];

    *PC = ((hi << 8) | lo);
}