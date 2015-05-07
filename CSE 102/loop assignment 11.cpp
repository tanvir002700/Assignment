/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#include<conio.h>
int main()
{
	printf("enter the line number that contain maximum starts:");
	int s;
	scanf("%d",&s);
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=s-i;j++)
		{
			printf(" ");
		}
		for(int k=1;k<=i*2-1;k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(int m=1;m<=s-1;m++)
	{
		for(int n=1;n<=m;n++)
		{
			printf(" ");
		}
		for(int p=1;p<=s*2-1-(2*m);p++)
		{
			printf("*");
		}
		printf("\n");
	}
	getch();
}
