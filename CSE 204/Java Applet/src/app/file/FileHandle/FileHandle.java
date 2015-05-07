package app.file.FileHandle;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;


public class FileHandle 
{
	public String fileRead(String filename) throws IOException
	{
			String temp="";
			FileInputStream in=new FileInputStream(filename);
			int n;
			while(true)
			{
					n=in.read();
					if(n!=-1)temp+=(char)n;
					else break;
				
			}
			in.close();
			return temp;
	}
	public void fileWrite(String fname,String msg) throws IOException 
	{
			FileOutputStream out=new FileOutputStream(fname);
			out.write(msg.getBytes());
			out.close();
	}
}
