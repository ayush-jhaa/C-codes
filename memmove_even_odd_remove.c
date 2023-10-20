#include<stdio.h>
#include<string.h>
int main()
{
     char str[10];
     scanf("%s",str);
     char *p=str;
     int n,var=2;

      n=strlen(str);

      if(n%2 !=0)
      {
         p= str+strlen(str)/2;
         memmove(p,p+1,strlen(p+1)+1);
         printf("%s",str);


      }

      else if(n%2 ==0)
      {
          p=str+((strlen(str)/2)-1);
          while(var>0)
          {
            memmove(p,p+1,strlen(p+1)+1);
            --var;
          }

      }

      printf("%s",str);

