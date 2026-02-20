//Problem: Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;

    // Read number of elements
    scanf("%d", &n);

    if (n < 2) {
        printf("Need at least two elements\n");
        return 0;
    }

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_sum = arr[left] + arr[right];
    int min_left = left;
    int min_right = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        // Update minimum sum if closer to zero
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_left = left;
            min_right = right;
        }

        // Move pointers
        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", arr[min_left], arr[min_right]);

    return 0;
}
