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
char *myargs[2];
myargs[0] = "ls";
myargs[1] = NULL;
execvp(myargs[0], myargs);
} else {

}
return 0;
}


/**********************************************************
Lawrence Hoerst

Question 1: I believe that there are so many variants of
exec because it's a very commonly used function. The
variants allow for a lot of flexibility when specifying
the parameters. This means that you have lots of options
as a developer when executing another function.

**********************************************************/
