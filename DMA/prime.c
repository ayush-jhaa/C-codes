#include<stdio.h>
#include<stdlib.h>

int isprime(int s)
{
    int i;

    for(i=2;i<s;i++)
    {
        if(s%i==0)
        {
           return 0;
        }
    }

    return 1;
}
int main()
{
     int s;
     printf("enter the starting number to take: ");
     scanf("%d",&s);

     int n,i=0;
     printf("number of prime number: ");
     scanf("%d",&n);

     int *arr;
     arr=(int *) malloc(n* sizeof(int));

     if(arr==NULL)
     {
        printf("not enough space!!!");
        exit(0);
     }

     while(i<n)
     {
           if(isprime(s))
            {
                arr[i++]=s;
            }

           s++;
     }

     i=0;
     while(i<n)
     {
        printf("%x ",&arr[i]);
        i++;
     }
}
