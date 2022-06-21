#include<stdio.h>
#include<conio.h>
int min(int arr[10],int n){
	int minvalue=arr[0],i;
	int index=-1;
	for(i=1;i<n;i++){
		if(minvalue>arr[i]){
			minvalue=arr[i];
			index=i;
		}
	}
	return index;
}
void main(){
	int framesize,len,i,j,k;
	int refstring[20],frame[20];
	int pagefault=0,least,access[20];
	clrscr();
	printf("Enter the length of reference string; ");
	scanf("%d",&len);
	printf("Enter the refernece string: ");
	for(i=0;i<len;i++)
		scanf("%d",&refstring[i]);
	printf("Enter the frame size: ");
	scanf("%d",&framesize);
	for(i=0;i<framesize;i++){
		frame[i]=-1;
		access[i]=0;
	}
	printf("\n\t\t\tPage table");
	for(i=0;i<len;i++){
		int avail=0;
		printf("\n%d\t",refstring[i]);
		for(j=0;j<framesize;j++)
			if(frame[j]==refstring[i]){
				avail=1;
				access[j]++;
				break;
			}
		if(avail==0){
			int dm=0;
			pagefault++;
			for(k=0;k<framesize;k++)
				if(frame[k]==-1){
					dm=1;
					break;
				}
			if(dm==1){
				frame[k]=refstring[i];
				access[k]++;
			}
			else{
				j=min(access,framesize);
				frame[j]=refstring[i];
				access[j]++;
			}
			for(k=0;k<framesize;k++)
				printf("%d ",frame[k]);
		}
	}
	printf("\nTotal pagefault: %d",pagefault);
	getch();

}