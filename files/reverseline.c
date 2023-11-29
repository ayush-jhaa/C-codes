#include<stdio.h>
#include<string.h>

void Reverse(char *s)
{
	int i=0,j;
	char ch;
	j=strlen(s)-2; // excluding new line and null
	for(;i<j;i++,j--)
	{
		ch=s[i];
		s[i]=s[j];
		s[j]=ch;
	}
}
void reverseLine(char *filename)
{
	FILE *fp;
	char str[100];
	fp=fopen(filename,"r+");
	if(fp==NULL)
	{
		printf("%s is not found\n",filename);
		return ;
	}
	while(fgets(str,100,fp))
	{
		Reverse(str);
		fseek(fp,-strlen(str),1);
		fputs(str,fp);
	}
	fclose(fp);
}
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("exe filename\n");
		return 0;
	}
	reverseLine(argv[1]);
}
