#include<stdio.h>
#include<conio.h>

//global variables
int n,process[10],bt[10],priority[10],wt[10],tat[10];

//sort the process according to the priority order -- selection sort technique is used
void sortbt(){
	int i,j,pos,temp;
	for(i=0;i<n;i++){
		pos=i;
		for(j=i+1;j<n;j++){
			if(priority[j]<priority[pos])
				pos=j;
		}
		//swapping the burst time
		temp=bt[pos];
		bt[pos]=bt[i];
		bt[i]=temp;
		//swapping the process number
		temp=process[pos];
		process[pos]=process[i];
		process[i]=temp;
	}
}

//Calculating the waiting time
void waitingtime(){
	int i;
	wt[0]=0;
	for(i=1;i<n;i++)
		wt[i]=bt[i-1]+wt[i-1];
}

//Calculating the turnaround time
void turnaroundtime(){
	int i;
	for(i=0;i<n;i++)
		tat[i]=bt[i]+wt[i];
}

//Calculating the average of waiting time and turnaround time
void average(){
	float awt,atat;
	int twt=0,ttat=0,i;
	sortbt();
	waitingtime();
	turnaroundtime();
	printf("Waiting time and turnaround time for each process: \n");
	for(i=0;i<n;i++){
		printf("Process%d:\t%d\t%d\n",process[i],wt[i],tat[i]);
		twt+=wt[i];
		ttat+=tat[i];
	}
	awt=(float)twt/n;
	atat=(float)ttat/n;
	printf("The average waiting time : %f\n",awt);
	printf("The average turnaround time: %f\n",atat);
}

//Displaying gantt chart
void ganttchart(){
	int i;
	printf("| ");
	for(i=0;i<n;i++)
		printf("P%d | ",process[i]);
	printf("\n0    ");
	for(i=0;i<n;i++)
		printf("%d    ",tat[i]);
}

//Main function
void main(){
	int i;
	printf("Enter the number of the process : ");
	scanf("%d",&n);
	printf("Enter the burst time and priority of each process: \n");
	for(i=0;i<n;i++){
		process[i]=i+1;
		printf("Process%d : ",process[i]);
		scanf("%d",&bt[i]);
		scanf("%d",&priority[i]);
	}
	average();
	ganttchart();
	getch();
}