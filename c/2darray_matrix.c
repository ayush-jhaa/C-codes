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

        printf("Enter values for row %d: ", i + 1);
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &((*matrix)[i][j]));
        }
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

int main() {
    int **matrix = NULL;
    int rows, cols;

    getInput(&matrix, &rows, &cols);
    print(matrix, rows, cols);

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
