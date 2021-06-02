#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>
#include <unistd.h>

#define VISIT_SIZE 1000000
char visit[VISIT_SIZE];

int get_prime(int n, int fd){
    // memset(visit, 0, VISIT_SIZE*sizeof(char));   //init, 0 means prime
    for(int i=2; i*i<n; i++){
        if(!visit[i]){  //if i is prime, filter the 2*i, 3*i, 4*i, ...
            for(int j=i*i; j<n; j+=i){      //i*(i-1) has already been filter(i-1 can be decomposed to more little prime)
                visit[j]=1;
            }
        }
    }
    
    int counter=0;  //count the prime number
    for(int i=2; i<n; i++){
        if(!visit[i]){
            fprintf(fd, "%d ", i);
            counter++;
        }
    }
    fprintf(fd, "\n");
    return counter;
}

int main(int argc, int argv[]){
    int n;
    if(argc==1){
        n = 1000;
    }else{
        n = atoi(argv[1]);
    }
    int fd = open("primes.txt", O_WRONLY | O_TRUNC);

    printf("[2, %d): %d\n", n, get_prime(n, fd));

    close(fd);
    return 0;
}