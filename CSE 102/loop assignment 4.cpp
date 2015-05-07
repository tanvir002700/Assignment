/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	printf("Enter which term u want to see the Fibonacci series:");
	int n;
	scanf("%d",&n);
	int f1=0,f2=1,f3=0;
	printf("1,");
	for(int i=1;i<n;i++)
	{
		f3=f1+f2;
		printf("%d,",f3);
		f1=f2;
		f2=f3;
	}
	printf("\b");
	return 0;
}
