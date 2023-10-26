#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2) {
            return (*s1 > *s2) ? 1 : -1;
        }
        s1++;
        s2++;
    }

    return 0; // Strings are equal.
}

int main() {
     char s1[20] ;
    scanf("%s",s1);
    __fpurge(stdin);
     char s2[20] ;
    scanf("%s",s2);

    int result = my_strcmp(s1, s2);

    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result < 0) {
        printf("String 1 is less than String 2.\n");
    } else {
        printf("String 1 is greater than String 2.\n");
    }

return 0;
}
