// Program to find union and intersection of two 2x2 matrices using logical operations
// using bitwise operations for union and intersection

#include <stdio.h>
#define SIZE 2

void enterMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void unionOfMatrices(int matrixA[SIZE][SIZE], int matrixB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matrixA[i][j] | matrixB[i][j]; // Logical OR for union
        }
    }
}

void intersectionOfMatrices(int matrixA[SIZE][SIZE], int matrixB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matrixA[i][j] & matrixB[i][j]; // Logical AND for intersection
        }
    }
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], unionResult[SIZE][SIZE], intersectionResult[SIZE][SIZE];

    printf("Enter elements of Matrix A (%d x %d):\n", SIZE, SIZE);
    enterMatrix(A);

    printf("Enter elements of Matrix B (%d x %d):\n", SIZE, SIZE);
    enterMatrix(B);

    printf("Matrix A:\n");
    printMatrix(A);

    printf("Matrix B:\n");
    printMatrix(B);

    unionOfMatrices(A, B, unionResult);
    printf("Union of Matrix A & Matrix B:\n");
    printMatrix(unionResult);

    intersectionOfMatrices(A, B, intersectionResult);
    printf("Intersection of Matrix A & Matrix B:\n");
    printMatrix(intersectionResult);

    return 0;
}