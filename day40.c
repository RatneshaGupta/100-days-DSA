//Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {

    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements from heap
    for (int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]);   // move max to end
        heapify(arr, i, 0);       // heapify reduced heap
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {

    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}