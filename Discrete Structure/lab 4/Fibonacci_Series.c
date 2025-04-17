
// Fibonacci Series in C with Matrix Representation
// This program generates the Fibonacci series up to n terms and displays it in a matrix-like format.
// It uses an array to store the Fibonacci numbers and prints them in a structured way.

#include <stdio.h>

#define MAX_TERMS 100 // Maximum number of terms to prevent overflow

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;
    int fib[MAX_TERMS]; // Array to store Fibonacci terms

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Validate input
    if (n <= 0 || n > MAX_TERMS) {
        printf("Please enter a number between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    // Generate Fibonacci series and store in array
    if (n >= 1) {
        fib[0] = t1;
    }
    if (n >= 2) {
        fib[1] = t2;
    }
    for (int i = 2; i < n; i++) {
        nextTerm = t1 + t2;
        fib[i] = nextTerm;
        t1 = t2;
        t2 = nextTerm;
    }

    // Print as a matrix-like table
    printf("\nFibonacci Series (Matrix Representation):\n");
    printf("Index |");
    for (int i = 0; i < n; i++) {
        printf("%4d ", i);
    }
    printf("\n------|");
    for (int i = 0; i < n; i++) {
        printf("-----");
    }
    printf("\nValue |");
    for (int i = 0; i < n; i++) {
        printf("%4d ", fib[i]);
    }
    printf("\n");

    return 0;
}