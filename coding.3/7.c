#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
close(STDOUT_FILENO);
printf("No I wasn't");
} else {
int rc_wait = wait(NULL);
}
return 0;
}

/*************************************************
Lawrence Hoerst

Question 1: If the child calls printf() after closing
the standard output file, no output is printed to
the console.

*************************************************/


