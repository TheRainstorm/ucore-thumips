#include <stdio.h>
#include <ulib.h>

int
main(void) {
    unsigned int tik, tok;
    
    tik = gettime_msec();
    cprintf("tik: %d\n", tik);
    for(int j=0; j<10; j++){
        for(int i=0; i<10000; i++){
            for(int i=0; i<10000; i++){
                ;
            }
        }
        tok = gettime_msec();
        cprintf("tok: %d\n", tok);
    }

    cprintf("use %04d msecs.\n", tok - tik);
    return 0;
}

