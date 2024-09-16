#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// #include<sys/wait.h>
int main(){
    pid_t pid;
    pid = fork();
    if(pid<0){
        //fork failed
        fprintf(stderr,"Fork failed\n");
        return 1;
    }
    else if(pid==0){
       printf("Child process: My PID is %d\n", getpid());
       printf("Child process: My parent's PID is %d\n", getppid());
        sleep(20);
        printf("Executing child process--\n");
        execlp("/bin/ls", "ls", NULL);
         perror("execlp");
        exit(1);
    } 
    else{
        printf("Parent process:My Pid is%d\n",getpid());
        printf("My Parent process : My child's PID is %d\n",pid);
        printf("Child process sleepy for 20 sec \n");
        wait (NULL);
        printf("Parent process : Child process has terminated\n");
    }
    return 0;
}
