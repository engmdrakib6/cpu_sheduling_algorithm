#include <stdio.h>

int main()
{
    int n, burstTime[20], waitTime[20], turnaroundTime[20], totalWaitTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    waitTime[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waitTime[i] = waitTime[i - 1] + burstTime[i - 1];
        totalWaitTime += waitTime[i];
    }

    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = burstTime[i] + waitTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaitTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);

    printf("\n\n-----------------------------------------------------------------\n");
		for(int i = 0; i<n; i++)
		{
			printf("|\tP%d\t",i+1);
			if(i+1 == n)
                printf("|");

		}
     printf("\n-----------------------------------------------------------------\n");

		for(int i = 0;i<n;i++)
		{
			if(i == 0)
			{
				printf("%d\t  \t%d",0,turnaroundTime[i]);
			}else {
				printf("\t  \t%d",turnaroundTime[i]);
			}
		}

    return 0;
}

