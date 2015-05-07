/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	printf("enter total num of crew:");
	long int c;
	scanf("%ld",&c);
	long int d=1;
	int i;
	for(i=1; i<=100; i++)
	{
		c=c/2;

		if(c==1)
		break;
	}
	for(int j=1; j<=i; j++)
	{
		d=2*d;
	}
	printf("your positon:%ldth",d);
	return 0;
}
