#include <stdio.h>
#include <stdlib.h>

char buf[20];
int get_int(){
    gets(buf, 20);
    return atoi(buf);
}

int main(){
    int ans = 77;

    printf("Guess number game! The number is in [0,128).\n");
    
    int i=0, n;
    while(1){
        printf("[%d]you guess: ", i);
        n = get_int();
        i++;
        if(i>=9){
            printf("Game Over! you wasted too many times\n");
            break;
        }
        else if(n < ans){
            printf("Too little\n");
        }else if(n > ans){
            printf("Too big\n");
        }else{
            printf("You Win!!!\n");
            break;
        }
    }
    return 0;
}