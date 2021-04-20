#include <stdio.h>
#include <ulib.h>

void
sleepy(int pid) {
    int i, time = 100;
    for (i = 0; i < 10; i ++) {
        sleep(time);
        cprintf("sleep %d x %d slices.\n", i + 1, time);
    }
    exit(0);
}

int
main(void) {
    unsigned int time = gettime_msec(), time2;
    cprintf("time start: %d\n", time);
    int pid1, exit_code;

    if ((pid1 = fork()) == 0) {
        sleepy(pid1);
    }
	
    assert(waitpid(pid1, &exit_code) == 0 && exit_code == 0);
    time2 = gettime_msec();
    cprintf("time end: %d\n", time2);
    cprintf("use %04d msecs.\n", gettime_msec() - time);
    cprintf("sleep pass.\n");
    return 0;
}

