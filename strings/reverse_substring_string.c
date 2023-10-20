#include<stdio.h>
#include<string.h>

int main()
{
      char s1[30]="ABCDEABCDE";
      char s2[5]="BCD";

      char *p,*q;
      char *temp=s1;
      char ch;
      int l2=strlen(s2);
      for(temp;temp=strstr(temp,s2);temp +=l2)
      {
          p=temp;
          q=temp+l2-1;

          while(p<q)
          {
             ch=*p;
             *p=*q;
             *q=ch;
             p++;
             q--;
          }
      }

      printf("%s",s1);

}
