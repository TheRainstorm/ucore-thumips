#include <stdio.h>
#include <ulib.h>
#include <time.h>

int
main(void) {
    //使用clock获得时间
    cprintf("part1: test clock\n");
    size_t tik, tok;

    tik = clock();
    for(int i=0; i<1000000; i++){
        for(int j=0; j<1; j++){
            ;
        }
    }
    tok = clock();
    cprintf("spend time(ms): %d\n", (tok-tik)/CLOCKS_PER_MSEC);

    //倒计时10秒
    cprintf("part2: test sleep2\n");
    for(int i=0; i<11; i++){
        //wait 1s
        cprintf("%d!\n", 10-i);
        sleep2(1000);
    }
    return 0;
}