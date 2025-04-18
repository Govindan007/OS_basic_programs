#include <stdio.h> 
void firstfit(int p_size[], int n, int m_size[], int m) { 
    printf("\t\tFIRST FIT \n"); 
    int m_temp[m]; 
    for (int i = 0; i < m; i++) m_temp[i] = m_size[i]; 
    for(int i = 0; i < n; i++) { 
        int flag = 0; 
        for(int j = 0; j < m; j++) { 
            if(m_temp[j] >= p_size[i]) { 
                printf("%d ALLOCATED IN %d MEMORY BLOCK", p_size[i], m_temp[j]); 
                m_temp[j] -= p_size[i]; 
                printf(" => %d SPACE REMAINING \n", m_temp[j]); 
                flag = 1; 
                break; 
            } 
        } 
        if(flag == 0) printf("%d CANNOT BE ALLOCATED \n", p_size[i]); 
    } 
} 
void worstfit(int p_size[], int n, int m_size[], int m) { 
    printf("\t\tWORST FIT \n"); 
    int m_temp[m]; 
    for (int i = 0; i < m; i++) m_temp[i] = m_size[i]; 
    for(int i = 0; i < n; i++) { 
        int loc = -1; 
        for(int j = 0; j < m; j++) { 
            if(m_temp[j] >= p_size[i] && (loc == -1 || m_temp[j] > m_temp[loc])) loc = j; 
        } 
        if(loc != -1) { 
            printf("%d ALLOCATED IN %d MEMORY BLOCK", p_size[i], m_temp[loc]); 
            m_temp[loc] -= p_size[i]; 
            printf(" => %d SPACE REMAINING \n", m_temp[loc]); 
} else printf("%d CANNOT BE ALLOCATED \n", p_size[i]); 
} 
} 
void bestfit(int p_size[], int n, int m_size[], int m) { 
printf("\t\tBEST FIT \n"); 
int m_temp[m]; 
for (int i = 0; i < m; i++) m_temp[i] = m_size[i]; 
for(int i = 0; i < n; i++) { 
int loc = -1; 
for(int j = 0; j < m; j++) { 
if(m_temp[j] >= p_size[i] && (loc == -1 || m_temp[j] < m_temp[loc])) loc = j; 
} 
if(loc != -1) { 
printf("%d ALLOCATED IN %d MEMORY BLOCK", p_size[i], m_temp[loc]); 
m_temp[loc] -= p_size[i]; 
printf(" => %d SPACE REMAINING \n", m_temp[loc]); 
} else printf("%d CANNOT BE ALLOCATED \n", p_size[i]); 
} 
} 
int main() { 
int i, n, m; 
printf("ENTER THE NUMBER OF PROCESSES: "); 
scanf("%d", &n); 
int p_size[n]; 
printf("ENTER THE ARRAY OF PROCESS SIZES: "); 
for(i = 0; i < n; i++) scanf("%d", &p_size[i]); 
printf("ENTER THE NUMBER OF MEMORY BLOCKS: "); 
scanf("%d", &m); 
int m_size[m]; 
printf("ENTER THE ARRAY OF MEMORY BLOCK SIZES: "); 
for(i = 0; i < m; i++) scanf("%d", &m_size[i]); 
firstfit(p_size, n, m_size, m); 
bestfit(p_size, n, m_size, m); 
worstfit(p_size, n, m_size, m); 
return 0; 
} 