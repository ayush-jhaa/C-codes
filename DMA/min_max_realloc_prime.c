#include<stdio.h>
#include<stdlib.h>

int isprime(int data)
{
     int i;

     for(i=2;i<data;i++)
     {
         if(data%i==0)
         {
            return 0;
         }
     }

     return 1;
}

int main()
{
     int min,max,data,i=0;
     int *arr=NULL;
     scanf("%d %d",&min,&max);

     for(data=min;data<=max;data++)
      {
          if(isprime(data))
          {
             arr=realloc(arr,(i+1)*sizeof(int));
             arr[i]=data;
             i++;
          }
      }

      int j=0;
      for(j=0;j<i;j++)
      {
           printf("%d ",arr[j]);
      }

}
