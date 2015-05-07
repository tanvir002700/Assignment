import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

class Server extends Thread
{
	ServerSocket serversocket;
	public Server(int port) throws IOException
	{
		serversocket=new ServerSocket(port);
		//serversocket.setSoTimeout(10000);
	}
	public void run()
	{
		Scanner input=new Scanner(System.in);
			System.out.println("Waiting for clint ");
			try
			{
				Socket server= serversocket.accept();
				System.out.println("connected to "+ server.getLocalPort());
				DataInputStream in=new DataInputStream(server.getInputStream());
				DataOutputStream out=new DataOutputStream(server.getOutputStream());
				out.writeUTF("Welcome to Local Server");
				while(true)
				{
					System.out.println(in.readUTF().toString());
					String temp=input.nextLine();
					out.writeUTF("Server: "+temp.toString());
				}
			} 
			catch (IOException e) 
			{
				System.out.println("time out");
			}
	}
}
public class GetServer 
{
	public static void main(String[] args) throws IOException 
	{
		Thread t=new Server(10);
		t.start();
	}

}
