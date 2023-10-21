#include<stdio.h>
#include<string.h>
void pairvowel(char *,char*);

int main()
{ 
    char str[50];
    fgets(str,50,stdin); 
    char*p=str; 
    pairvowel(str,p);
    
}

void pairvowel(char *str,char *p)
{
    int l=2,found=0; 
    while(*p) 
  { 
        if(*p== 'a'|| *p=='A' || *p=='e' || *p=='E' || *p=='i' || *p=='I' || *p=='o' || *p=='O' || *p=='u' || *p=='U')
        
  { 
            char *q=p;
            q++; 
            
       if(*q=='a' || *q=='A' || *q=='e' || *q=='E' || *q=='i' || *q=='I' || *q=='o' || *q=='O' || *q=='u' || *q=='U') 
        
      { 
          found=1;
          memset(p,'*',l);
          
     } 
           
 }
       p++; 
        
} 

if(found)
  printf("%s",str);
else 
  printf("there is no pair of vovels to hide");
    
}
