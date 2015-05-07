package com.UI;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextPane;

public class Show
{
	private JFrame frame;
	private JPanel panel;
	private JScrollPane pane;
	private JButton B1;
	private JTextArea txt;
	public Show(String ans,String name)
	{
		frame = new JFrame(name+" Output");
		frame.setSize(600, 600);
		panel =new JPanel();
		txt=new JTextArea();
		pane =new JScrollPane(txt);
		pane.setPreferredSize(new Dimension(360,300));
		B1 =new JButton("Close");
		frame.add(panel);
		panel.add(pane);
		txt.setText(ans);
		pane.setBackground(Color.black);
		txt.setEditable(false);
		panel.add(B1);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		B1.addActionListener(new ActionListener() 
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