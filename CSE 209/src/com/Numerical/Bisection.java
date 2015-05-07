package com.Numerical;
import com.Function.Function;

/*class for Bisection operation*/
public class Bisection
{
	private String S;
	
	/*Recursion function for find solution*/
	private double bisection(double x1,double x2,int step)
	{
		double x3=(x1+x2)/2;
		S+=("In step "+step+" x = "+x3+"\n");
		if(step==10)return x3;
		double f=Function.function(x3);
		if(f>0)
		{
			return bisection(x1, x3, step+1);
		}
		else
		{
			return bisection(x3, x2, step+1);
		}
	}
	
	
	/*bisection function overloading*/
	private double bisection(double x1,double x2,int step,int N)
	{
		double x3=(x1+x2)/2;
		S+=("In step "+step+" x = "+x3+"\n");
		if(step==N)return x3;
		double f=Function.function(x3);
		if(f>0)
		{
			return bisection(x1, x3, step+1,N);
		}
		else
		{
			return bisection(x3, x2, step+1,N);
		}
	}
	
	
	/*Generate the bisection function*/
	public String Gen(double guess1,double guess2)
	{
		S="";
		double ans=bisection(guess1, guess2, 0);
		return S;
	}
	
	/*Generate bisection with range*/
	public String Gen(double guess1,double guess2,int N)
	{
		S="";
		long  start=System.currentTimeMillis();
		double ans=bisection(guess1, guess2, 0, N);
		long end=System.currentTimeMillis();
		S+="Total Time take for this operation : "+(end-start)+" milliseconds\n";
		return S;
	}
}