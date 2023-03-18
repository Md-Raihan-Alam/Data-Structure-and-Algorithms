#include <stdio.h>

int main() {
    int m1, n1, m2, n2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &m1, &n1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &m2, &n2);

    // Check if matrix multiplication is possible
    if (n1 != m2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    int A[m1][n1], B[m2][n2], C[m1][n2];

    // Input first matrix
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input second matrix
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize elements of product matrix to 0
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            C[i][j] = 0;
        }
    }

    // Multiply matrices
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            for(int k=0;k<n1;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    // Print the product matrix
    printf("Product of the two matrices:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
