#include "mem.h"

void initMemory(uint16_t resetVecPtr){
    for(int i = 0; i < MEM_SIZE; i++){
        data[i] = 0;
    }

    uint8_t hi = resetVecPtr >> 8;
    uint8_t lo = resetVecPtr & 0x00FF;

    data[0xfffc] = lo;
    data[0xfffd] = hi;
}