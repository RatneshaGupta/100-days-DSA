//Problem Statement Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

#include <stdio.h>

int maxLenZeroSum(int arr[], int n) {
    int maxLen = 0;
    int sum = 0;

    // Hash map using array (for simplicity)
    // Assuming sum range is within -10000 to 10000
    int hash[20001];
    
    for (int i = 0; i < 20001; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum = 0 → subarray from 0 to i
        if (sum == 0) {
            maxLen = i + 1;
        }

        // If sum seen before
        if (hash[sum + 10000] != -1) {
            int prevIndex = hash[sum + 10000];
            int len = i - prevIndex;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            hash[sum + 10000] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));

    return 0;
}