#include <stdio.h>

int main(){
    int i = 0;
    while(i < 64){
        printf("Hello world! %d\n", i);
        usleep(100000);
        i++;
    }
    return 0;
}