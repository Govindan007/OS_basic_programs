#include <stdio.h> 
int main() { 
    int frameCount, n; 
    printf("Enter the number of frames: "); 
    scanf("%d", &frameCount); 
    printf("Enter the number of page requests: "); 
    scanf("%d", &n); 
    int pages[n], frames[frameCount], recent[frameCount], pageFaults = 0; 
    printf("Enter the page string: "); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &pages[i]); 
    for (int i = 0; i < frameCount; i++) 
        frames[i] = -1; 
    printf("\nPage Frames:\n"); 
    for (int i = 0; i < n; i++) { 
        int found = 0; 
        for (int j = 0; j < frameCount; j++) { 
            if (frames[j] == pages[i]) { 
                found = 1; 
                recent[j] = i;  
                break; 
            } 
        } 
        if (!found) { 
            pageFaults++; 
            int placed = 0; 
            for (int j = 0; j < frameCount; j++) { 
                if (frames[j] == -1) { 
                    frames[j] = pages[i]; 
                    recent[j] = i; 
                    placed = 1; 
                    break; 
                } 
            } 
 
            if (!placed) { 
                int minIndex = 0; 
                for (int j = 1; j < frameCount; j++) { 
                    if (recent[j] < recent[minIndex]) 
                        minIndex = j; 
                } 
                frames[minIndex] = pages[i]; 
                recent[minIndex] = i; 
            } 
        } 
        for (int j = 0; j < frameCount; j++) { 
            if (frames[j] != -1) 
                printf("%d  ", frames[j]); 
            else 
                printf("-  "); 
        } 
        printf("\n"); 
    } 
    printf("\nTotal Page Faults (LRU) = %d\n", pageFaults); 
    return 0; 
} 