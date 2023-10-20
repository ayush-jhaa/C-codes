#include<stdio.h>
#include<string.h>

int main()
{
   char s1[30]="ABCDABCABCDE";
   char s2[10]="BCD";

   char *p=s1;
   char * found=NULL;
   int l2=strlen(s2);

   while(p=strstr(p,s2))
   {
        found=p;
        p +=l2;
   }

   if(found)
   {
       memmove(found,found+l2,strlen(found+l2)+1);
   }
   printf("%s",s1);

}
