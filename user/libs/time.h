#ifndef __LIBS_TIME_H__
#define __LIBS_TIME_H__
#include <defs.h>

#define CLOCKS_PER_SEC 33000000
#define CLOCKS_PER_MSEC 33000

typedef unsigned int clock_t;
clock_t clock();    //获得板子上的timer计数器的值, CLOCKS_PER_SEC表示了其增加速度
                    //原本的gettime_msec函数：内核通过时钟中断（通过CP0_counter和CP0_compare产生）维护一个全局变量，该变量每1/1000s加一。本函数返回该变量值
void clock_reset(); //将板子上的timer清0

void sleep2(int t); //等待t毫秒，通过循环等待clock的值实现。
                    //ulib.c中的sleep函数会进行sleep系统调用，内核将当前进程设置为SLEEPING状态，并添加一个时钟中断事件。
#endif