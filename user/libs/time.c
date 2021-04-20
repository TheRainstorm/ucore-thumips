#include <time.h>
#include <syscall.h>

clock_t clock(void){
    return (clock_t)sys_gettime_confreg();
}

void clock_reset(){
    sys_settime_confreg(0);
}

void sleep2(int t){
    clock_reset();
    while(clock()/(CLOCKS_PER_MSEC)!=t){
        ;
    }
}