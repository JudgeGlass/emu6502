#include "cpu.h"

void cpuInit(){
    cpu.active = 1;
    initMemory();

    flags.IRQ_DISABLED = 1;
    flags.DECIMAL_MODE = 0;
    initRom(&cpu.PC);
    printf("Program Counter Start: 0x%x\n", cpu.PC);
    
}

void clock(){
    uint8_t op = readBus(cpu.PC);

    printf("OP: %x\n", op);

    
}

void execInstruction(uint8_t op){
    uint8_t cycles = 0;
    
    
    
}