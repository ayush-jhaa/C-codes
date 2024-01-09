/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

void isvowel(char *str);

int main() {
    char str[50];
    //fgets(str, 50, stdin);
    scanf("%[^\n]s",str);
    isvowel(str);
}

void isvowel(char *str) {
    char *p = str, *q = str, *r = NULL;
    int found = 0,again=0;

    while ((q = strchr(q, ' '))) {
        r = q;
        --r;

        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
            if (*r == 'a' || *r == 'e' || *r == 'i' || *r == 'o' || *r == 'u') {
                found = 1;
            }
        }

        while (p <= r) {
            if (found) {
                printf("%c", *p);
            }
            ++p;
             
        }
        
        if(found)
        printf("\n");

        found=0;
        p++;
        q++;
        
       
        
    }
   printf("\n");
    
    if(*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u')
        {
            int num=strlen(p);
            r=p+(num-1);
            
             if (*r == 'a' || *r == 'e' || *r == 'i' || *r == 'o' || *r == 'u')
             again=1;
            
            while(p<=r)
            {
                 if (again) {
                printf("%c", *p);
            }
            ++p;
            }
        }
}
