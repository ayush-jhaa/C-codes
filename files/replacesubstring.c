#include<stdio.h>
#include<stdlib.h>

#include<string.h>
char * readFromFile(char *filename)
{
	char *p=NULL;
	FILE *fp;
	long long int size;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("%s is not found\n",filename);
		return NULL;
	}
	fseek(fp,0,2);
	size=ftell(fp)+1;
	rewind(fp);
	p=calloc(size,1);
	fread(p,size,1,fp);
	p[size]='\0';
	fclose(fp);
	return p;
}

char * replaceAllOccofSubstr(char *p,char *s1,char *s2)
{
	char *q;
	long int l1,l2,i;
	q=p;
	l1=strlen(s1);
	l2=strlen(s2);
	while(q=strstr(q,s1))
	{
		if(l2>l1)
		{
			i=q-p;
			p=realloc(p,strlen(p)+1+(l2-l1));
			if(p+i != q)
			{
				q=p+i;
			}
			memmove(q+l2,q+l1,strlen(q+l1)+1);
		}
		else if(l2<l1)
		{
			memmove(q+l2,q+l1,strlen(q+l1)+1);
			p=realloc(p,strlen(p)+1);
		}
		strncpy(q,s2,l2);
		q=q+l2;
	}
	return p;
}

void writeToFile(char *p,char *filename)
{
	FILE *fp;
	fp=fopen(filename,"w");
	fwrite(p,strlen(p),1,fp);
	fclose(fp);
}

int main(int argc, char *argv[])
{	char *ptr;
	if(argc!=4)
	{
		printf("exe filename substr newstr\n");
		return 0;
	}
	ptr=readFromFile(argv[1]);
	ptr=replaceAllOccofSubstr(ptr,argv[2],argv[3]);
	writeToFile(ptr,argv[1]);
}
