import java.applet.Applet;
import java.awt.Button;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Label;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import app.file.FileHandle.FileHandle;

public class App extends Applet 
{
	String msg="";
	Label L1,L2,L3;
	TextField f_name;
	TextArea txt_area;
	Button b1,b2;
	String show_status;
	boolean file_open_sucessfully;
	public void init()
	{
		setBackground(Color.lightGray);
		L1=new Label("file name: ");
		L2=new Label("Editor area: ");
		f_name=new TextField(20);
		txt_area=new TextArea(20, 25);
		b1=new Button("save");
		b2=new Button("open");
		this.setSize(500, 500);
	}
	public void start()
	{
		msg="";
		show_status="Applet open";
		setLayout( null );
		add(L1);
		add(f_name);
		add(b2);
		add(L2);
		add(txt_area);
		add(b1);
		b2.addActionListener(new Action1(f_name,txt_area,this));
		b1.addActionListener(new Action2(f_name,txt_area,this));
		L1.reshape(10, 20, 60, 40);
		f_name.setBackground(Color.black);
		f_name.setForeground(Color.white);
		f_name.reshape(L1.getX()+60, L1.getY(), 300, 50);
		b2.reshape(f_name.getX()+f_name.getWidth()+5, f_name.getY(), 60,40 );
		int midx=(b2.getX()-f_name.getX())/2;
		L2.reshape(midx, f_name.getY()+50, 66, 40);
		txt_area.reshape(f_name.getX(), L2.getY()+L2.getHeight(), 300, 300);
		txt_area.setBackground(Color.black);
		txt_area.setForeground(Color.LIGHT_GRAY);
		int midx2=(txt_area.getX()+txt_area.getWidth())/2;
		b1.reshape(midx2, txt_area.getY()+txt_area.getHeight()+5, 60, 40);
		b1.setBackground(Color.red);
		b2.setBackground(Color.pink);
	}
	public void paint(Graphics g)
	{
		g.drawString(msg, b1.getX(), b1.getY()+b1.getHeight()+20);
		showStatus(show_status);
	}
}

class Action2 implements ActionListener
{
	TextField TF;
	TextArea TA;
	App A;
	public Action2(TextField tf,TextArea ta,App a)
	{
		TF=tf;
		TA=ta;
		A=a;
	}
	public void actionPerformed(ActionEvent e) 
	{
		FileHandle F=new FileHandle();
		try 
		{
			if(A.file_open_sucessfully==true)
			{
				A.msg="file Save sucessfully";
				A.repaint();
			}
			else
			{
				A.msg="file not open sucessfully";
				A.repaint();
			}
			F.fileWrite(TF.getText(), TA.getText());
		} 
		catch (IOException e1)
		{
			
		}
	}
}
class Action1 implements ActionListener
{
	TextField TF;
	TextArea TA;
	App A;
	public Action1(TextField tf,TextArea ta,App a)
	{
		TF=tf;
		TA=ta;
		A=a;
	}
	public void actionPerformed(ActionEvent arg0)
	{
		FileHandle F=new FileHandle();
		String msg;
		try 
		{
			msg = F.fileRead(TF.getText());
			TA.setText(msg);
			A.file_open_sucessfully=true;
		}
		catch (IOException e) 
		{
			A.file_open_sucessfully=false;
			TA.setText(TF.getText()+" File not Found");
		}
	}
}