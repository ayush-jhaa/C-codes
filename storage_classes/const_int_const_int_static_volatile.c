// this is giving answer  

#include <stdio.h>

int main()
{
  const int v=100;
  int *p=&v;
  ++*p;
  printf("%d",v);

  return 0;
}

// this is not giving answer
#include <stdio.h>
int main()
{
  const int static v=100;
  int *p=&v;
  ++*p;
  printf("%d",v);

  return 0;
}

// volatile for optimization remove

#include <stdio.h>
int main()
{
 volatile const int static v=100;
  int *p=&v;
  ++*p;
  printf("%d",v);

  return 0;
}
