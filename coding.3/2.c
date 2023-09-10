#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
FILE *file = fopen("2.txt", "w");
int rc = fork();
if (rc < 0) {
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
// write to the file
fprintf(file, "child write to file\n");
} else {
// parent write to file
fprintf(file, "parent write to file\n");
}
return 0;
}

/***********************************************
Lawrence Hoerst
Question 1: It seems as though both the child and
parent can acess the file descriptor returned by
open freely.

Question 2: It looks like if they're writing to
the file concurrently, they do not overwrite
each other's work. For example, both lines in
the code above were written to the file 2.txt
one after the other. I believe the order is
undetermined, however.

***********************************************/
