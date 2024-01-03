#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *readfile(char *filename)
{
      FILE *fp;
      char *p;
      int size;
      fp=fopen(filename,"r");
      if(fp==NULL)
      {
         printf("file not found");
         return 0;
      }
      fseek(fp,0,2);
      size= ftell(fp)+1;
      rewind(fp);
      p=calloc(1,size);
      p[size]='\0';
      fread(p,size,1,fp);
      fclose(fp);
      return p;
}

void reverseSub(char *s1,char *s2)
{
    char *p,*q,*temp,ch;

    int l2=strlen(s2);

    for(temp=s1;temp=strstr(temp,s2);temp +=l2 )
   {
      p=temp; q=temp+l2-1;

    while(p<q)
     {
        ch=*p;
        *p=*q;
        *q=ch;
        p++; q--;
     }

   }

}

void printfile(char *p,char *filename)
{
   FILE *fp=NULL;
   fp=fopen(filename,"w");

   fprintf(fp,"%s",p);
   fclose(fp);
}

int main(int argc, char *argv[])
{
   char *p=NULL;

   if(argc !=3)
    {
       printf("argument are less");
       return 0;
    }

    p= readfile(argv[2]);
    reverseSub(p,argv[1]);
    printfile(p,argv[2]);

}
