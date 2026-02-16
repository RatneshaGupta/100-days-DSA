//Problem: Given an array of integers, count the frequency of each distinct element and print the result.

#include <stdio.h>

int main() {
    int n;

    // Read size of array
    scanf("%d", &n);

    int arr[n];
    int visited[n];   // To mark counted elements

    // Initialize visited array with 0
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for(int i = 0; i < n; i++) {

        if(visited[i] == 1)   // Already counted
            continue;

        int count = 1;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;  // Mark as counted
            }
        }

        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}
