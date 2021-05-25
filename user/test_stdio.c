#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("test getchar\n");
    char ch;
    ch = getchar();
    printf("%c\n", ch);

    printf("test gets\n");
    char s[20];
    gets(s, 20);
    cputs(s);

    return 0;
}