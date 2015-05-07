package com.Function;
public class Function
{
	/*This is the main function*/
	public static double function(double x)
	{
		return (x*x*x*x)-(7*x*x)-10;
	}
	
	/*first derivative of main function*/
	public static double function1(double x)
	{
		return (4*x*x*x)-14;
	}
	public String Gen(double x)
	{
		String s="";
		double v=function(x);
		s="f("+x+") = "+ v;
		return s;
	}
}