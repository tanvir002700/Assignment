/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	int m,n,p,q,a[100][100],b[100][100],c[100][100];
	printf("Enter the 1st matrix row num:");
	scanf("%d",&m);
	printf("Enter the 1st matrix column num:");
	scanf("%d",&n);
	printf("Enter the 2nd matrix row num:");
	scanf("%d",&p);
	printf("Enter the 2nd matrix column num:");
	scanf("%d",&q);
	if(m==p&&n==q)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("Enter a%d%d:",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
		}
		for(int k=0;k<p;k++)
		{
			for(int l=0;l<q;l++)
			{
				printf("Enter b%d%d:",k+1,l+1);
				scanf("%d",&b[k][l]);
			}
		}
		printf("your matrix are:\n");
		for(int x=0;x<m;x++)
		{
			for(int y=0;y<n;y++)
			{
				printf("%d ",a[x][y]);
			}
			printf("\n");
		}
		printf("\n");
		for(int u=0;u<p;u++)
		{
			for(int v=0;v<q;v++)
			{
				printf("%d ",b[u][v]);
			}
			printf("\n");
		}
		printf("ans:\n\n");
		for(int s=0;s<m;s++)
		{
			for(int t=0;t<n;t++)
			{
				printf("%d ",a[s][t]+b[s][t]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Dimension Error.");
	}
	return 0;
}
