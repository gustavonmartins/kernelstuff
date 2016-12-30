#include <stdio.h>
#include <sys/types.h>

#define COMMON_NUM 100

void PapaThing (void);
void BabyThing (void);

int main (void){
  pid_t pid;
  int tricky;
  
  pid = fork();

  if (pid<0){
    printf("hmmm... something went wrong :(\n");
  }
  else if (pid==0){
    printf("%d Hi!! I am your new child! Surprised :) ??\n",getpid());
    BabyThing();
    tricky=4;
  }
  else if (pid>0){
    printf("%d: I think I just became a daddy... !!!\n",getpid());
    PapaThing();
    tricky=40;
  }

  printf("Who am I? %d and I read the trick number of %d\n",getpid(),tricky);
}

void PapaThing (void){
  int i;
  printf("Papa: I hope I can read this: %d\n",COMMON_NUM);
  for (i=1;i<=COMMON_NUM;i++){
    printf("Papa: Counting till... %d\n",i);
  }
  printf("Papa is aaaaamazed!\n");
}

void BabyThing (void){
  int i;
  for (i=1;i<=COMMON_NUM;i++){
    printf("Baby: Counting till... %d\n",i);
    }
  printf("Baby: Yes, I read!: %d\n",COMMON_NUM);
  printf("Baby: I am bored :(\n");
}
