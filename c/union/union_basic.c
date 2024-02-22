#include <stdio.h>

union tag
{
    struct stu
    {
        char ch1[2];
        char ch2[2];
    }s1;
    
    struct stu2
    {
        short int i;
        short int j;
    }s2;
    
}v={1,1,1,1};

int main()
{
    printf("%d\n",&v.s2.j); // 636657682
    printf("%d\n",&v.s1.ch2);// 636657682
    
    printf("%d\n",&v.s2.i); // 636657680
    printf("%d\n",&v.s1.ch1);  // 636657680
}
