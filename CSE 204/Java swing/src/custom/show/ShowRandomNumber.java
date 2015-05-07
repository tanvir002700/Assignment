package custom.show;

import java.util.Random;

import javax.swing.JTextArea;

public class ShowRandomNumber implements Runnable
{
	public static char check;
	Thread t;
	JTextArea TEXT;
	int n=0;
	public ShowRandomNumber(JTextArea Text)
	{
		t=new Thread(this);
		TEXT=Text;
		t.start();
	}
	public void run()
	{
		Random Rand=new Random();
		do
		{
			n++;
			int r=Rand.nextInt(26);
			char ch=(char) (r+'a');
			check=ch;
			TEXT.append(ch+" ");
			if(n%10==0)
			{
				TEXT.append("\n");
			}
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				
			}
		}while(n<=100);
	}
}