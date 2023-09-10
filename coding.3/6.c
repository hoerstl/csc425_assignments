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
} else {
int childPID = waitpid(rc, NULL, 0);
printf("Parent here, waited for: %d\n", childPID);
}
return 0;
}



/*********************************************************
Lawrence Hoerst

Question 1: waitpid() would be super useful if the parent
created many child processes and wanted to wait for a
specific one to be completed before continuing.

*********************************************************/
