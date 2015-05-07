import java.applet.Applet;
import java.awt.Button;
import java.awt.Graphics;
import java.awt.TextArea;
import java.awt.TextField;

public class test extends Applet
{
    TextField t1 = new TextField(50);
    TextArea t2 = new TextArea();
    Button b1 = new Button("Save");
    Button b2 = new Button("Open");
    public void init()
    {
    	//this.setSize(500, 500);
        setLayout(null);
        add(t1);
        add(t2);
        add(b1);
        add(b2);
    } public void paint(Graphics g)
    {
        t1.setLocation(10, 10);
        t1.setSize(300, 25);
        t2.setLocation(10, 40);
        t2.setSize(300, 300);
        b1.setLocation(30, 350);
        b1.setSize(50,25);
        b2.setLocation(100, 350);
        b2.setSize(50,25);
    }
}
