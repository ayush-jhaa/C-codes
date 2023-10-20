#include <stdio.h>
#include <string.h>

void palindrome(char str[]) {
    char *p, *q;
    int palin;
    p = str;
    q = str + strlen(str) - 1;
    
    while (p < q) {
        palin = 0;
        if (*p == *q) {
            palin = 1;
            p++;
            q--;
        } else {
            break;
        }
    }
    
    if (palin == 0) {
        printf("not palindrome");
    } else {
        printf("palindrome");
    }
}

int main() {
    char str[20];
    scanf("%s", str);
    palindrome(str);
    return 0;
}
