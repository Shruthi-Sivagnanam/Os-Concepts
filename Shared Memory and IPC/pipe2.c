#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main(void){
    int pdfs[2];
    pipe(pdfs);
    pid_t pid;
    pid=fork();
    if(pid!=0){
        close(0);
        dup(pdfs[0]);
        close(pdfs[1]);
        execlp("wc","wc","-l",NULL);
    }
    else{
        close(1);
        dup(pdfs[1]);
        close(pdfs[0]);
        execlp("who","who",NULL);
    }
    return 0;
}
