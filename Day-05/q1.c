/*A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. 
Your task is to create a single chronological log that preserves the correct order of arrivals.*/

#include <stdio.h>

int main() {
    int p, q;

    // Read size of first log
    scanf("%d", &p);
    int a[p];
    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Read size of second log
    scanf("%d", &q);
    int b[q];
    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    // Merge both logs
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // Print remaining elements of first log
    while(i < p) {
        printf("%d ", a[i]);
        i++;
    }

    // Print remaining elements of second log
    while(j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}