// Program 2
#include <stdio.h>

#define SIZE 5

// printMatrix displays what the matrix looks like
void printMatrix(int matrix[SIZE][SIZE]){
    // Loops through the matrix and prints each element
    for (int i = 0; i < SIZE; i++) {
        // Prints each element in the current row with a width of 4 characters
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// addMatrices adds two matrices and stores the result in a third matrix
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loops through the matrices and adds the corresponding elements
    for (int i = 0; i < SIZE; i++) {
        // Adds corresponding elements from m1 and m2 and stores it in result
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// multiplyMatrices multiplies two matrices and stores the result in a third matrix
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loops through the matrices and multiples them using multiplication
    for (int i = 0; i < SIZE; i++) {
        // Initialize the result matrix element to 0 before adding the products
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            // Calculates the dot product of the i-th row of m1 and the j-th column of m2
            for (int k = 0; k < SIZE; k++) {
                result[i][j] = result[i][j] + (m1[i][k] * m2[k][j]);
            }
        }
    }
}

// transposeMatrix transposes a matrix and stores the result in a second matrix
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Loops through the matrix and assigns the transposed values to the result matrix
    for (int i = 0; i < SIZE; i++) {
        // Assigns the value at position (i, j) in the original matrix to position (j, i) in the result matrix
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Main function to demonstrate the matrix operations
int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5}, 
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}, 
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE];

    printf("Matrix 1:\n");
    printMatrix(m1);

    printf("Matrix 2:\n");
    printMatrix(m2);

    printf("Sum of matrices:\n");
    addMatrices(m1, m2, result);
    printMatrix(result);

    printf("Product of matrices:\n");
    multiplyMatrices(m1, m2, result);
    printMatrix(result);

    printf("Transpose of Matrix 1:\n");
    transposeMatrix(m1, result);
    printMatrix(result);

    return 0;
}