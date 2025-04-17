// Factorial.c
// This program calculates the factorial of a non-negative integer using recursion.
// It includes detailed print statements to show the steps of the computation.
// The maximum input is limited to 20 to prevent overflow of the unsigned long long type.
// The program also includes input validation to ensure the user enters a valid non-negative integer.
// The factorial of a number n is the product of all positive integers less than or equal to n.
// The factorial of 0 is defined to be 1.
// The program uses a recursive function to compute the factorial and prints each step of the recursion.
// The final result is printed at the end.
// The program is designed to be user-friendly and provides clear instructions for input.
// The program is written in C and includes necessary header files for input/output operations.

#include <stdio.h>

unsigned long long factorial(unsigned int n, int step) {
    printf("Step %d: n = %u\n", step, n);
    if (n == 0 || n == 1) {
        printf("Base case reached: %u! = 1\n", n);
        return 1;
    }
    unsigned long long result = n * factorial(n - 1, step + 1);
    printf("Step %d: %u * %u! = %llu\n", step, n, n - 1, result);
    return result;
}

int main() {
    unsigned int n;
    printf("Enter a non-negative integer (max 20): ");
    scanf("%u", &n);

    if (n > 20) {
        printf("Input too large. Maximum is 20 to avoid overflow.\n");
        return 1;
    }

    printf("\nFactorial Computation Steps:\n");
    unsigned long long result = factorial(n, 0);
    printf("\nFinal: Factorial of %u is %llu\n", n, result);

    return 0;
}