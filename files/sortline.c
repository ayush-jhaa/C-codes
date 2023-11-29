#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cnt;
void * readFromFile(char *filename)
{
	char (*p)[100]=NULL;
	char str[100];
	FILE *fp;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("%s is not found\n",filename);
		return NULL;
	}

	while(fgets(str,100,fp))
	{
		p=realloc(p,(cnt+1)*100);
		strcpy(p[cnt],str);
		cnt++;

	}
	fclose(fp);
	return p;

}
void * sortLines(char (*p)[100])
{
	int i,j;
	char temp[100];
	for(i=1;i<cnt;i++)
	{
		for(j=0;j<cnt-i;j++)
		{
			if(strlen(p[j])>strlen(p[j+1]))
			{
				strcpy(temp,p[j]);
				strcpy(p[j],p[j+1]);
				strcpy(p[j+1],temp);
			}
		}
	}
	return p;
}
void writeToFile(char (*p)[100],char *filename)
{
	FILE *fp;
	int i;
	fp=fopen(filename,"w");
	for(i=0;i<cnt;i++)
	{
		fputs(p[i],fp);
	}
	fclose(fp);
}

int main(int argc,char *argv[])
{	char (*lines)[100]=NULL;
	if(argc!=2)
	{
		printf("exe filename\n");
		return 0;
	}
	if((lines=readFromFile(argv[1])))
	{
		lines=sortLines(lines);
		writeToFile(lines,argv[1]);
	}
}

