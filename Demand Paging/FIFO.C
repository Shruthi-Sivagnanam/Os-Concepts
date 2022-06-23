#include<stdio.h>
#include<conio.h>
void main(){
	int framesize,frame[20];
	int len,refstring[20];
	int pagefault=0,first=0;
	int i,j;
	clrscr();
	printf("Enter the length of the reference string: ");
	scanf("%d",&len);
	printf("Enter the reference string: ");
	for(i=0;i<len;i++)
		scanf("%d",&refstring[i]);
	printf("Enter the frame size: ");
	scanf("%d",&framesize);
	for(i=0;i<framesize;i++)
		frame[i]=-1;
  
  //FIFO page replacement technique.
	printf("The Ref table : \n");
	printf("String  Frame content:");
	for(i=0;i<len;i++){
		int avail=0;
		printf("\n%d\t",refstring[i]);
		for(j=0;j<framesize;j++)
			if(frame[j]==refstring[i]){
				avail=1;
				break;
			}
		if(avail==0){
			pagefault++;
			frame[first]=refstring[i];
			if(first==framesize-1)
				first=0;
			else
				first++;
		}
	}
	printf("The total number of page fault: %d",pagefault);
	getch();
}
