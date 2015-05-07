package com.UI;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Menu
{
	private JFrame frame;
	private JPanel panel;
	private JButton b1,b2,b3,b4,b5,b6;
	public Menu()
	{
		frame=new JFrame("Menu");
		frame.setSize(600,600);
		panel=new JPanel();
		b1=new JButton("Bisection");
		b2=new JButton("Newton Repson");
		b3=new JButton("Regular Falasi");
		b4=new JButton("Secant");
		b5=new JButton("Function");
		b6=new JButton("Close");
	}
	public void Gen()
	{
		frame.add(panel);
		panel.add(b1);
		panel.add(b2);
		panel.add(b3);
		panel.add(b4);
		panel.add(b5);
		panel.add(b6);
		panel.setLayout(new GridLayout(3,2));
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		b1.addActionListener(new ActionListener() 
		{
			
			@Override
			public void actionPerformed(ActionEvent arg0) 
			{
				// TODO Auto-generated method stub
				UiBisection Bi=new UiBisection();
				Bi.Gen();
			}
		});
		b2.addActionListener(new ActionListener() 
		{
			
			@Override
			public void actionPerformed(ActionEvent e) 
			{
				// TODO Auto-generated method stub
				UiNewTonRepson Ne=new UiNewTonRepson();
				Ne.Gen();
			}
		});
		b3.addActionListener(new ActionListener() 
		{
			
			@Override
			public void actionPerformed(ActionEvent e) 
			{
				// TODO Auto-generated method stub
				UiRegularFalsi Re=new UiRegularFalsi();
				Re.Gen();
				
			}
		});
		b4.addActionListener(new ActionListener() 
		{
			
			@Override
			public void actionPerformed(ActionEvent e) 
			{
				// TODO Auto-generated method stub
				UiSecant Se=new UiSecant();
				Se.Gen();
				
			}
		});
		b5.addActionListener(new ActionListener() 
		{
			
			@Override
			public void actionPerformed(ActionEvent e)
			{
				// TODO Auto-generated method stub
				UiFunction F=new UiFunction();
				F.Gen();
			}
		});
		b6.addActionListener(new ActionListener() 
		{
			
			@Override
			public void actionPerformed(ActionEvent e) 
			{
				// TODO Auto-generated method stub
				frame.dispose();
			}
		});
	}
}