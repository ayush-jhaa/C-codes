// here you are trying to modify string literal which resides in read only segment thats why segmentation fault comes.

#include <stdio.h>

int main()
{
   char *p="Vector";
   *p='v';             //segmentation fault

    return 0;
}
