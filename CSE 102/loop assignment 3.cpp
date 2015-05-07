/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	printf("Enter the value of x in degree:");
	double x;
	scanf("%lf",&x);
	int y,z;
	z=x;
	y=x/90;
	if(y%2!=0&&z%90==0)
	{
		printf("math error.");
	}
	else
	{

		int a;
		a=x/360;
		double rem=x-a*360;
		rem=rem*(3.1415/180);
		double sinx=0;
		double prev=100;
		int i;
		for(i=1;;i++)
		{
			double pow=1;
			double fac=1;
			for(int j=1;j<=(i*2)-1;j++)
			{
				pow=pow*rem;
				fac=fac*j;
			}
			if(i%2==0)
			{
				sinx=sinx-pow/fac;
			}
			else
			{
				sinx=sinx+pow/fac;
			}
			if(fabs(prev-pow/fac)<0.00001)
			{
				break;
			}
			prev=pow/fac;
		}
		double cosx=1;
		double prev2=100;
		for(int k=2;;k++)
		{
			double pow2=1;
			double fac2=1;
			for(int l=1;l<=k*2-2;l++)
			{
				pow2=pow2*rem;
				fac2=fac2*l;
			}
			if(k%2==0)
			{
				cosx=cosx-pow2/fac2;
			}
			else
			{
				cosx=cosx+pow2/fac2;
			}
			if(fabs(prev2-pow2/fac2)<0.00001)
			{
				break;
			}
			prev2=pow2/fac2;
		}
		double tanx=sinx/cosx;
		printf("tan(%.2lf)=%.2lf",x,tanx);
	}
	return 0;
}
