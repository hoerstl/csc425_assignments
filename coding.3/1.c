#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
int x = 100;
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
printf("Initial Child Value: %d\n", x);
x += 1;
printf("Post Child Value: %d\n", x);
} else {
printf("Initial Parent Value: %d\n", x);
x += 5;
printf("Post Parent Value: %d\n", x);
//int rc_wait = wait(NULL);
}
return 0;
}

/*********************************************
Lawrence Hoerst
Question 1:
The value of the variable in the child process
is the same as in the parent before they 
independently change the values. 
Question 2:
When they both change the values, their 
alterations do not affect the other's
variable.
*********************************************/
