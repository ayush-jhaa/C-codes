#include <stdio.h>

int test_little_endian(void)
{
    int v=1;
    char *p=&v;
    
    return (*p);
}

unsigned short int HTONS(unsigned short int var)
{
    char *p;
    char temp;
    
    if(test_little_endian())
    {
        p=&var;
        temp=*p;
        *p=*(p+1);
        *(p+1)=temp;
    }
    
    return var;
}


int main()
{
    int data;
    scanf("%d",&data);
    
  data=  HTONS(data);
    
    printf("%d",data);
}
