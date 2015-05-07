import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import com.Numerical.Bisection;
import com.Numerical.NewTonRepson;
import com.UI.Menu;
import com.UI.UiBisection;
import com.UI.UiFunction;
import com.UI.UiNewTonRepson;
import com.UI.UiRegularFalsi;
import com.UI.UiSecant;

public class Main
{
	static JFrame frame;
	public static void main(String args[])
	{
		frame=new JFrame("Neumerical analysis");
		frame.setSize(400, 400);
		JPanel panel=new JPanel();
		JLabel l1=new JLabel("Tanvir Hasan - 12101005");
		JLabel l2=new JLabel("Tanmoy Ahmed");
		JLabel l3=new JLabel("Zafor Iqbal");
		JLabel l4=new JLabel("Masud Bappi");
		JButton b1=new JButton("Start");
		frame.add(panel);
		panel.add(l1);
		panel.add(l2);
		panel.add(l3);
		panel.add(l4);
		panel.add(b1);
		panel.setLayout(null);
		l1.setBounds(10, 10, 500, 20);
		l2.setBounds(l1.getX(), l1.getY()+l1.getHeight()+10, 500, 20);
		l3.setBounds(l2.getX(), l2.getY()+l2.getHeight()+10, 500, 20);
		l4.setBounds(l3.getX(), l3.getY()+l3.getHeight()+10, 500, 20);
		b1.setBounds(l4.getX()+100, l4.getY()+l4.getHeight()+10, 100, 40);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		b1.addActionListener(new ActionListener() 
		{
			
			@Override
			public void actionPerformed(ActionEvent arg0)
			{
				// TODO Auto-generated method stub
				Menu Me=new Menu();
				Me.Gen();
				frame.dispose();
			}
		});
		
	}
}