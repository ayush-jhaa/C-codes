#include<stdio.h>

size_t mystrlen(const char*p)
{
      size_t length=0;

      while(p[length])
      {
          length++;
      }

      return length;
}
int main()
{
       char p[20];
       gets(p);
       size_t length=mystrlen(p);

      printf("%zu",length);
}
