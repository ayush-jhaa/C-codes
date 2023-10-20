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

   while(q=strchr(q,p))
{
   memmove(q,q+1,strlen(q+1)+1);
}
   printf("%s",str);
}
