#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>





int main(int argc, char **argv){

long long bytesToUse = atoi(argv[1]) * 1024 * 1024;
int* timeWaster = malloc(bytesToUse);
long long numbersInArray = bytesToUse / (long long)sizeof(int);
printf("Here's the pid for convenience: %d\n", getpid());
printf("Tried to allocate %lld bytes\n", bytesToUse);
printf("%lld integers will fit in the allocated array\n", numbersInArray);

long long i = 0;
while(1){

    timeWaster[i] = 1;
    i = (i + 1) % numbersInArray;
}

}

