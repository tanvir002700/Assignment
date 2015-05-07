/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	char a[20],b[20];
	printf("Enter 1st name:");
	gets(a);
	printf("Enter 2nd name:");
	gets(b);
	int i,j;
	for(i=0;;i++)
	{
		if(a[i]==NULL)
		{
			break;
		}
	}
	for(j=0;;j++)
	{
		if(b[j]==NULL)
		{
			break;
		}
	}
	for(int k=i;k<=i+j;k++)
	{
		a[k]=b[k-i];
	}
	a[i+j]==NULL;
	puts(a);
	return 0;
}
