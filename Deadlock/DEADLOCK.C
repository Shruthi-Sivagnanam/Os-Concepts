#include<stdio.h>
#include<conio.h>
int avail[10],need[10][10],alloc[10][10],max[10][10];
int n,r;
void input(){
	int i,j;
	printf("Enter the no of process: ");
	scanf("%d",&n);
	printf("Enter the resources: ");
	scanf("%d",&r);
	printf("Enter the max matirx: ");
	for(i=0;i<n;i++)
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);
	printf("Enter the allocation matrix: ");
	for(i=0;i<n;i++)
		for(j=0;j<r;j++)
			scanf("%d",alloc[i][j]);
	printf("Enter the avail matrix: ");
	for(i=0;i<r;i++)
		scanf("%d",&avail[i]);
}
void call(){
	int finish[10],temp,need[10][10],flag=1,k,c=0,dead[10],safe[10];
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<r;j++)
			need[i][j]=max[i][j]-alloc[i][j];
	while(flag){
		flag=0;
		for(i=0;i<n;i++){
			c=0;
			for(j=0;j<r;j++){
				if(finish[i]==0 && (need[i][j]<=avail[j])){
					c++;
					if(c==r){
						for(k=0;k<r;k++){
							avail[k]+=alloc[i][j];
							finish[i]=1;
							flag=1;
						}
						if(finish[i]==1)
							i=n;
					}
				}
			}
		}
	}
	flag=0;
	j=0;
	for(i=0;i<n;i++){
		if(finish[i]==0){
			dead[j]=i;
			j++;
			flag=1;
		}
	}
	if(flag==1){
		printf("System in dead lock: ");
		for(i=0;i<n;i++)
			printf("P%d\t",dead[i]);
	}
	else
		printf("No dead lock ");
}
void main(){
	clrscr();
	printf("\t\t\tDeadlock prevention");
	input();
	call();
	getch();
}