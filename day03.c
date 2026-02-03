//Problem: Implement linear search to find key k in an array. 
//Count and display the number of comparisons performed.

#include <stdio.h>

int main() {
    int n, i, k;
    int comparisons = 0;
    int found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}




