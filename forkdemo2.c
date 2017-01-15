#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
  int test1,test2;
  printf("my pid is %d\n",getpid());
  fork();
  test2=wait(&test1);
  printf("my pid is %d, child returned %d and %d\n",getpid(),test1, test2);
  fork();
  test2=wait(&test1);
  printf("my pid is %d, child returned %d and %d\n",getpid(),test1, test2);
  fork();
  test2=wait(&test1);
  printf("my pid is %d, child returned %d and %d\n",getpid(),test1, test2);
  
  exit( 17);
}
