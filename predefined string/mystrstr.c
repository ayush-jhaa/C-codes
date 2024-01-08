#include <stdio.h>

char *user_defined_strstr(const char *haystack, const char *needle) {
    while (*haystack != '\0') {
        const char *hay = haystack;
        const char *need = needle;

        while (*need != '\0' && *hay == *need) {
            hay++;
            need++;
        }

        if (*need == '\0') {
            return (char *)haystack;  // substring found
        }

        haystack++;
    }

    return NULL;  // substring not found
}

int main() {
    const char *text = "Hello, World!";
    const char *substring = "World";

    char *result = user_defined_strstr(text, substring);

    if (result != NULL) {
        printf("Substring '%s' found at position: %ld\n", substring, result - text);
    } else {
        printf("Substring '%s' not found in the string.\n", substring);
    }

    return 0;
}
