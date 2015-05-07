/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>

int main()
{
	printf("enter the line num:");
	int n;
	scanf("%d",&n);
	int g;
	for(int i=1;i<=n;i++)
	{
		g=i;
		for(int j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		for(int k=1; k<=2*i-1;k++)
		{
			if(k<=i)
			{
				printf("%d",k);
			}
			else
			{
				g=g-1;
				printf("%d",g);
			}
		}
		printf("\n");
	}
	return 0;
}
