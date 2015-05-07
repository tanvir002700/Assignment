/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int fac(int x)
{
    int i,a=1;
    for(i=1;i<=x;i++)
    {
        a=a*i;
    }
    return a;
}
int ncr(int y,int z)
{
    int b=fac(y)/(fac(z)*fac(y-z));
    return b;
}

int main()
{
	printf("enter the line num:");
	int n;
	scanf("%d",&n);
	for(int l=1;l<=n;l++)
	{
		for(int j=1;j<=n-l;j++)
		{
			printf(" ");
		}
		for(int k=1; k<=l;k++)
		{
		    int m=ncr(l-1,k-1);
			printf("%d ",m);
		}
		printf("\n\n");
	}
	return 0;
}
