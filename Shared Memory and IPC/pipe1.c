#include  <stdio.h>
#include<sys/types.h>
#include<stdlib.h>

int main(void)
{
    int pdfs[2],arr[25],br[25];
    pid_t pid;
    if(pipe(pdfs)==-1){
        printf("Error in pipe creation");
        exit(-1);
     }
    pid=fork();
    if(pid==0){
        int f0=0,f1=1,f2;
        int i;
        printf("Child process: \n");
        for(i=0;i<25;i++){
            f2=f1+f0;
            f0=f1;
            f1=f2;
            arr[i]=f2;
            printf("%d ",f2);
        }
        write(pdfs[1],arr,25*sizeof(int));
    }
    else{
        int i,j;
        wait(NULL);
        printf("\nParent process: \n");
        read(pdfs[0],br,25*sizeof(int));
        for(i=0;i<25;i++){
            int flag=0;
            for(j=2;j<br[i]/2;j++){
                if(br[i]%j==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                      printf("%d ",br[i]);
        }
    }
}
