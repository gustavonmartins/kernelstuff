#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 5000

void doChildJob(int);
void doParentJob(int);

int main (void) {
  pid_t pid;

  printf("Stage 1: Forking baby\n");
  pid=fork();
  if (pid<0){
    printf("Stage 1: Fork fail\n”");
    exit(1);
  }
  else if (pid==0){
    doChildJob(1);
    printf("Child is now wants to calculate more!\n");
    execvp("/usr/bin/galculator",NULL);
    printf("April fools day: This text will never see daylight\n");
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
  for (i=0;i<=MAX_COUNT/100;i++){
    printf("Stage %d, Child talks: %d\n",index,i);
  }
}

void doParentJob(int index){
  printf("***Stage %d, Parent turn***\n",index);
  int i;
  double makeSlow;
  for (i=0;i<=MAX_COUNT;i++){
    printf("Stage %d, Parent talks: %d\n",index,i);
  }
}
