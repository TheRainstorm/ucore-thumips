#include <stdio.h>
#include <ulib.h>

int
main(void) {
    unsigned int tik, tok, tok_p;
    
    tik = gettime_msec();
    // cprintf("tik: %d\n", tik);
    tok = gettime_msec();
    for(int i=0; i<10; i++){
        while(1){
            tok_p = tok;
            tok = gettime_msec();
            if(tok != tok_p && (tok - tik)%100==0){
                // cprintf("tok: %d\n", tok);
                break;
            }
        }
        cprintf("%d!\n", 9-i);
    }
    return 0;
}