#include <stdio.h> 
#include <limits.h> 
 
int main() { 
    int n, i, j, temp; 
    int id[20], arrivalTime[20], burstTime[20], remainingTime[20], priority[20]; 
    int completionTime[20], waitingTime[20], turnAroundTime[20]; 
    int isCompleted[20] = {0}; 
    float totalTurnAroundTime = 0, totalWaitingTime = 0; 
 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
    for (i = 0; i < n; i++) { 
        id[i] = i + 1; 
        printf("\nEnter Arrival Time, Burst Time, and Priority for Process %d: ", id[i]); 
        scanf("%d %d %d", &arrivalTime[i], &burstTime[i], &priority[i]); 
        remainingTime[i] = burstTime[i]; 
    } 
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++) { 
            if (arrivalTime[j] > arrivalTime[j + 1]) { 
                temp = arrivalTime[j]; arrivalTime[j] = arrivalTime[j + 1]; arrivalTime[j + 1] = temp; 
                temp = burstTime[j]; burstTime[j] = burstTime[j + 1]; burstTime[j + 1] = temp; 
                temp = remainingTime[j]; remainingTime[j] = remainingTime[j + 1]; remainingTime[j + 1] = temp; 
                temp = priority[j]; priority[j] = priority[j + 1]; priority[j + 1] = temp; 
                temp = id[j]; id[j] = id[j + 1]; id[j + 1] = temp; 
            } 
        } 
    } 
    int currentTime = 0, completed = 0, idx; 
    printf("\nGantt Chart:\n|"); 
    while (completed < n) { 
        int highestPriority = INT_MAX; 
        idx = -1; 
        for (i = 0; i < n; i++) { 
            if (arrivalTime[i] <= currentTime && !isCompleted[i] && priority[i] < highestPriority) { 
                highestPriority = priority[i]; 
                idx = i; 
            } 
        } 
        if (idx != -1) { 
            printf(" P%d (%d) |", id[idx], currentTime); 
            remainingTime[idx]--; 
            currentTime++; 
            if (remainingTime[idx] == 0) { 
                completionTime[idx] = currentTime; 
                turnAroundTime[idx] = completionTime[idx] - arrivalTime[idx]; 
                waitingTime[idx] = turnAroundTime[idx] - burstTime[idx]; 
                totalTurnAroundTime += turnAroundTime[idx]; 
                totalWaitingTime += waitingTime[idx]; 
                isCompleted[idx] = 1; 
                completed++; 
            } 
        } else { 
            printf(" Idle (%d) |", currentTime); 
            currentTime++; 
        } 
    } 
    printf(" %d |\n", currentTime); 
    printf("\nProcess\tPriority\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n"); 
    for (i = 0; i < n; i++) { 
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", id[i], priority[i], arrivalTime[i], burstTime[i], 
completionTime[i], turnAroundTime[i], waitingTime[i]); 
    } 
printf("\nAverage Turnaround Time: %.2f", totalTurnAroundTime / n); 
printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n); 
return 0; 
}