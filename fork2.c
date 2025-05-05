#include <stdio.h>
#include <unistd.h>

int main()
{
   pid_t child_pid;
   child_pid=fork();
   if(child_pid==0){
    printf("Child Process:PID=%d\n",getpid());
   }
   else if(child_pid>0){
    printf("Parent Process:PID=%d\n",getppid());
   }
   else{
    perror("Fork Failed");
   }
   return 0;
}