#include<stdio.h>
#include<string.h>
void reverse(char *,char *,int);
int main()
{
  char arr[40]; 
  gets(arr); 
  char s1[10];
  scanf("%s",s1);
  int l=strlen(s1); 
  reverse(arr,s1,l);
}

void reverse(char *arr,char *s1,int l)
{ 
  char*p=arr;
  int i=0; 
  int found=0; 
  while(p=strstr(p,s1)) 
  {
    found=1; 
    i=0;
    while(s1[i]) 
    {
      p[i]=s1[l-i-1]; 
      i++; 
    }
    p=p+l;
  } 
  
  
  if(found)
    printf("%s",arr); 
  else 
    printf("sub string not found");}
