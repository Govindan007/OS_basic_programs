#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#define MAX 3 
int i = 0, j = 0, a[MAX], s = 0; 
void producer(); 
void consumer(); 
int main() { 
int c; 
while (1) { 
printf("\nMENULIST\n\n"); 
printf("1. Producer\n"); 
printf("2. Consumer\n"); 
printf("3. Exit\n\n"); 
printf("Enter Your Choice: "); 
scanf("%d", &c); 
switch (c) { 
case 1: producer(); break; 
case 2: consumer(); break; 
case 3: exit(0); 
default: printf("Invalid choice!\n"); 
} 
} 
} 
void producer() { 
if (s == MAX) { 
printf("\nBuffer Is Full\n"); 
sleep(1); 
} else { 
printf("Enter The Element To Be Produced: "); 
scanf("%d", &a[i]); 
printf("\n%d Is Produced\n", a[i]); 
i = (i + 1) % MAX; 
s++; 
} 
} 
void consumer() { 
if (s == 0) { 
printf("\nBuffer Is Empty\n"); 
sleep(1); 
} else { 
printf("\n%d Is Consumed\n", a[j]); 
j = (j + 1) % MAX; 
s--; 
} 
} 