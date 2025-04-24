#include <stdio.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 
int main() { 
int shmid; 
key_t key = 7800; 
int *shm, *it; 
int i, j, n, pid, temp; 
printf("Enter The Count: "); 
scanf("%d", &n);  
size_t shmsz = n * sizeof(int); 
if ((shmid = shmget(key, shmsz, IPC_CREAT | 0666)) < 0) { 
perror("Error On SHMGET"); 
exit(1); 
} 
if ((shm = shmat(shmid, NULL, 0)) == (int *)-1) { 
perror("Error On SHMAT"); 
exit(1); 
} 
it = shm; 
printf("Enter The Elements: "); 
for (i = 0; i < n; i++) 
scanf("%d", &it[i]); 
printf("\nEntered Elements Are: "); 
for (i = 0; i < n; i++) 
printf("%d ", it[i]); 
printf("\n"); 
    pid = fork(); 
    if (pid < 0) { 
        perror("Fork Failed"); 
        exit(1); 
    } else if (pid > 0) { 
        for (i = 0; i < n; i++) { 
            for (j = i + 1; j < n; j++) { 
                if (it[i] > it[j]) { 
                    temp = it[i]; 
                    it[i] = it[j]; 
                    it[j] = temp; 
                } 
            } 
        } 
        wait(NULL); 
 
        shmdt(shm); 
        shmctl(shmid, IPC_RMID, NULL); 
    } else { 
        sleep(1); 
        printf("Sorted Elements Are: "); 
        for (i = 0; i < n; i++) 
            printf("%d ", it[i]); 
        printf("\n"); 
 
        shmdt(shm); 
    } 
 
    return 0; 
} 