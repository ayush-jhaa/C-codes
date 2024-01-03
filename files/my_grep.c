#include<stdio.h>
#include<string.h>

void myGrep(char *s1,char *filename)
{
	FILE *fp;
	char line[100];
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("%s is not found\n",filename);
		return ;
	}
	while(fgets(line,100,fp))
	{
		if(strstr(line,s1))
		{
			printf("%s\n",line);
		}
	}
	fclose(fp);
}
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("exe substr filename\n");
		return 0;
	}
	myGrep(argv[1],argv[2]);
}
