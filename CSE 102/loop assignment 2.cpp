/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	printf("Enter a 10 base number:");
	int d,j,i;
	scanf("%d",&d);
	int r,b=0,m=0,c;
	c=d;
	for(i=1;; i++)
	{
		r=d%2;
		d=d/2;
		b=b*10+r;
		if(d==0)
		{
			break;
		}
	}
	for(j=1; j<=i; j++)
	{
		r=b%10;
		b=b/10;
		m=m*10+r;
	}
	printf("Bainary of %d is %d",c,m);
	return 0;
}
