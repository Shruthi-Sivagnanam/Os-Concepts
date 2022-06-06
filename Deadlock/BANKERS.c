#include<stdio.h>
#include<conio.h>
void main(){
	int i,j,k,ans[10],ind=0,need[10][10],y,flag,f[10];
	int n,m,alloc[10][10],max[10][10],avail[10];
	printf("Enter the number of the process: ");
	scanf("%d",&n);
	printf("Enter the number of resources: ");
	scanf("%d",&m);
	printf("Enter the avaliable resource matrix: ");
	for(i=0;i<m;i++)
		scanf("%d",&avail[i]);
	printf("Enter the allocation matrix: ");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&alloc[i][j]);
	printf("Enter the max matrix: ");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&max[i][j]);
	for(k=0;k<n;k++)
		f[k]=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			need[i][j]=max[i][j]-alloc[i][j];
	y=0;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(f[i]==0){
				flag=0;
				for(j=0;j<m;j++)
				if(need[i][j]>avail[j]){
					flag=1;
					break;
				}
				if(flag==0){
					ans[ind++]=i;
					for(y=0;y<m;y++)
						avail[y]+=alloc[i][y];
					f[i]=1;
				}
			}
		}
	}
	flag=1;
	for(i=0;i<n;i++){
		if(f[i]==0){
			flag=0;
			printf("The following sequence is not  sequence.");
			break;
		}
	}
	if(flag==1){
		printf("The following is the safe sequence: ");
		for(i=0;i<n;i++)
			printf("%d\t",ans[i]);
	}
	getch();
}
