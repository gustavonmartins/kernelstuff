#include <stdio.h>
#include <signal.h>

int main (){
  
  int i;

  signal(SIGINT,SIG_IGN);
    printf("you cant stop me!\n");

    while(1){
      sleep(1);
       printf("haha!!!\n");
    }
  
}
