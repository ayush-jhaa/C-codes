#include<stdio.h>
#include<string.h>

char *mystrcat(char *dest,const char* src)
{
       int i=0,j=0;
       while(dest[j])
       {
            j++;
       }
       while(src[i])
       {
           dest[i+j]=src[i];
           i++;
       }

       dest[i+j]='\0';

       return dest;
}
int main()
{
    char src[10];
    puts("enter src");
    gets(src);

    char dest[30];
    puts("enter dest");
    gets(dest);

    mystrcat(dest,src);

    printf("%s",dest);
}
