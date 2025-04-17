#include <stdio.h> 
#include <limits.h> 
int main() { 
    int n, i, j, temp, id[20], arrivalTime[20], burstTime[20], remainingTime[20]; 
    int completionTime[20], turnAroundTime[20], waitingTime[20], currentTime = 0, completed = 0, minIndex; 
    float totalTurnAroundTime = 0, totalWaitingTime = 0; 
    int gantt[100], ganttIndex = 0; 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
    for (i = 0; i < n; i++) { 
        id[i] = i + 1; 
        printf("\nEnter Arrival Time and Burst Time for Process %d: ", id[i]); 
        scanf("%d %d", &arrivalTime[i], &burstTime[i]); 
        remainingTime[i] = burstTime[i]; 
    } 
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++) { 
            if (arrivalTime[j] > arrivalTime[j + 1]) { 
                temp = arrivalTime[j]; arrivalTime[j] = arrivalTime[j + 1]; arrivalTime[j + 1] = temp; 
                temp = burstTime[j]; burstTime[j] = burstTime[j + 1]; burstTime[j + 1] = temp; 
                temp = remainingTime[j]; remainingTime[j] = remainingTime[j + 1]; remainingTime[j + 1] = temp; 
                temp = id[j]; id[j] = id[j + 1]; id[j + 1] = temp; 
            } 
        } 
    } 
    while (completed < n) { 
        minIndex = -1; 
        int minRemainingTime = INT_MAX; 
        for (i = 0; i < n; i++) { 
            if (arrivalTime[i] <= currentTime && remainingTime[i] > 0 && remainingTime[i] < minRemainingTime) { 
                minRemainingTime = remainingTime[i]; 
                minIndex = i; 
            } 
        } 
        if (minIndex != -1) { 
            gantt[ganttIndex++] = id[minIndex]; 
            remainingTime[minIndex]--; 
            currentTime++; 
            if (remainingTime[minIndex] == 0) { 
                completionTime[minIndex] = currentTime; 
                turnAroundTime[minIndex] = completionTime[minIndex] - arrivalTime[minIndex]; 
                waitingTime[minIndex] = turnAroundTime[minIndex] - burstTime[minIndex]; 
                totalTurnAroundTime += turnAroundTime[minIndex]; 
                totalWaitingTime += waitingTime[minIndex]; 
                completed++; 
            } 
        } else { 
            gantt[ganttIndex++] = -1; 
            currentTime++; 
        } 
    } 
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n"); 
    for (i = 0; i < n; i++) { 
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", id[i], arrivalTime[i], burstTime[i], completionTime[i], turnAroundTime[i], waitingTime[i]); 
    } 
    printf("\nAverage Turnaround Time: %.2f", totalTurnAroundTime / n); 
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n); 
    printf("\nGantt Chart:\n|"); 
    for (i = 0; i < ganttIndex; i++) { 
        if (gantt[i] == -1) printf(" IDLE |"); 
        else printf(" P%d |", gantt[i]); 
    } 
printf("\n"); 
return 0; 
}