#include<stdio.h>
#include<string.h>
int myisdigit(char);
int myatoi(char*);
int main()
{
       char str[20];
       int i,n1,n2,sum;

      // taking input of first num
INPUT1:      puts("enter first  num:");
             scanf("%s",str);


       for(i=0;str[i];i++)
        {
           if(!myisdigit(str[i]))
            {
                 printf("invalid input");
                 goto INPUT1;
            }
        }

       //convert ascii to integer.

       n1=  myatoi(str);

             // taking input of second num
INPUT2:      puts("enter second  num:");
             scanf("%s",str);


       for(i=0;str[i];i++)
        {
           if(!myisdigit(str[i]))
            {
                 printf("invalid input");
                 goto INPUT2;
            }
        }

       //convert ascii to integer.

       n2=  myatoi(str);

       //sum of integer

       sum=n1+n2;
       printf("%d",sum);


}

int myisdigit(char v)
{
       if(v>=48 && v<=57)
         return 1;

       return 0;
}

int myatoi(char* v)
{
        int i=0, k=0;

      for(i=0;v[i];i++)
        {
           k=k*10+v[i]-48;
        }
      return k;
}
