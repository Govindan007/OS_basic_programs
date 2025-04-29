#include <stdio.h> 
int main() { 
    int frameCount, n; 
    printf("Enter the number of frames: "); 
    scanf("%d", &frameCount); 
    printf("Enter the number of page requests: "); 
    scanf("%d", &n); 
    int pages[n], frames[frameCount], freq[frameCount], recent[frameCount], pageFaults = 0; 
    printf("Enter the page string: "); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &pages[i]); 
    for (int i = 0; i < frameCount; i++) { 
        frames[i] = -1; 
        freq[i] = 0; 
        recent[i] = -1; 
    } 
    printf("\nPage Frames:\n"); 
    for (int i = 0; i < n; i++) { 
        int found = 0; 
        for (int j = 0; j < frameCount; j++) { 
            if (frames[j] == pages[i]) { 
                found = 1; 
                freq[j]++;          
                recent[j] = i 
                break; 
            } 
        } 
        
 
 
 
 
 
 
 if (!found) { 
            pageFaults++; 
            int placed = 0; 
            for (int j = 0; j < frameCount; j++) { 
                if (frames[j] == -1) { 
                    frames[j] = pages[i]; 
                    freq[j] = 1; 
                    recent[j] = i; 
                    placed = 1; 
                    break; 
                } 
            } 
            if (!placed) { 
                int minFreq = freq[0], minIndex = 0; 
                for (int j = 1; j < frameCount; j++) { 
                    if (freq[j] < minFreq || (freq[j] == minFreq && recent[j] < recent[minIndex])) { 
                        minFreq = freq[j]; 
                        minIndex = j; 
                    } 
                } 
 
                frames[minIndex] = pages[i]; 
                freq[minIndex] = 1; 
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
 
    printf("\nTotal Page Faults (LFU) = %d\n", pageFaults); 
    return 0; 
} 