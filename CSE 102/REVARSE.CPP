/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int main()
{
	char ch[20];
	printf("Enter your name:");
	gets(ch);
	int i;
	for(i=0;i<20;i++)
	{
		if(ch[i]==NULL)
		{
			break;
		}
	}
	int a=i;
	for(int j=0;j<a/2;j++)
	{
		i--;
		char temp=ch[j];
		ch[j]=ch[i];
		ch[i]=temp;
	}
	puts(ch);
	return 0;
}
