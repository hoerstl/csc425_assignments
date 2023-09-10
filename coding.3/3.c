#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
FILE *file = fopen("3.txt", "w+");
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
printf("hello\n");
fprintf(file, "done");
fclose(file);
} else {
char fileContent[100];
fileContent[0] = 0;
while(!fileContent[0]){
fseek(file, 0, SEEK_SET);
fgets(fileContent, 100, file);
sleep(.2);
}
printf("goodbye\n");
fclose(file);
}
return 0;
}

/*********************************************************
Lawrence Hoerst

Question 1: I absolutely can ensure that the child process
always finishes first without calling wait() in the parent.
I achieved this by writing to a file in the child when I was
done with it. The parent, however, waits for something to be
place in the file during that time. Therefore, the parent
always executes it's instructions after the child.

*********************************************************/
