/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#include<string.h>
#define max 500
int main()
{
	char num1[max],num2[max],res[2*max],temp[max],temp2;
	int i;
	for(i=0;i<max;i++)
	{
		num1[i]='0';
		num2[i]='0';
	}
	for(i=0;i<max;i++)
	{
		temp[i]=0;
		res[i]=0;
	}
	printf("Enter the 1st num:");
	gets(num1);
	printf("Enter the 2nd num:");
	gets(num2);
	strrev(num1);
	strrev(num2);
	for(i=0;i<max;i++)
	{
		if(num1[i]==NULL)
		{
			num1[i]=0;
		}
		else
		{
			num1[i]=num1[i]-48;
		}
	}
	for(i=0;i<max;i++)
	{
		if(num2[i]==NULL)
		{
			num2[i]=0;
		}
		else
		{
			num2[i]=num2[i]-48;
		}
	}
	char hand1=0,hand2=0;
	for(i=0;i<max;i++)
	{
		for(int j=0;j<max;j++)
		{
			temp[j]=(num1[j]*num2[i]+hand1)%10;
			hand1=(num1[j]*num2[i]+hand1)/10;
		}
		for(j=0;j<max;j++)
		{

			temp2=res[j+i];
			res[j+i]=(temp[j]+res[j+i]+hand2)%10;
			hand2=(temp2+temp[j]+hand2)/10;
		}
	}
	for(i=0;i<max;i++)
	{
		res[i]=res[i]+48;
	}
	for(i=max-1;i>=0;i--)
	{
		if(res[i]!='0')
		{
			res[i+1]=NULL;
			break;
		}
	}
	strrev(res);
	puts(res);
	return 0;
}
