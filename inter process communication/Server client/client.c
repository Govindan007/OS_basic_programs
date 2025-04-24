#include <stdio.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdlib.h> 
#include <unistd.h>   
#define SHMSZ 27   
int main() { 
int shmid;          
key_t key = 6780;   
char *shm, *s;      
if ((shmid = shmget(key, SHMSZ, 0666)) < 0) { 
perror("Error On SHMGET");  
exit(1); 
} 
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { 
perror("Error On SHMAT");  
exit(1); 
} 
putchar('\n'); 
for (s = shm; *s != '\0'; s++) { 
putchar(*s); 
printf(" "); 
} 
putchar('\n'); 
putchar('\n'); 
*shm = '*';  
shmdt(shm);  
return 0; 
} 