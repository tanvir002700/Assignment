class Convert
{
	Convert()
	{
		
	}
	double convert_double(int n)
	{
		return (double)n;
	}
	double convert_double(float n)
	{
		return (double)n;
	}
	int convert_int(double n)
	{
		return (int)n;
	}
	int convert_int(float n)
	{
		return (int)n;
	}
};
class anick
{
	public static void main(String args[])
	{
		Convert A= new Convert();
		int b=A.convert_int(123.456);
		System.out.println(b);
	}
}