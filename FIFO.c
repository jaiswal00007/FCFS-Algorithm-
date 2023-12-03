#include<stdio.h>
int main()
{
    int n,bt[25];
    printf("Enter no. of Process:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter burst time for Process %d:",i+1);
        scanf("%d",&bt[i]);
    }
    //Calculating waiting time
    int wt[n],i;
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
    }
    float tat=0.00,twt=0.00;
    printf("Process Id      Burst Time      TurnAround time     Waiting time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]\t\t",i+1);
        printf("%d\t\t",bt[i]);
        printf("%d\t\t",wt[i]);
        printf("%d\t\t",wt[i]+bt[i]);
        printf("\n");
        tat+=wt[i];
        twt+=wt[i]+bt[i];
    }
    float awt=twt/n;
    float atat=tat/n;
    printf("Average Waiting Time: %.2f\n",awt);
    printf("Average TurnAround Time: %.2f",atat);
    return 0;
}
