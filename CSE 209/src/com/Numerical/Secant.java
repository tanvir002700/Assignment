package com.Numerical;

import com.Function.Function;
public class Secant
{
	private String S;
	private double secant(double x1,double x2,int step)
	{
		double x3=x2-((x2-x1)/(Function.function(x2)-Function.function(x1)))*Function.function(x2);
		S+=("In step "+step+" x = "+x3+"\n");
		if(step==10)return x3;
		return secant(x2, x3, step+1);
	}
	private double secant(double x1,double x2,int step,int N)
	{
		double x3=x2-((x2-x1)/(Function.function(x2)-Function.function(x1)))*Function.function(x2);
		S+=("In step "+step+" x = "+x3+"\n");
		if(step==N)return x3;
		return secant(x2, x3, step+1,N);
	}
	public String Gen(double guess1,double guess2)
	{
		S="";
		double ans=secant(guess1, guess2, 0);
		return S;
	}
	
	public String Gen(double guess1,double guess2,int N)
	{
		S="";
		long  start=System.currentTimeMillis();
		double ans=secant(guess1, guess2, 0, N);
		long end=System.currentTimeMillis();
		S+="Total Time take for this operation : "+(end-start)+" milliseconds\n";
		return S;
	}
	
}