#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * readFromFile(char *filename)
{
FILE *fp;
long int size;
char *p=NULL;
fp=fopen(filename,"r");

if(fp==NULL)
{
	printf("%s is not found\n",filename);
	return NULL;
}
fseek(fp,0,2);
size=ftell(fp);
rewind(fp);
p=calloc(1,size);
fread(p,size+1,1,fp);
p[size]='\0';
fclose(fp);
return p;

}

long int countAllOccOfChar(char *p,char ch)
{	long int cnt=0;
	char *q;
	q=p;
	while(q=strchr(q,ch))
	{
		cnt++;
		q++;
	}
	return cnt;
}
int main(int argc, char *argv[])
{	char *str;
	long int lcnt=0,scnt=0;
	if(argc!=2)
	{
		printf("exe filename\n");
		return 0;
	}
	
	str=readFromFile(argv[1]);
	scnt=countAllOccOfChar(str,32);
	lcnt=countAllOccOfChar(str,10);
	printf("no of characters is %d\n",strlen(str));
	printf("no of lines %ld\n",lcnt);
	printf("no of words %ld\n",lcnt+scnt);
}

