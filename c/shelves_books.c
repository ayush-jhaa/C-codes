#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, s, p, b, i = 0, cnt = 0;
    int **arr;


    arr = (int **)malloc(200 * sizeof(int *));
    for (int i = 0; i < 200; i++) {
        arr[i] = (int *)malloc(100 * sizeof(int));
    }

    while (1) {
        printf("1. enter the shelf and page 2. print the page of book on specific shelf 3. print the books on shelf\n");
        printf("enter the x value: ");
        scanf("%d", &x);

        if (x == 1) {
            printf("enter the shelf no.");
            scanf("%d", &s);
            printf("enter the no. of pages in book");
            scanf("%d", &p);
            for (int j = 0; j < 100; j++) {
                if (arr[s][j] == 0) {
                    arr[s][j] = p;
                    break;
                }
            }
        } else if (x == 2) {
            printf("enter the shelf no.");
            scanf("%d", &s);
            printf("enter the book no.");
            scanf("%d", &b);

            if (arr[s][b] == 0) {
                printf("book not present\n");
            } else {
                printf("shelf %d book no. %d contains: %d pages", s, b, arr[s][b]);
                printf("\n");
            }
        } else if (x == 3) {
            printf("enter the shelf no.");
            scanf("%d", &s);
            cnt = 0;
            for (i = 0; i < 100; i++) {
                if (arr[s][i] != 0) {
                    cnt++;
                }
            }

            if (cnt == 0) {
                printf("book not present there\n");
            } else {
                printf("no. of books in a shelf no. %d is : %d\n", s, cnt);
            }
        } else {
            printf("wrong input\n");
        }
    }

    // Free the allocated memory
    for (int i = 0; i < 200; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
