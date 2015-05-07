import java.net.*;
import java.io.*;

public class GreetingClient extends Thread //GreetingClint class enteds Thread class
{
    static DataInputStream in; // DataInputStream for take input from Server

    public static void main(String[] args) //Main function
    {
        String serverName = args[0]; //serverName store host name from args[0] 
        int port = Integer.parseInt(args[1]); //Port take Server port number from args[1]
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //create bufferedReader br for take input from keyboard
        try
        {
            Socket client = new Socket(serverName, port); //client is socket type object which make connection between client and server
            Thread t = new GreetingClient(); //create Thread type object t which run the child thread
            in = new DataInputStream(client.getInputStream()); //in bype object which take input from server
            DataOutputStream out = new DataOutputStream(client.getOutputStream()); //create dataoutputstream out which send data to server
            t.start(); //here start child thread

            while (true) 
            {
                String s = br.readLine(); //taking input from keyboard by br and store in String object s
                out.writeUTF("Client: " + s); // Send this String s to Srever by out object
                if (s.equals("Bye")) //when client type bye then the loop will be stop
                {
                    break;
                }
            }
            client.close(); //after breaking loop client will be close
        }
        catch (Exception e)
        {

        }
    }

    public void run() //this is child thread
    {
        try
        {
            while (true)
            {
                String s = in.readUTF(); //take input from server and stroe it string type object s
                System.out.println(s); //print s string which store server msg 
                if (s.equals("Bye")) //if server send Bye msg then the while loop will be stop
                    break;
            }
        }
        catch (Exception e)
        {

        }
    }
}
