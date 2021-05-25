#include <thumips.h>
#include <stdio.h>
#include <syscall.h>
#include <file.h>
#include <ulib.h>
#include <unistd.h>

/* HIGH level console I/O */

/* *
 * cputch - writes a single character @c to stdout, and it will
 * increace the value of counter pointed by @cnt.
 * */
static void
cputch(int c, int *cnt) {
    sys_putc(c);
    (*cnt) ++;
}


/* *
 * vcprintf - format a string and writes it to stdout
 *
 * The return value is the number of characters which would be
 * written to stdout.
 *
 * Call this function if you are already dealing with a va_list.
 * Or you probably want cprintf() instead.
 * */
int
vcprintf(const char *fmt, va_list ap) {
    int cnt = 0;
    vprintfmt(cputch, NO_FD, &cnt, fmt, ap);
    return cnt;
}

/* *
 * cprintf - formats a string and writes it to stdout
 *
 * The return value is the number of characters which would be
 * written to stdout.
 * */
int
cprintf(const char *fmt, ...) {
    va_list ap;
    int cnt;
    va_start(ap, fmt);
    cnt = vcprintf(fmt, ap);
    va_end(ap);
    return cnt;
}


static const char* hexdigits = "0123456789ABCDEF";
void printhex(unsigned int x){
  char tmp[9];
  int i=0;
  tmp[8] = 0;
  for(i=7;i>=0;i--){
    tmp[i] = hexdigits[x & 0xf];
    x = x >> 4;
  }
  cprintf(tmp);
}


/* cputchar - writes a single character to stdout */
void
cputchar(int c) {
  sys_putc(c);
}

void printbase10(int x){
  unsigned int t;
  int i = 0;
  char buf[16];
  if(x<0)
    cputchar('-');
  x = (x<0)?-x:x;
  while(x >= 10){
    t = __divu10(x); 
    buf[i++] = ('0'+(x-__mulu10(t)));
    x = t;
  }
  buf[i] = ('0'+x);
  for(;i>=0;i--){
    cputchar(buf[i]);
  }
}


/* *
 * kputs- writes the string pointed by @str to stdout and
 * appends a newline character.
 * */
int
cputs(const char *str) {
    int cnt = 0;
    char c;
    while ((c = *str ++) != '\0') {
        cputch(c, &cnt);
    }
    cputch('\n', &cnt);
    return cnt;
}


static void
fputch(char c, int *cnt, int fd) {
    write(fd, &c, sizeof(char));
    (*cnt) ++;
}

int
vfprintf(int fd, const char *fmt, va_list ap) {
    int cnt = 0;
    vprintfmt((void*)fputch, fd, &cnt, fmt, ap);
    return cnt;
}

int
fprintf(int fd, const char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    int cnt = vfprintf(fd, fmt, ap);
    va_end(ap);

    return cnt;
}

int getchar(){
  int c, ret;
  if ((ret = read(0, &c, sizeof(char))) <= 0) {
      return -1;
  }

  cputchar(c);
  return c;
}

char *gets(char * buffer, int bufsize) {
    int ret, i = 0;
    while (1) {
        char c;
        if ((ret = read(0, &c, sizeof(char))) < 0) {
            return NULL;
        }
        else if (ret == 0) {
            if (i > 0) {
                buffer[i] = '\0';
                break;
            }
            return NULL;
        }

        if (c == 3) {
            return NULL;
        }
        else if (c >= ' ' && i < bufsize - 1) {
            cputchar(c);
            buffer[i ++] = c;
        }
        else if (c == '\b' && i > 0) {
            cputchar(c);
            i --;
        }
        else if (c == '\n' || c == '\r') {
            cputchar('\r'); //use CRLF
            cputchar('\n');
            buffer[i] = '\0';
            break;
        }
    }
    return buffer;
}