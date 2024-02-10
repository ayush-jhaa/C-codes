#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        int *ptr = (int *)malloc(sizeof(int)); // Allocate memory dynamically
        if (ptr == NULL) {
            printf("Memory allocation failed. Exiting program.\n");
            exit(1);
        }
        // Do some work with ptr
    }
    return 0;
}
