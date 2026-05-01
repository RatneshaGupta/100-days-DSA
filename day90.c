//Problem StatementGiven n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

#include <stdio.h>

int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime + arr[i] <= maxTime) {
            currentTime += arr[i];
        } else {
            painters++;
            currentTime = arr[i];
        }
    }

    return painters <= k;
}

int minTime(int arr[], int n, int k) {
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low) low = arr[i]; // max board
        high += arr[i]; // total length
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));

    return 0;
}