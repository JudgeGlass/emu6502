#include "mem.h"

void initMemory(){
    for(int i = 0; i < MEM_SIZE; i++){
        data[i] = 0;
    }
}