/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	printf("enter the line num that contain maximum blanks:");
	int b;
	scanf("%d",&b);
	int a=b-1;
	for(int t=1;t<=(b*2-1);t++)
	{
		printf("*");
	}
	printf("\n");
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=(a+1)-i;j++)
		{
			printf("*");
		}
		for(int k=1;k<=i*2-1;k++)
		{
			printf(" ");
		}
		for(int l=1;l<=(a+1)-i;l++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(int m=1;m<=(a-1);m++)
	{
		for(int n=1;n<=m+1;n++)
		{
			printf("*");
		}
		for(int p=1;p<=(a*2-1)-2*m;p++)
		{
			printf(" ");
		}
		for(int q=1;q<=m+1;q++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(int r=1;r<=(b*2-1);r++)
	{
		printf("*");
	}
    return 0;
}
