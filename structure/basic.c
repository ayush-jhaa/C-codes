#include <stdio.h>
#include <stdlib.h>

struct str
{
    char name[20];
    int rollno;
    float marks;
};

int main()
{
    struct str *arr = NULL;
    int i = 0;

    arr = (struct str *)malloc(5 * sizeof(struct str));

    for (i = 0; i < 5; i++)
    {
        printf("Enter the details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", arr[i].name);  // Use %s for strings
        printf("Roll No: ");
        scanf("%d", &arr[i].rollno);
        printf("Marks: ");
        scanf("%f", &arr[i].marks);
    }

    printf("Student details:\n");
    for (i = 0; i < 5; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", arr[i].name);
        printf("Roll No: %d\n", arr[i].rollno);
        printf("Marks: %.2f\n", arr[i].marks);
    }

    free(arr); // Don't forget to free the allocated memory when you're done.

    return 0;
}
