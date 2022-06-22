#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(void){
    pid_t pid;
    pid=fork();
    if(pid<0){
        printf("Process creation failed");
        exit(-1);
    }
    else if(pid==0){
        printf("Child process \n");
        execl("/bin/date","date",0);
        exit(0);
    }
    else{
        wait(NULL);
        printf("\nChild terminated ");
        exit(0);
    }
    printf("\n Thank you");
    return 0;
}
