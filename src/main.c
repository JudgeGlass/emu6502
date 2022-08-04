/**
 * @file main.c
 * @author Hunter Wilcox (Hunter Wilcox)
 * @brief This is an emulator based on Ben Eater's 6502 computer, but with the addition of a TI 83+ display.
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#include "cpu.h"


int main(){


    cpuInit();
    while(cpu.active){
        clock();
    }
    


    return 0;
}