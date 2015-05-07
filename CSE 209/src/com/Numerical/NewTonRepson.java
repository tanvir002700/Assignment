package com.Numerical;
import com.Function.Function;

public class NewTonRepson
{
	private String S;
	private double newtonrepson(double x1,int step)
	{
		double x2=x1-(Function.function(x1)/Function.function1(x1));
		S+=("In step "+step+" x = "+x2+"\n");
		if(step==10)return x2;
		return newtonrepson(x2, step+1);
	}
	private double newtonrepson(double x1,int step,int N)
	{
		double x2=x1-(Function.function(x1)/Function.function1(x1));
		S+=("In step "+step+" x = "+x2+"\n");
		if(step==N)return x2;
		return newtonrepson(x2, step+1,N);
	}
	public String Gen(double guess)
	{
		S="";
		double ans=newtonrepson(guess, 0);
		return S;
	}
	public String Gen(double guess,int N)
	{
		S="";
		long  start=System.currentTimeMillis();
		double ans=newtonrepson(guess, 0, N);
		long end=System.currentTimeMillis();
		S+="Total Time take for this operation : "+(end-start)+" milliseconds\n";
		return S;
	}
}