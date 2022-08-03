#include <stdio.h>

#include "types.h"


int main(){
    
    uint16_t addr = 0x8000;

    printf("High byte: 0x%x\n", (addr >> 8));
    printf("Low byte: 0x%x\n", (addr & 0x00FF));

    return 0;
}