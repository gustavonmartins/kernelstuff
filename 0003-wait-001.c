#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define MAX_COUNT 200
#define BUF_SIZE 100

void doChildJob(int);
void doParentJob(int);

int main (void) {
  pid_t pid;
  char buf[BUF_SIZE];

  printf("Stage 1: Forking baby\n");
  pid=fork();
  if (pid<0){
    printf("Stage 1: Fork fail\n”");
    exit(1);
  }
  else if (pid==0){
    doChildJob(1);
  }
  else if (pid>0) {
    printf("Parent:Before you freeze me, let me spea...\n");
    wait(NULL);
    doParentJob(1);
  }
 
}

void doChildJob(int index){
  printf("***Stage %d, Child turn***\n",index);
  int i;
  for (i=0;i<=MAX_COUNT;i++){
    printf("Stage %d, Child talks: %d\n",index,i);
  }
}

void doParentJob(int index){
  printf("***Stage %d, Parent turn***\n",index);
  int i;
  for (i=0;i<=MAX_COUNT;i++){
    printf("Stage %d, Parent talks: %d\n",index,i);
  }
}
