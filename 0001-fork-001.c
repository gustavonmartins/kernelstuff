#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define MAX_COUNT 200
#define BUF_SIZE 100

int main (void)
{
  pid_t pid;
  int i;
  char buf[BUF_SIZE];

  fork(); //from here one, there are two processes, so this program is duplicated

  pid=getpid();

  for (i=1; i<= MAX_COUNT; i++){
    printf("My name is pid %d, value = %d\n",pid,i);
  }
}
