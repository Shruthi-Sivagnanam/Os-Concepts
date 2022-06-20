#include<stdio.h>
#include<conio.h>
int noofprocess,noofhole;
int holesize[10],processsize[10],holenumber[10];

//First fit way of allocating the memory to the process
void firstfit(){
	int i,j;
	printf("\n\t\tFirst Fit");
	printf("\nProcess Psize Allocatedhole");
	for(i=0;i<noofprocess;i++){
		int c=0;
		for(j=0;j<noofhole;j++){
			if(processsize[i]<=holesize[j]){
				printf("\nP%d\t%d\tH%d",i,processsize[i],j);
				c=1;
				holesize[j]-=processsize[i];
				break;
			}
		}
		if(c==0){
			printf("\nP%d\t%d\tNot allocated",i,processsize[i]);
		}
	}
}
//Best fit way of allocating memory to the process
void bestfit(){
	int i,j;
	int temp;
	for(i=0;i<noofhole-1;i++){
		for(j=i+1;j<noofhole;j++){
			if(holesize[i]>holesize[j]){
				//holes are sorted
				temp=holesize[i];
				holesize[i]=holesize[j];
				holesize[j]=temp;
				//hole number is sorted according to the size
				temp=holenumber[i];
				holenumber[i]=holenumber[j];
				holenumber[j]=temp;
			}
		}
	}
	printf("\n\t\tBest Fit\n");
	printf("\nProcess Psize Allocated hole");
	for(i=0;i<noofprocess;i++){
		int c=0;
		for(j=0;j<noofhole;j++){
			if(processsize[i]<=holesize[j]){
				printf("\nP%d\t%d\tH%d",i,processsize[i],holenumber[j]);
				c=1;
				holesize[j]-=processsize[i];
				break;
			}
		}
		if(c==0)
			printf("\nP%d\t%d\tNot allocated",i,processsize[i]);
	}
}
void main(){
	int i,j;
	int ch;
	clrscr();
	printf("\t\t\tMemory Allocation\n");
	printf("Enter the number of the memory holes: ");
	scanf("%d",&noofhole);
	printf("Enter the eack block hole size: \n");
	for(i=0;i<noofhole;i++){
		printf("Hole %d: ",i);
		scanf("%d",&holesize[i]);
		holenumber[i]=i;
	}
	printf("Enter the number of process: ");
	scanf("%d",&noofprocess);
	printf("Enter the size of each process:\n");
	for(i=0;i<noofprocess;i++){
		printf("Process %d: ",i);
		scanf("%d",&processsize[i]);
	}
	printf("\nMenu for allocation:\n");
	printf("\n1.First Fit \n2.Best Fit");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			firstfit();
			break;
		case 2:
			bestfit();
			break;
		default:
			printf("Wrong choice!!");
	}
	printf("\n\t\tThank you!!");
	getch();
}