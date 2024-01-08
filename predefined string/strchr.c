/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

char* strchar(const char* str, int ch) {
    while (*str != '\0') {
        if (*str == ch) {
            return (char*)str;  // Found the character, return its address
        }
        str++;
    }

    return NULL;  // Character not found
}

int main() {
    const char* text = "Hello, World!";
    char searchChar = 'x';

    char* result = strchar(text, searchChar);

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", searchChar, result - text);
    } else {
        printf("Character '%c' not found in the string.\n", searchChar);
    }

    return 0;
}
