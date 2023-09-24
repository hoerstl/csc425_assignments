#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>





int main(int argc, char **argv){

long long bytesToUse = atoi(argv[1]) * 1024 * 1024;
int* timeWaster = malloc(bytesToUse);
int numbersInArray = bytesToUse / sizeof(int);
printf("Tried to allocate %lld bytes\n", bytesToUse);
printf("%d integers will fit in the allocated array\n", numbersInArray);

int i = 0;
while(1){

timeWaster[i] = 1;
    i = (i + 1) % numbersInArray;
}

}

