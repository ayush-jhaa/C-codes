#include<stdio.h>

int main()
{
    float f;
    scanf("%f",&f);
    
    int *x=&f;
    
    for(int i=31;i>=0;i--)
    {
        printf("%d",((*x)>>i)&1);
    }
}
