#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
int p[2];
if (pipe(p) < 0){
exit(1);
}

int f1 = fork();
if (f1 < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (f1 == 0) {
write(p[1], "Hello", 5);
} else{
int f2 = fork();
if (f2 < 0){
// Second fork failed
fprintf(stderr, "fork 2 failed\n");
exit(1);
} else if (f2 == 0){
char passedInfo[5];
read(p[0], passedInfo, 5);
printf("I got the data from the first child! They say '%s'!\n", passedInfo);
}
}

return 0;
}




/*******************************************************
Lawrence Hoerst

There were no questions for this one so 'hi!'

*******************************************************/

