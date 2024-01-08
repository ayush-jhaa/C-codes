#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX 100
void Input(int *);
void Display(int *);

void Insertion(int *);

int main()
{
	int arr[MAX];
	Input(arr);
	printf("elements\n");
	Display(arr);
	Insertion(arr);
	printf("Elements after Sorting\n");
	Display(arr);
}

void Input(int *p)
{
	int i;
	printf("%d\n",getpid());
	srand(getpid());
	for(i=0;i<MAX;i++)
	{
		p[i]=rand()%1000;
	}
}

void Display(int *p)
{
	int i;
	for(i=0;i<MAX;i++)
		printf("%d ",p[i]);
	printf("\n");
}

void Insertion(int *p)
{
	int i,j,temp;
	// i represents the index of unsorted elements
	for(i=1;i<MAX;i++)
	{
		temp=p[i];
		j=i-1; // j represents the index of last element in sorted part
		while(j>=0 && temp < p[j])
		{
			p[j+1]=p[j];
			j--;
		}
		p[j+1]=temp;
	}

}
