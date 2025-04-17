// C program to demonstrate the use of binary representation for sets
// using bitwise operations for union and intersection

#include <stdio.h>

#define MAX_ELEMENTS 6

void inputSetBinary(int set[]) {
    int n, element;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        if (element >= 0 && element < MAX_ELEMENTS) {
            set[element] = 1; // Mark element as present
        }
    }
}

void displaySetBinary(int set[]) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

void unionSetBinary(int setA[], int setB[], int resultSet[]) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        resultSet[i] = setA[i] | setB[i]; // Logical OR for union
    }
}

void intersectionSetBinary(int setA[], int setB[], int resultSet[]) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        resultSet[i] = setA[i] & setB[i]; // Logical AND for intersection
    }
}

int main() {
    int setA[MAX_ELEMENTS] = {0}; // Initialize set A to all 0s
    int setB[MAX_ELEMENTS] = {0}; // Initialize set B to all 0s
    int resultSet[MAX_ELEMENTS] = {0}; // Initialize result set to all 0s

    printf("Enter elements of set A (Binary Representation):\n");
    inputSetBinary(setA);
    printf("Set A: ");
    displaySetBinary(setA);

    printf("Enter elements of set B (Binary Representation):\n");
    inputSetBinary(setB);
    printf("Set B: ");
    displaySetBinary(setB);

    // Union
    unionSetBinary(setA, setB, resultSet);
    printf("Union of set A & set B: ");
    displaySetBinary(resultSet);

    // Intersection
    intersectionSetBinary(setA, setB, resultSet);
    printf("Intersection of set A & set B: ");
    displaySetBinary(resultSet);

    return 0;
}
