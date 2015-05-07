/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int strlen(char a[])
{
    int i;
	for(i=0;i<500;i++)
	{
		if(a[i]==NULL)
		{
			break;
		}
	}
	return i;
}
int main()
{
	char c[500];
	printf("Enter a string:");
	gets(c);
	int z=strlen(c);
	printf("Your string num: %d",z);
	return 0;
}
