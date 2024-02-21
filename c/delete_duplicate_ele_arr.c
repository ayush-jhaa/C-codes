#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr; // Declare pointer to int to hold the array dynamically
    int i, j, k, size;

    printf("Define the number of elements in the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("\nEnter %d elements of the array:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size;) {
            if (arr[j] == arr[i]) {
                for (k = j; k < size; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; // Decrease size when duplicate is found
            } else {
                j++;
            }
        }
    }

    // Resize the array to remove the duplicate elements completely
    arr = (int *)realloc(arr, size * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Display array after removing duplicates
    printf("\nArray elements after removal of duplicates: ");
    for (i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
