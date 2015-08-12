import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calculator 
{
	public static void main(String[]args)
	{
		MyFrame frame=new MyFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.show();
	}
}

class MyFrame extends JFrame
{
	public MyFrame()
	{
		setTitle("Exercise16_4");
		setSize(WIDTH,HEIGHT);
		setResizable(false);
		MyPanel panel_1=new MyPanel();
		//ButtonPanel panel_2=new ButtonPanel();
		Container contentPane=getContentPane();
		contentPane.add(panel_1);
		//contentPane.add(panel_2,BorderLayout.SOUTH);
	}
	public static final int WIDTH=500;
	public static final int HEIGHT=150;
}

class MyPanel extends JPanel
{
	JLabel label_1,label_2,label_3;
	JTextField num_1,num_2,result;
	public MyPanel()
	{
		label_1=new JLabel("Number 1");
		label_2=new JLabel("Number 2");
		label_3=new JLabel("Result");
		num_1=new JTextField("	");
		num_2=new JTextField("	");
		result=new JTextField("	");
		add(label_1);
		add(num_1);
		add(label_2);
		add(num_2);
		add(label_3);
		add(result);
		makeButton("Add",'+');
		makeButton("Subtract",'-');
		makeButton("Multiply",'*');
		makeButton("Divide",'/');
	}

	JButton btn;
	public void makeButton(String s,char op)
	{
		btn=new JButton(s);
		add(btn);
		btn.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent event)
			{
				result.setText(getResult(op));
			}
		});
	}
	public String getResult(char x)
	{
		float m=0.0f;
		switch(x)
		{
			case'+':m=Float.parseFloat(num_1.getText())+Float.parseFloat(num_2.getText());
				break;
			case'-':m=Float.parseFloat(num_1.getText())-Float.parseFloat(num_2.getText());
				break;
			case'*':m=Float.parseFloat(num_1.getText())*Float.parseFloat(num_2.getText());
				break;
			case'/':m=Float.parseFloat(num_1.getText())/Float.parseFloat(num_2.getText());
				break;
		}
		return Float.toString(m);
	}
}


