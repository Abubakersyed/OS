#include<stdio.h>
void main()
{
	int bt[20],P[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
	printf("Enter number of Process: ");
	scanf("%d",&n);
	printf("\n Enter number of Burst time: \n");
	for(i=0;i<n;i++)
	{
		printf("P%d: ",i+1);
		scanf("%d",&bt[i]);
		P[i]=i+1;
		
	}//contains process number
	
	//sorting burst time in ascending order using selection sort
	
	for(i=0;i<n;i++)
	{
		pos=i;
		
		for(j=i+1;j<n;j++)
		{
			
			if(bt[j]<bt[pos])
			pos=j;
			
		}
		temp = bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		
			temp = P[i];
			P[i]=P[pos];
			P[pos]=temp;
		
		
	}
	
wt[0]=0;

//waiting time for first process will be Zero

//calculate wasting time 

for(i=1;i<n;i++)
{
	wt[i]=0;
	for(j=0;j<i;j++)
	wt[i]+=bt[j];
	total+=wt[i];
	
}

avg_wt=(float)total/n;
total=0;

printf("\nProcess\tBurst Time\tWaiting Time\tTurnaroud Time");
for(i=0;i<n;i++)
{
	tat[i]=bt[i]+wt[i];
	total+=tat[i];
	
	
	printf("P%d\t%d\t\t%d\t\t%d\n",P[i],bt[i],wt[i],tat[i]);
}
	avg_tat=(float)total/n;
	printf("\n\n Average Waiting Time: %.2f",avg_wt);
	printf("\n Average Turnaroud Time = %.2f\n",avg_tat);
	
	return 0;
}


