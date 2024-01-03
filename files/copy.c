#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *readFromFile(char *filename)
{

	FILE *fp;
	char *p=NULL;
	long int size;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("%s is not found\n",filename);
		return NULL;
	}
	fseek(fp,0,2); // taking to end of the file
	size=ftell(fp);
	rewind(fp); // taking control to begining of the file
	p=calloc(1,size+1);
	fread(p,size,1,fp);
	p[size]='\0';
	fclose(fp);
	return p;
	
}

void writeToFile(char *buf,char *filename)
{
	FILE *fp;
	fp=fopen(filename,"w");
	fwrite(buf,1,strlen(buf),fp);
	fclose(fp);
}

int main(int argc,char *argv[])
{	char *buf;
	if(argc!=3)
	{
		printf("./cp srcfile destfile\n");
		return 0;
	}
	buf=readFromFile(argv[1]);
	if(buf)
	writeToFile(buf,argv[2]);
	free(buf);
		
}
