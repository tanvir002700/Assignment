import java.net.*;
import java.io.*;

public class GreetingServer extends Thread //GreetingServer class extends Thread class
{
    private static ServerSocket serverSocket; //Create serversocket type object serversocket which will be store the port number
    private static DataInputStream in; //create Dataiputstream to take input from client

    public void run() //this is the child thread
    {
        try
        {
            while (true) 
            {
                String s = in.readUTF(); //take input from client and store it String type object s
                System.out.println(s); //print string s which store msg of client
                if (s.equals("Bye")) //if client send Bye then this while loop stop
                    break;
            }
        }
        catch (Exception e)
        {
            //e.printStackTrace();
        }
    }

    public static void main(String[] args) //main function
    {
        int port = Integer.parseInt(args[0]); //set port name from agrs[0]

        try
        {
            serverSocket = new ServerSocket(port); //serversocket initial with port number
            // serverSocket.setSoTimeout(10000);

            while (true)
            {
                try
                {
                    Socket server = serverSocket.accept();//now serversocket.accept() wait for responce of client
                    in = new DataInputStream(server.getInputStream());// create Datainput strea for taking input from client
                    Thread t = new GreetingServer(); //create Thread type object t
                    t.start(); //run the child Thread
                    DataOutputStream out = new DataOutputStream(server.getOutputStream()); //create DataoutputStream object out for send msg to client
                    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //create BufferedReader object br to take input from keyboard
                    while (true)
                    {
                        String s = br.readLine(); //here main thread take input from keyboard and store in String type object s
                        out.writeUTF("Server: " + s); //send this String s to Client
                        if (s.equals("Bye")) //when s find Bye then while loop will be break
                            break;
                    }
                    server.close(); //after while loop break the server will be close
                }
                catch (SocketTimeoutException s) //try block never throw any exception bcoz there is no time set for waiting time out
                {
                    System.out.println("Socket timed out!"); 
                    break;
                }
                catch (Exception e)
                {
                    //e.printStackTrace();
                    break;
                }
            }

        }
        catch (Exception e)
        {
            //e.printStackTrace();
        }
    }
}
