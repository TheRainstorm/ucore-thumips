#include <stdio.h>
#include <ulib.h>
#include <gpio.h>
#include <time.h>

int
main(void) {
    printf("Test begin\n");

    printf("Test timer: sleep 1s\n");
    sleep2(1000);       //sleep2 use sys_pread
    printf("Test timer end\n");

    printf("Test LED: blink interleaved\n");
    for(int i=0; i<10; i++){
        pwrite(LED_RG0_ADDR, i%4);
        pwrite(LED_RG1_ADDR, 3 - i%4);
        pwrite(LED_ADDR, i%2 ? 0x5555 : 0xaaaa);
        sleep2(200);
    }
    printf("Test LED end\n");

    printf("Test 7-segment displays: write *Switch* value\n");
    pwrite(NUM_ADDR, pread(SWITCH_ADDR));
    printf("Test 7-segment displays end\n");

    printf("Test end\n");

    return 0;
}