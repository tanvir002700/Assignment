/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	printf("Enter 1st number:");
	int a;
	scanf("%d",&a);
	printf("Enter 2nd number:");
	int b;
	scanf("%d",&b);
	int lcm=1;
	for(int i=1;i<=a;i++)
	{
		if(a%i==0&&b%i==0)
		{
			lcm=lcm*i;
			a=a/i;
			b=b/i;
		}
	}
	lcm=lcm*a*b;
	printf("LCM of %d & %d is :%d",a,b,lcm);
	return 0;
}
