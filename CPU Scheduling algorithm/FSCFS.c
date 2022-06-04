#include<stdio.h>
#include<conio.h>

//global variables
int n,wt[10],bt[10],tat[10];

//Calculating waiting time for each process
void waitingtime(){
	int i;
	wt[0]=0;
	for(i=1;i<n;i++)
		wt[i]=bt[i-1]+wt[i-1];
}

//Calculating turnaround time for each process
void turnaroundtime(){
	int i;
	for(i=0;i<n;i++)
		tat[i]=wt[i]+bt[i];
}

//Calculating the average waiting time and turnaround time
void average(){
	int twt=0,ttat=0;
	float awt,atat;
	int i;
	waitingtime();
	turnaroundtime();
	printf("Wating time and turnaround time for each process: \n");
	for(i=0;i<n;i++){
		printf("Process %d\t%d\t%d\n",i+1,wt[i],tat[i]);
		twt+= wt[i];
		ttat+=tat[i];
	}
	awt=(float)twt/n;
	atat=(float)ttat/n;
	printf("The average waiting time: %f\n",awt);
	printf("The average turnaround time: %f\n",atat);
}

//Dispalying the gantt chart
void ganttchart(){
	int i;
	printf("The Gantt Chart \n");
	printf("| ");
	for(i=0;i<n;i++)
		printf("P%d | ",i+1);
	printf("\n0   ");
	for(i=0;i<n;i++)
		printf("%d   ",tat[i]);
}

//Main function
void main(){
	int i;
	clrscr();
	printf("\t\t\tFCFS Scheduling\n");
	printf("Enter the number of process : ");
	scanf("%d",&n);
	printf("Enter the burst time of the each process: \n");
	for(i=0;i<n;i++){
		printf("Process %d :",i+1);
		scanf("%d",&bt[i]);
	}
	average();
	ganttchart();
	getch();
}
