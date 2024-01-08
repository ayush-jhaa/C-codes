#include <stdio.h>

char *user_defined_strrchr(const char *str, int ch) {
    const char *lastOccurrence = NULL;

    while (*str != '\0') {
        if (*str == ch) {
            lastOccurrence = str;
        }
        str++;
    }

    return (char *)lastOccurrence;
}

int main() {
    const char *text = "Hello, World!";
    char searchChar = 'o';

    char *result = user_defined_strrchr(text, searchChar);

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", searchChar, result - text);
    } else {
        printf("Character '%c' not found in the string.\n", searchChar);
    }

    return 0;
}
