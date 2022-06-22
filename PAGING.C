#include<stdio.h>
#include<conio.h>
#include<math.h>
void main(){
	int size,m,n,pgno,pagetable[3]={5,6,7},i,j,frameno;
	int ra=0,ofs;
	clrscr();
	printf("Enter the process size(max 12kb): ");
	scanf("%d",&size);
	n=ceil(size/4);
	printf("Total no of pages: %d",n);
	printf("\nEnter the relative address (in hex):");
	scanf("%d",&ra);
	pgno=ra/1000;
	ofs=ra%1000;
	printf("Page no is %d",pgno);
	printf("\nPage table");
	for(i=0;i<n;i++)
		printf("\n%d [%d] ",i,pagetable[i]);
	frameno=pagetable[pgno];
	printf("\nPhysical address : %d%d",frameno,ofs);
	getch();
}