#include <stdio.h> 
#include <stdlib.h> 
int main() { 
    int n, head, max_cylinder, seek_time = 0, i, prev, index = 0;  
    printf("Enter total number of disk requests: "); 
    scanf("%d", &n);  
    int requests[n + 1];  
    printf("Enter disk requests: "); 
    for (i = 0; i < n; i++) { 
        scanf("%d", &requests[i]); 
    }  
    printf("Enter initial head position: "); 
    scanf("%d", &head);  
    printf("Enter maximum cylinder number: "); 
    scanf("%d", &max_cylinder);  
    requests[n] = max_cylinder;   
    n++;  
    for (i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (requests[i] > requests[j]) { 
                int temp = requests[i]; 
                requests[i] = requests[j]; 
                requests[j] = temp; 
            } 
        } 
    } 
    while (index < n && requests[index] < head) { 
        index++; 
    } 
    prev = head; 
    printf("\nSCAN Order: ");  
    
 
 
for (i = index; i < n; i++) { 
printf("%d -> ", requests[i]); 
seek_time += abs(requests[i] - prev); 
prev = requests[i]; 
}  
for (i = index - 1; i >= 0; i--) { 
printf("%d -> ", requests[i]); 
seek_time += abs(requests[i] - prev); 
prev = requests[i]; 
}  
printf("End\nTotal Seek Time: %d\n", seek_time);  
return 0; 
} 