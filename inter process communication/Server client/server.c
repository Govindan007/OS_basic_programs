#include <stdio.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdlib.h> 
#include <unistd.h> 
#define SHMSZ 27   
int main() { 
int shmid;          
char c;             
key_t key = 6780;   
char *shm, *s;      
if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) { 
perror("Error On SHMGET");  
exit(1); 
} 
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { 
perror("Error On SHMAT");  
exit(1); 
} 
s = shm;  
for (c = 'a'; c <= 'z'; c++) 
*s++ = c;  
*s = '\0';   
putchar('\n'); 
for (s = shm; *s != '\0'; s++) { 
putchar(*s); 
printf(" "); 
} 
putchar('\n'); 
putchar('\n'); 
while (*shm != '*') 
sleep(1);  
shmdt(shm);                    
shmctl(shmid, IPC_RMID, NULL);  
return 0; 
} 