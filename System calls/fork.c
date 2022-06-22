
#include  <stdio.h>
#include<sys/types.h>

void main()
{
    pid_t pid;
    int x=4;
    pid=fork();
    if(pid<0){
        printf("Process creation failed");
        exit(-1);
    }
    else if(pid==0){
        printf("Child process");
        printf("\nProcess id %d",getpid());
        printf("\nThe value of x is %d",x++);
        printf("\nParent porcess id: %d",getppid());
    }
    else{
        printf("Parent process");
        printf("\nProcess id is %d",getpid());
        printf("\nX=%d",x);
        printf("\nProcess id of shell is %d",getppid());
    }
    printf("\nThank you!!");
}
