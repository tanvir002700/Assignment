package com.UI;

import java.awt.Color;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JWindow;

import com.Function.Function;
import com.Numerical.Bisection;

public class UiFunction
{
	private JFrame frame;
	private JPanel panel;
	private JLabel l1;
	private JTextField txtF;
	private JLabel l2;
	private JButton b1;
	public UiFunction()
	{
		frame=new JFrame("f(x) = x^4 - 7x^2 -10 ");
		panel=new JPanel();
		l1=new JLabel("f(x): ");
		txtF=new JTextField();
		l2=new JLabel("Y = f(x): ");
		b1=new JButton("Close");
	}
	public void Gen()
	{
		frame.add(panel);
		frame.setSize(600, 200);
		panel.add(l1);
		panel.add(txtF);
		panel.add(l2);
		panel.add(b1);
		txtF.setBackground(Color.cyan);
		panel.setLayout(null);
		l1.setBounds(50,50,30,20);
		txtF.setBounds(l1.getX()+l1.getWidth()+10, l1.getY(), 100, 25);
		l2.setBounds(txtF.getX(), txtF.getY()+txtF.getHeight()+10, 500, 20);
		b1.setBounds(l1.getX(), l2.getY()+l2.getHeight()+10, 100, 25);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		txtF.addActionListener(new ActionListener()
		{
			
			@Override
			public void actionPerformed(ActionEvent arg0) 
			{
				// TODO Auto-generated method stub
				String v=txtF.getText();
				txtF.setText("");
				try
				{
					double x=new Double(v);
					Function F=new Function();
					String ans= F.Gen(x);
					l2.setText("Y = "+ans);
				} 
				catch (NumberFormatException e) 
				{
					// TODO Auto-generated catch block
					JOptionPane.showMessageDialog(null, "Oie mia thik vabe input Den\n");
				}
			}
		});
		b1.addActionListener(new ActionListener() 
		{
			
			@Override
			public void actionPerformed(ActionEvent arg0) 
			{
				// TODO Auto-generated method stub
				frame.dispose();
			}
		});
	}
}