#include<stdio.h>
#include<conio.h>
#include<string.h>
struct dirfile{
	char filename[20];
	char dirname[20];
}file[10];
void main(){
	char dirname[20];
	char name[20];
	int ch,choice,found;
	int i=0,j,k;
	clrscr();
	printf("Enter the name of the directory: ");
	scanf("%s",dirname);
	do{
		printf("\t\t\tMenu \n");
		printf("1.Create file\n2.Delete file\n3.Search file\n4.List all file");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the name of the file: ");
				scanf("%s",file[i].filename);
				strcpy(dirname,file[i].dirname);
				printf("%s",file[i].filename);
				i++;
				break;
			case 2:
				found=0;
				printf("Enter the name of the file: ");
				scanf("%s",name);
				for(j=0;j<i;j++){
					if(strcmp(file[j].filename,name)==0){
						for(k=j;k<i-1;k++)
							strcpy(file[k].filename,file[k+1].filename);
						i--;
						found=1;
						break;
					}
					}
				if(found==0)
					printf("No such file");
				else
					printf("File deleted");
				break;
			case 3:
				found=0;
				printf("Enter the name of the filename: ");
				scanf("%s",name);
				for(k=0;k<i;k++){
					if(strcmp(file[k].filename,name)==0){
						found=1;
						break;
					}
				}
				if(found==0)
					printf("No such file");
				else
					printf("File exists");
				break;
			case 4:
				printf("The file in directory are: \n");
				for(k=0;k<i;k++)
					printf("%s  ",file[k].filename);
				break;
			default:
				printf("Wrong choice!!");

		}
		printf("\nDo you want to continue?<0/1>: ");
		scanf("%d",&ch);
	}while(ch==1);
}
