//Problem: Implement Binary Search Iterative - Implement the algorithm.

#include <stdio.h>

// Function to sort array (Bubble Sort for simplicity)
void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Iterative Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    sort(arr, n);

    // Step 2: Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Optional: Binary Search
    /*
    int target;
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("\nFound at index %d", result);
    else
        printf("\nNot found");
    */

    return 0;
}