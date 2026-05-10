#include <stdio.h>

int main()
{
    int count, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0;
    int at[10], bt[10], tat[10], rt[10];          // fixed: added bt[10]

    printf("Enter total processes: ");
    scanf("%d", &n);
    remain = n;

    // fixed: separated input loop from scheduling loop
    for (count = 0; count < n; count++)
    {
        printf("Enter Arrival Time and Burst Time for Process %d: ", count + 1);
        scanf("%d %d", &at[count], &bt[count]);
        rt[count] = bt[count];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);                   // fixed: moved outside loops

    printf("\nProcess\t\tTurnaround Time\t\tWaiting Time\n");

    // fixed: correct for-loop syntax (removed bad outer count loop)
    for (time = 0, count = 0; remain != 0; )
    {
        if (rt[count] <= time_quantum && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= time_quantum;
            time += time_quantum;                 // fixed: typo time_qunatum
        }

        if (rt[count] == 0 && flag == 1)          // fixed: == not =, flag==1 not flag==0
        {
            remain--;
            tat[count] = time - at[count];        // fixed: removed time_at[], correct TAT
            printf("P[%d]\t\t%d\t\t\t%d\n",
                   count + 1,
                   tat[count],
                   tat[count] - bt[count]);       // fixed: wt = tat - bt
            wait_time += tat[count] - bt[count];  // fixed: correct formula
            turnaround_time += tat[count];
            flag = 0;
        }

        if (count == n - 1)                       // fixed: == not =
            count = 0;
        else if (at[count + 1] <= time)
            count++;
        else
            count = 0;
    }

    printf("\nAverage Waiting Time: %.2f", (float)wait_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)turnaround_time / n);

    return 0;
}
