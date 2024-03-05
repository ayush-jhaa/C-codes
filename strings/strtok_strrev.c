#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void str_rev(char *p)
{
    int l=strlen(p)-1;
    char *s=p;
    char *r=p;
    char temp;
    r=p+l;
    
    while(s<r)
    { 
      temp=*s;
      *s=*r;
      *r=temp;
      s++;
      r--;
    }
 
}

int main()
{
    char *str=NULL;
    int j=0;
    do
    {
        str=realloc(str,(j+1)*sizeof(char));
        str[j]=getchar();
    }while(str[j++] !='\n');
    
    str[j-1]='\0';
    
    int l=strlen(str)-1;

    // str_rev(str)  // if you want to reverse the main string without reversing substring

    char *p=strtok(str," ");
    int i;

    while(p !=NULL)
    {
        str_rev(p);
        p= strtok(NULL, " ");
    }
    


    for( i=0;i<=l;i++)
    {
       if(str[i]=='\0')
       {
           str[i]=' ';
       }
    }
    s2[i]='\0';
    printf("%s",str);
}
