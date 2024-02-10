#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void strrev(char *p)
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
    
    int l=strlen(str);
    

    char *s2=malloc(l+1);

    char *p=strtok(str," ");
    int i;

    while(p !=NULL)
    {
        strrev(p);
        p= strtok(NULL, " ");
    }
    


    for( i=0;i<=l-1;i++)
    {
       if(str[i]=='\0')
       {
           s2[i]=' ';
       }
       
       else
       {
           s2[i]=str[i];
       }
    }
    s2[i]='\0';
    
    strcpy(str,s2);
    
    printf("%s\n",s2);
    printf("%ld\n",strlen(s2));
    printf("%ld\n",sizeof(s2));
    
    printf("------------------------------------------------------\n");
    
    printf("%s\n",str);
    printf("%ld\n",strlen(str));
     printf("%ld\n",sizeof(str));
     
     free(str);
     free(s2);
    
     
     str=NULL;
     s2=NULL;
     
}
