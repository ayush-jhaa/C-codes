
#include <stdio.h>

int main()
{
    char arr[20]="this is vector";
    char s1 [5]="is";
    char s2 [5]="AB";
    
    char *p=arr;
    int l=strlen(s2);
    
    while(p=strstr(p,s1))
    {
        strncpy(p,s2,l);
        p=p+l;
    }
    
    printf("%s",arr);
    return 0;
}
