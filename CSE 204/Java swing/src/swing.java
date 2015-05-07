import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import custom.show.ShowRandomNumber;


public class swing 
{
	public static int right=0,wrong=0;
	public static void main(String[] args) 
	{
		JFrame frame=new JFrame("TYPING MASTER");
		frame.setSize(600, 600);
		JPanel panel=new JPanel();
		JTextArea text=new JTextArea(20,30);
		JTextArea text2=new JTextArea(20,20);
		JLabel Header=new JLabel("TYPING MASTER");
		JLabel typingArea=new JLabel("Typing area");
		JLabel L1=new JLabel("right 0");
		JLabel L2=new JLabel("wrong 0");
		text2.setBackground(Color.BLUE);
		text.setBackground(Color.gray);
		frame.add(panel);
		
		panel.add(Header);
		panel.add(text);
		panel.add(text2);
		panel.add(L1);
		panel.add(typingArea);
		panel.add(L2);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		panel.setLayout(null);
		Header.setBounds(200, 00, 200, 30);
		text.setBounds(Header.getX()-100, Header.getY()+Header.getHeight(), 300, 200);
		typingArea.setBounds(Header.getX(),text.getY()+text.getHeight()+5,200,30);
		text2.setBounds(text.getX(), typingArea.getY()+50, 300, 200);
		L1.setBounds(text2.getX(), text2.getY()+text2.getHeight()+5, 1000, 20);
		L2.setBounds(text2.getX()+230, text2.getY()+text2.getHeight()+5, 1000, 20);
		ShowRandomNumber S=new ShowRandomNumber(text);
		text2.addKeyListener(new action(L1,L2));
	}

}



class action implements KeyListener
{
	JLabel L1,L2;
	public action(JLabel l1,JLabel l2)
	{
		L1=l1;
		L2=l2;
	}
	@Override
	public void keyPressed(KeyEvent arg0) 
	{
		if(arg0.getKeyChar()==ShowRandomNumber.check)
		{
			L1.setText("right "+(++swing.right));
		}
		else
		{
			L2.setText("wrong "+(++swing.wrong));
		}
	}

	@Override
	public void keyReleased(KeyEvent arg0) 
	{
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyTyped(KeyEvent arg0) 
	{
		// TODO Auto-generated method stub
		
	}
	
}