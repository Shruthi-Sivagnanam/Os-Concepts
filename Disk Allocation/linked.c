#include<stdio.h>
#include<string.h>

struct dirfile{
    char filename[10];
    int noofblock;
    int blocks[10];
}file[10];

void main(){
    int i,j=0,n,blocks[10],k,ch;
    char name[10];
    int c=0;
    int allocated[20];
    for(i=0;i<20;i++)
        allocated[i]=0;
    do{
        c=0;
        printf("Enter the filename: ");
        scanf("%s",name);
        printf("Enter the no of blocks: ");
        scanf("%d",&n);
        printf("Enter the block numbers: ");
        for(i=0;i<n;i++)
            scanf("%d",&blocks[i]);
        for(i=0;i<n;i++){
            if(allocated[blocks[i]]==1 || blocks[i]>20){
                c=1;
                break;
            }
        }
        if(c==1){
            printf("Allocation not possible");
        }
        else{
            strcpy(file[j].filename,name);
            file[j].noofblock=n;
            for(k=0;k<n;k++){
                file[j].blocks[k]=blocks[k];
                allocated[blocks[k]]=1;
            }
            j++;
        }
        printf("Do you want to continue: ");
        scanf("%d",&ch);
    }while(ch==1);
    printf("The file Allocation: ");
    printf("\nFilename noofblocks list:");
    for(k=0;k<j;k++){
        printf("\n%s\t%d\t",file[k].filename,file[k].noofblock);
        for(i=0;i<file[k].noofblock;i++)
            printf("%d->",file[k].blocks[i]);
    }
}
