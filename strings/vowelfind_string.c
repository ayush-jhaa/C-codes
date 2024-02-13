#include <stdio.h>
#include<string.h>

void isvowel(char *x)
{
    char *p=x;

    char str[10]="AaEeIiOoUu";
    int i=0,count=0;

    while(p[i])
    {
        if(strchr(str,p[i]) !=NULL)
        {
            count++;
        }
        i++;
    }
    printf("%d ",count);
}

int main()
{
    char p[]="i am an student";

    char *q=strtok(p," ");

    while(q !=NULL)
    {
        isvowel(q);
        q=strtok(NULL," ");
    }

    return 0;
}
