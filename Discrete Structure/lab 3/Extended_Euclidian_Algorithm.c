// Extended Euclidean Algorithm with step-by-step output
// This program calculates the GCD of two numbers and finds x and y such that ax + by = gcd(a, b)
// It also prints the steps of the algorithm in a tabular format.


#include <stdio.h>

int gcdExtended(int a, int b, int *x, int *y) {
    int x_prev = 1, y_prev = 0; // For a
    int x_curr = 0, y_curr = 1; // For b
    int temp_a = a, temp_b = b; // Store original a, b
    int step = 0;

    printf("\nStep-by-Step Extended Euclidean Algorithm:\n");
    printf("Step |  a  |  b  |  q  |  x  |  y  | GCD\n");
    printf("-----|-----|-----|-----|-----|-----|-----\n");

    while (b != 0) {
        int quotient = a / b;
        int temp = b;
        b = a % b;
        a = temp;

        int temp_x = x_curr;
        x_curr = x_prev - quotient * x_curr;
        x_prev = temp_x;

        int temp_y = y_curr;
        y_curr = y_prev - quotient * y_curr;
        y_prev = temp_y;

        // Print step with correct x, y (previous step’s values)
        printf("%4d |%4d |%4d |%4d |%4d |%4d |%4d\n", 
               step, a, b, quotient, x_prev, y_prev, a);
        step++;
    }

    // Assign final x, y from second-to-last step
    *x = x_prev;
    *y = y_prev;

    if (a < 0) {
        a = -a;
        *x = -*x;
        *y = -*y;
    }

    printf("-----|-----|-----|-----|-----|-----|-----\n");
    printf("Final GCD(%d, %d) = %d, x = %d, y = %d\n", temp_a, temp_b, a, *x, *y);

    return a;
}

int main() {
    int a, b, x, y;
    printf("Enter the values for a and b: ");
    scanf("%d %d", &a, &b);

    int g = gcdExtended(a, b, &x, &y);
    printf("\nVerification: %d * %d + %d * %d = %d\n", a, x, b, y, g);

    return 0;
}