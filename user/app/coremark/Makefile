CFLAGS := -fno-builtin-fprintf -fno-builtin -nostdlib  -nostdinc -g  -EL -G0 -fno-delayed-branch -Wa,-O3 -fno-pic -mno-abicalls -mno-shared -mfp32 -ggdb -gstabs
CFLAGS += -I../../libs -I../../../kern/include -I.
CFLAGS += -DITERATIONS=6000
CFLAGS += -DFLAGS_STR=\"-O3\"

FPGA_LD_FLAGS = -S

OBJS = $(patsubst %.c, %.o, $(wildcard *.c))

../../../$(USER_OBJDIR)/coremark: $(OBJS)
	$(LD) $(FPGA_LD_FLAGS) -T ../../libs/user.ld ../../../$(USER_LIB) $(OBJS) -o $@

%.o: %.c coremark.h Makefile
	$(CC) -c -mips1 $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o