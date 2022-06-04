#include<stdio.h>
#include<conio.h>

//global variable
int n,process[10],bt[10],wt[10],tat[10];

// Sort the burst time -- selection sort technique is used
void sortbt(){
	int i,j,pos,temp;
	for(i=0;i<n;i++){
		pos=i;
		for(j=i+1;j<n;j++){
			if(bt[j]<bt[pos])
				pos=j;
		}
		//burst time is swapped
		temp=bt[pos];
		bt[pos]=bt[i];
		bt[i]=temp;
		//Process number is swapped
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

//Calculating the turn around time
void turnaroundtime(){
	int i;
	for(i=0;i<n;i++)
		tat[i]=bt[i]+wt[i];
}

//Calculating the average waiting time and turnaround time
void average(){
	float awt,atat;
	int twt=0,ttat=0,i;
	sortbt();
	waitingtime();
	turnaroundtime();
	printf("Waiting time and Turn around time for each process: \n");
	for(i=0;i<n;i++){
		printf("Process %d:\t%d\t%d\n",process[i],wt[i],tat[i]);
		ttat+=tat[i];
		twt+=wt[i];
	}
	awt=(float)twt/n;
	atat=(float)ttat/n;
	printf("The average of the waiting time: %f\n",awt);
	printf("The average of the turnaround time : %f\n",atat);
}

//Displaying the gantt chart
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
	clrscr();
	printf("\t\t\tSJF\n");
	printf("Enter the number of the process: ");
	scanf("%d",&n);
	printf("Enter the burst time of the each process: \n");
	for(i=0;i<n;i++){
		printf("Process%d : ",i+1);
		scanf("%d",&bt[i]);
		process[i]=i+1;
	}
	average();
	ganttchart();
	getch();
}