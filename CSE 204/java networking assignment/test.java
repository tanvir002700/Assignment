import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;


public class Clint
{

	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		String name="localhost"; ///server name
		int port=10; ///port number of server
		try
		{
			Socket clint=new Socket(name,port); ///create link between server and clint
			DataInputStream in=new DataInputStream(clint.getInputStream());
			DataOutputStream out= new DataOutputStream(clint.getOutputStream());
			System.out.println(in.readUTF());
			out.writeUTF("welcome to clint");
			while(true)
			{
				System.out.println(in.readUTF().toString());
				String temp=input.nextLine();
				out.writeUTF("Clint: "+temp.toString());
			}
		}
		catch (UnknownHostException e)
		{
			System.out.println("invalid host name");
		}
		catch (IOException e)
		{
			System.out.println("invalid host name");
		}
	}

}
