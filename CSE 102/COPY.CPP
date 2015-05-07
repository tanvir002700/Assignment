/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	char ch[20],d[20];
	printf("Enter your name:");
	gets(ch);
	int i;
	for(i=0;i<20;i++)
	{
		if(ch[i]==NULL)
		{
			break;
		}
	}
	for(int j=0;j<=i;j++)
	{
		d[j]=ch[j];
	}
	puts(d);
	return 0;
}
