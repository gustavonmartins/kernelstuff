#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//##define SHHHH

void wakeup (int);
void wakeup2 (int);

int main(){
  printf("About to sleep for 4 seconds\n");
  signal(SIGALRM,wakeup);
  alarm(4);
  pause();
  printf("Morning!!!!!!!!!!!\n");
  signal(SIGALRM,wakeup2);
  alarm(3);
  for (int i=0;;++i) {
    printf("I count to: %d\n", i);
  }
}

void wakeup(int signum){
#ifndef SHHH
  printf("Alarm received from kernel\n");
#endif
}

void wakeup2(int signum){
  printf("What a weird thing!\n");
  exit(1);
}
