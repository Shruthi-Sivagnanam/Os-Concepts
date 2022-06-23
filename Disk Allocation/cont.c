#include <stdio.h>
#include<string.h>

struct directory{
    char filename[10];
    int start;
    int length;
}dir[10];

int main()
{
    int i,ch,start, length;
    int j=0,k;
    int size=20;
    char name[10];
    int allocated[20];
    for(i=0;i<20;i++)
        allocated[i]=0;
    do{
        printf("Enter the filename: ");
        scanf("%s",name);
        printf("Enter the start block number: ");
        scanf("%d",&start);
        printf("Enter the length of the file: ");
        scanf("%d",&length);
        if(start+(length-1)<20){
            int c=0;
            for(k=start;k<start+length;k++){
                if(allocated[k]==1)
                    c=1;
                    break;
            }
            if(c==1)
                printf("Can't be allocated");
            else{
                strcpy(dir[j].filename,name);
                dir[j].start=start;
                dir[j].length=length;
                j++;
                for(k=start;k<start+length;k++)
                    allocated[k]=1;
                printf("Allocation done sucessfully");
            }
        }
        else
            printf("Allocation can't be done");
        printf("Do you want to continue?<0/1>: ");
        scanf("%d",&ch);
    }while(ch==1);
    printf("\nThe file allocation in the disk: ");
    printf("\nFile start length \n");
    for(i=0;i<j;i++){
        printf("%s %d %d\n",dir[i].filename,dir[i].start,dir[i].length);
    }

    return 0;
}
