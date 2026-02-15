//Problem: Given a matrix, calculate the sum of its primary diagonal elements. 
//The primary diagonal consists of elements where row index equals column index.

#include <stdio.h>

int main() {
    int m, n, i, j, sum = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal = %d", sum);

    return 0;
}
