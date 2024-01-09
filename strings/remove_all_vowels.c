#include <stdio.h>
#include <string.h>

void removeVowels(char *str);

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    removeVowels(str);

    printf("String without vowels: %s\n", str);

    return 0;
}

void removeVowels(char *str) {
    char vowels[] = "aeiouAEIOU";
    int len = strlen(str);
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';  // Add null terminator to the end of the modified string
}
