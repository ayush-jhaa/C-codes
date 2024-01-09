#include<stdio.h>
#include<string.h>

int main()
{
   char s1[100]="This is vector india hello vector india";
   char s2[20]="india";
   char s3[20]="hyderabad";
   
   int l3=strlen(s3);
   int l2=strlen(s2);
   char *p=s1;
   
   while(p=strstr(p,s2))
   {

   memmove(p+l3,p+l2,strlen(p+l2)+1);
   strncpy(p,s3,l3);
    
   
   
   }
   printf("%s",s1);
}

//input:- this is vector india hello vector india
//output:- this is vector hyderabad hello vector hyderabad
