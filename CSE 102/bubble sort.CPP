/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[100];
	printf("Enter a range:");
	scanf("%d",&a[0]);
	for(int i=1;i<=a[0];i++)
	{
		printf("%d.Enter number:",i);
		scanf("%d",&a[i]);
	}
	printf("Rearrange >> ");
	for(int j=1;j<=a[0];j++)
	{
		for(int k=j;k<=a[0];k++)
		{
			if(a[j]>a[k])
			{
				int temp;
				temp=a[j];
				a[j]=a[k];
				a[k]=temp;
			}
		}
		printf("%d, ",a[j]);
	}
	printf("\b");
	getch();
	return 0;
}
