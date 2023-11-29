k#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
int cnt;
int isPrime(int n)
{	int i=2;
	if(n==1)
		return 0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int * Input()
{
	int *p=NULL;
	int min,max;
	printf("enter the range for primenos\n");
	scanf("%d %d",&min,&max);
	for(min;min<=max;min++)
	{
		if(isPrime(min))
		{
			p=realloc(p,(cnt+1)*sizeof(int));
			p[cnt]=min;
			cnt++;
		}
	}
	return p;
}
void Print(int *p)
{
	int i;
	for(i=0;i<cnt;i++)
		printf("%d,",p[i]);
	printf("\ntotal primeno %d\n",cnt);
}
int main()
{
	FILE *fp1,*fp2;
	int *arr;
	int i;
	arr=Input();
	Print(arr);
	fp1=fopen("file1","w");
	fp2=fopen("file2","w");
	fwrite(arr,sizeof(int),cnt,fp1);
	for(i=0;i<cnt;i++)
	{
		fprintf(fp2,"%d,",arr[i]);
	}
	printf("size of file1 %ld\n",ftell(fp1));
	printf("size of file2 %ld\n",ftell(fp2));

	fclose(fp1);
	fclose(fp2);

}
