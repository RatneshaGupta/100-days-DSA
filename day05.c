//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. 
//Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], merged[200];
    int i = 0, j = 0, k = 0;

    // Input for first server log
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Input for second server log
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;

    // Merge both logs
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            merged[k] = a[i];
            i++;
        } else {
            merged[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from server 1
    while (i < p) {
        merged[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from server 2
    while (j < q) {
        merged[k] = b[j];
        j++;
        k++;
    }

    // Output merged log
    for (i = 0; i < k; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
