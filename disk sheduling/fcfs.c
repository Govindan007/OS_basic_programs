#include <stdio.h> 
#include <stdlib.h> 
int main() { 
int n, head, seek_time = 0, prev;  
printf("Enter total number of disk requests: "); 
scanf("%d", &n);  
int requests[n];  
printf("Enter disk requests: "); 
for (int i = 0; i < n; i++) { 
scanf("%d", &requests[i]); 
}  
printf("Enter initial head position: "); 
scanf("%d", &head);  
prev = head; 
printf("\nFCFS Order: ");  
for (int i = 0; i < n; i++) { 
printf("%d -> ", requests[i]); 
seek_time += abs(requests[i] - prev); 
prev = requests[i]; 
}  
printf("End\nTotal Seek Time: %d\n", seek_time);  
return 0; 
} 