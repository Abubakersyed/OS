#include<stdio.h>

int main()
{
    int bt[20], p[20], wt[20], tat[20], pr[20];
    int i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;

    // Input number of processes
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority
    printf("\nEnter Burst Time and Priority\n");

    for(i = 0; i < n; i++)
    {
        printf("\nProcess P[%d]\n", i + 1);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);

        p[i] = i + 1;
    }

    // Sorting according to priority
    // Smaller priority number = higher priority

    for(i = 0; i < n; i++)
    {
        pos = i;

        for(j = i + 1; j < n; j++)
        {
            if(pr[j] < pr[pos])
            {
                pos = j;
            }
        }

        // Swap priority
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        // Swap burst time
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // Swap process number
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // Waiting Time calculation
    wt[0] = 0;

    for(i = 1; i < n; i++)
    {
        wt[i] = 0;

        for(j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }

        total += wt[i];
    }

    avg_wt = (float)total/n;

    // Turn Around Time calculation
    total = 0;

    printf("\nProcess\t Burst Time\t Priority\t Waiting Time\t Turnaround Time");

    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];

        total += tat[i];

        printf("\nP[%d]\t\t %d\t\t %d\t\t %d\t\t %d",
               p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    avg_tat = (float)total/n;

    printf("\n\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
