#include<stdio.h>
int main()
{
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
printf("Etnter total number of processes(maximum 20):");
scanf("%d",&n);
printf("\n Enter process Burst Time\n");
for(i=0;i<n;i++)
{
	printf("P[%d]: ",i+1);
	scanf("%d",&bt[i]);
	
}
	wt[0]=0;//waiting time for first time process is 0
	for(i=0;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
		
		wt[i]+=bt[j];
	}
		
	}
	
	printf("\n Process \t \t Burst time \t wasting time\t Turnaroud Time");
	//calculating turn around time 
	
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		printf("\n P[%d]\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
		
	}
	

avwt=avwt/n;
avtat=avtat/n;
printf("\n\n Average Waiting Time: %d",avwt);
printf("\n\n Average Turnaround Time: %d\n",avtat);
return 0;
}
