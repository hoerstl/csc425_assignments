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
printf("Child here\n");
printf("Return of Child wait: %d\n", wait(NULL));
} else {
int childPID = wait(NULL);
printf("Parent here, waited for: %d\n", childPID);
}
return 0;
}



/*********************************************************
Lawrence Hoerst

Question 1: When I use wait for the parent to halt for the
child, the parent process becomes blocked until the child
is complete. Once, done, the wait function returns the PID
of the terminated child process.

Question 2: It seems that when I use wait in the child,
the wait function immediately returns a value of -1.
This indicates that the child has no child processes
of its own and therefore has no way to wait for them.

*********************************************************/
