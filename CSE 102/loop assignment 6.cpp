/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	printf("Enter a num:");
	int n;
	scanf("%d",&n);
	printf("Primes within the range of 1 to %d are:\n 2,",n);
	int flag=0;
	for(int i=3;i<=n;i++)
	{
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("%d,",i);
		}
		flag=0;
	}
	printf("\b");
	return 0;
}
