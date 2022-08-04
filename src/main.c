#include <stdio.h>

#include "cpu.h"


int main(){


    cpuInit();
    while(cpu.active){
        clock();
    }
    


    return 0;
}