#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
int main() { 
    int sum = 0, i, n; 
    pid_t pid; 
    printf("Enter the number: "); 
    scanf("%d", &n); 
    pid = fork(); 
    if (pid < 0) { 
        printf("Error creating process\n"); 
        return 1; 
    } 
    else if (pid > 0) {  // Parent process 
        for (i = 0; i < n; i++) { 
            sum += i; 
        } 
        printf("Parent Sum: %d\n", sum); 
    } 
    else {  // Child process 
        int diff = 0; 
        for (i = 0; i < n; i++) { 
            diff -= i; 
        } 
        printf("Child Diff: %d\n", diff); 
    } 
    return 0; 
}