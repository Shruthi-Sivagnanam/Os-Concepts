
#include <stdio.h>
int bt[10],wt[10],tat[10];
int timeslice,n;

void wt_and_tat(){
    int i,j;
    int temp=0;
    int flag=1;
    int c;
    int bt1[10];
    for(i=0;i<n;i++)
        bt1[i]=bt[i];
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
    }
    while(flag){
    for(i=0;i<n;i++){
        if(bt[i]==0)
            continue;
        if(bt[i]>=timeslice){
            bt[i]-=timeslice;
            temp+=timeslice;
            tat[i]=temp;
        }
        else if(bt[i]<timeslice){
            temp+=bt[i];
            tat[i]=temp;
            bt[i]=0;
        }
    }
    c=0;
    for(j=0;j<n;j++)
        if(bt[j]!=0){
            c=1;
            break;
        }
    if(c==0)
        flag=0;
    }
    for(i=0;i<n;i++)
        wt[i]=tat[i]-bt1[i];
}
void awt_and_atat(){
    float awt,atat;
    int twt=0,ttat=0;
    int i,j;
    printf("The waiting time and turnaround time are:\n ");
    for(i=0;i<n;i++){
        printf("\nP%d\t%d\t%d",i,wt[i],tat[i]);
        twt+=wt[i];
        ttat+=tat[i];
    }
    awt=(float)twt/n;
    atat=(float)ttat/n;
    printf("\nThe average waiting time: %f\n",awt);
    printf("The average turnaround time: %f",atat);
}
int main()
{
    int i;
    printf("Enter the no of process: ");
    scanf("%d",&n);
    printf("Enter the burst time of each process: ");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);
    printf("Enter the timeslice: ");
    scanf("%d",&timeslice);
    wt_and_tat();
    awt_and_atat();
    return 0;
}
