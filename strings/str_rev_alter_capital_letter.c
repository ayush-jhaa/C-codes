#include<stdio.h>
#include<string.h>

void reverse(char *str)
{
    char *p=str;
    char *q=str+(strlen(str)-1);
    char temp;
    
    while(p<q)
    {
        temp=*p;
        *p=*q;
        *q=temp;
        
        p++;
        q--;
    }
    
}

void convert(char *str)
{
    char *p=strtok(str," ");
    
    while(p!=NULL)
    {
       reverse(p);
       p=strtok(NULL," ");
        
    }
    
}

void remove_null(char *str,int n)
{
    for(int i=0;i<n;i++)
    {
        if(str[i]=='\0')
        str[i]=' ';
        
    }
}

void alternate_cap(char *str,int n)
{
    int i=0;
    do
    {
       if(i%2==1)
       {
           if(str[i]>=97 &&str[i]<=122)
           {
               str[i]=str[i]-32;
           }
       }
    }while(str[++i]);
}

int main()
{
    char str[100];
    fgets(str,100,stdin);
    int n=strlen(str);
    str[n-1]='\0';
    
    reverse(str);
    convert(str);
    
    remove_null(str,n);
    alternate_cap(str,n);

    printf("%s",str);
    return 0;
}
