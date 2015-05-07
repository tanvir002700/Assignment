/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	printf("Enter a number:");
	int n;
	scanf("%d",&n);
	int rem=0,sum=0;
	for(;;)
	{
		rem=n%10;
		sum=sum+rem;
		n=n/10;
		if(n==0)
		{
			break;
		}

	}
	printf("summation of digit of %d is %d",n,sum);
	return 0;
}
