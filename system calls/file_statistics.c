#include<stdio.h> 
#include<stdlib.h> 
#include<sys/stat.h> 
void main() 
{ 
char file[50]; 
struct stat *nfile; 
nfile=(struct stat*)malloc(sizeof(struct stat)); 
printf("Enter the file name: "); 
scanf("%s",file); 
stat(file,nfile); 
printf("Last access time : %ld\n",nfile->st_atime); 
printf("Inode no : %ld\n",nfile->st_ino); 
printf("Block size : %ld\n",nfile->st_blksize); 
printf("Access mode : %d\n",nfile->st_mode); 
printf("User id : %d\n",nfile->st_uid); 
printf("Group id : %d\n",nfile->st_gid); 
printf("Devide id : %ld\n",nfile->st_dev); 
} 