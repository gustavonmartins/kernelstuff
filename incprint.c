#include <stdio.h>
#include <pthread.h> //Compile and link with -pthread.
#include <unistd.h>

#define NUM 5

int counter=0;
void *print_count(void*);


int main(){
  pthread_t t1;
  int i;
  
  pthread_create(&t1, NULL, print_count, NULL);
  for (i=0;i<NUM;i++){
    counter++;
    sleep(1);
  }
  
  pthread_join(t1,NULL); //dont execute further (wait here) until thread chaos has been stopped
  printf("Finished!\n”");
}

void *print_count(void *m){
  int i;
  for (i=0; i<NUM; i++){
    printf("count=%d\n", counter);
    sleep(1); //This is bad. Better would be to only update if counter has changed
  }
}
