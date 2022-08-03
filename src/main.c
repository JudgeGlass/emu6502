#include <stdio.h>

#include "types.h"
#include "rom.h"


int main(){
    
    uint8_t hi = 0x80;
    uint8_t lo = 0xAA;
    uint16_t PC = 0;

    printf("PTR: 0x%x\n", ((hi << 8) | lo));

    initRom(&PC);


    return 0;
}