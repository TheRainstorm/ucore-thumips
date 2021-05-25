#include <stdio.h>
#include <stdlib.h>
#include <ulib.h>
#include <time.h>

#include <gpio.h>


int
main(void) {
    printf("Test begin\n");

    printf("Test LED: blink interleaved\n");
    for(int i=0; i<10; i++){
        // pwrite(LED_RG0_ADDR, i%4);
        // pwrite(LED_RG1_ADDR, 3 - i%4);
        pwrite(LED_ADDR, i%2 ? 0x5555 : 0xaaaa);
        sleep2(200);
    }
    pwrite(LED_ADDR, 0);
    printf("Test LED end\n");

    printf("Test 7-segment displays: write *Switch* value\n");
    int num;
    for(int i=0; i<100; i++){
        num = pread(SWITCH_ADDR);
        if(num==0){
            break;
        }
        pwrite(NUM_ADDR, num);
        sleep2(100);
    }
    pwrite(NUM_ADDR, 0);
    printf("Test 7-segment displays end\n");

    printf("Test end\n");

    return 0;
}