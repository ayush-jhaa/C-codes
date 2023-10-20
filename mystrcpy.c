#include<stdio.h>

char *mystrcpy(char *desti,const char* src)
{
   int i=0;

   while(src[i])
   {
       desti[i]=src[i];
       i++;
   }

   desti[i]='\0';
   return desti;
}

int main()
{
     char src[20];
     puts("enter the source:");
     gets(src);

     char desti[40];
     puts("enter the destination:");
     gets(desti);

     printf("desti before strcpy:%s\n",desti);

     mystrcpy(desti,src);

     printf("after strcpy:%s",desti);
}
