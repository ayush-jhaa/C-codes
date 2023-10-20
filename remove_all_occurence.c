#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
int main()
{
   char str[20];
   scanf("%s",str);
   __fpurge(stdin);
   int i=0;
   char *q=str;

   char p;
   puts("enter the char to remove");

   scanf("%c",&p);

   while(str[i])
   {
        if(str[i]==p)
        {
            memmove(q+i,q+i+1,strlen(q+i+1)+1);
        }

        else
        ++i;
   }

   printf("%s",str);
}
