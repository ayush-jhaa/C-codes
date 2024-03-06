#include <stdio.h>
#include <stdlib.h>

void getInput(int ***matrix, int *rows, int *cols) {
    printf("Enter the number of rows: ");
    scanf("%d", rows);

    printf("Enter the number of columns: ");
    scanf("%d", cols);

    *matrix = calloc(*rows, sizeof(int *));
    for (int i = 0; i < *rows; i++) {
        (*matrix)[i] = calloc(*cols, sizeof(int));
    }
}

void print(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void input(int ***matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("Enter matrix values for row %d:\n", i + 1);
        for (int j = 0; j < cols; j++) {
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}

void multiply_matrix(int ***result, int **m1, int **m2, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            (*result)[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                (*result)[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    int **matrix = NULL;
    int **matrix2 = NULL;
    int **result = NULL;
    int rows, cols;

    printf("First matrix...\n");
    getInput(&matrix, &rows, &cols);
    input(&matrix, rows, cols);

    printf("Second matrix...\n");
    getInput(&matrix2, &rows, &cols);
    input(&matrix2, rows, cols);

    print(matrix, rows, cols);
    print(matrix2, rows, cols);

    // Allocate memory for the result matrix
    result = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = calloc(cols, sizeof(int));
    }

    multiply_matrix(&result, matrix, matrix2, rows, cols);
    printf("Result matrix:\n");
    print(result, rows, cols);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix);
    free(matrix2);
    free(result);

    return 0;
}
