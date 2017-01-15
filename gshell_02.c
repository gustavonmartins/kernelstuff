#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXARGS 20
#define ARGLEN  100

int execute (char*[]);

int main(){
  char *arglist[MAXARGS+1];
  int   numargs;
  char  argbuf [ARGLEN];
  char *makestring();
  numargs=0;

  while (numargs<MAXARGS){
    printf("Arg[%d]?",numargs);
    if (fgets(argbuf, ARGLEN, stdin) && *argbuf!='\n'){
      arglist[numargs++]=makestring(argbuf);
    }
    else {
      if (numargs>0) {
	arglist[numargs]=NULL;
	execute (arglist);
	numargs=0;
      }
    }
  }
  return 0;
}

int execute (char* arglist[]) {

  pid_t pid;
  
  pid=fork();

  if (pid==-1) {
    printf("For error!");
    exit(1);
  }
  else if (pid==0){
    execvp(arglist[0], arglist);
    perror("execvp failed\n”");
    exit(1);
  }
  else {
    //Has to wait for child before doing anything else:
    wait(NULL);
    printf("Child exited\n");
  }
  
}

char* makestring (char* buf){

  char *cp;

  buf[strlen(buf)-1]='\0';
  cp=malloc(strlen(buf)+1);

  if (cp==NULL){
    fprintf(stderr,"no memory\n");
    exit(1);
  }

  strcpy (cp,buf);
  return cp;
}
