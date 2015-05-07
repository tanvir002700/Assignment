/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	printf("enter the value of n:");
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i*2;j=j+2)
		{
			sum=sum+j;
		}
	}
	printf("%d",sum);
	return 0;
}
