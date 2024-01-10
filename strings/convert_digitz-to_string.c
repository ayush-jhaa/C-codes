#include <stdio.h>
#include <ctype.h>
#include <string.h>

void convertNumericToWords(const char *input) {
    const char *digitWords[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    while (*input) {
        if (isdigit(*input)) {
            int digit = *input - '0';
            if (digit >= 0 && digit <= 9) {
                printf("%s", digitWords[digit]);
            } else {
                printf("%c", *input);
            }
        } else {
            printf("%c", *input);
        }
        input++;
    }
}

int main() {
    const char input_str_1[] = "Hello 24India";
    printf("Input: %s\tOutput: ", input_str_1);
    convertNumericToWords(input_str_1);
    printf("\n");

    const char input_str_2[] = "Programming practice";
    printf("Input: %s\tOutput: ", input_str_2);
    convertNumericToWords(input_str_2);
    printf("\n");

    const char input_str_3[] = "Virtual34 Prog56ramming";
    printf("Input: %s\tOutput: ", input_str_3);
    convertNumericToWords(input_str_3);
    printf("\n");

    return 0;
}
