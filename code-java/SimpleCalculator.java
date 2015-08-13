import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class SimpleCalculator extends JFrame implements ActionListener
{
		JPanel NumPanel=new JPanel();
		JPanel ButtonPanel=new JPanel();
		
		JLabel label_1=new JLabel("Number 1");
		JLabel label_2=new JLabel("Number 2");
		JLabel label_3=new JLabel("Result");
		JTextField num_1=new JTextField("                ");
		JTextField num_2=new JTextField("                ");
		JTextField result=new JTextField("	");
		
		JButton btn_1=new JButton("Add");
		JButton btn_2=new JButton("Subtract");
		JButton btn_3=new JButton("Multiply");
		JButton btn_4=new JButton("Divide");
		
		Container cp=getContentPane();
		BorderLayout border=new BorderLayout(2,5);
		
	public static void main(String[]args)
	{
		SimpleCalculator frame=new SimpleCalculator();
	}	
	public SimpleCalculator()
	{
		setTitle("Exercise16_4");
		setSize(500,150);
		setVisible(true);
		
		NumPanel.add(label_1);NumPanel.add(num_1);
		NumPanel.add(label_2);NumPanel.add(num_2);
		NumPanel.add(label_3);NumPanel.add(result);
		
		ButtonPanel.add(btn_1);ButtonPanel.add(btn_2);
		ButtonPanel.add(btn_3);ButtonPanel.add(btn_4);
		
		cp.setLayout(border);
		cp.add(NumPanel,border.NORTH);
		cp.add(ButtonPanel,border.SOUTH);
		
		btn_1.addActionListener(this);
		btn_2.addActionListener(this);
		btn_3.addActionListener(this);
		btn_4.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e)
	{
		float m=0.0f;
		JButton btn=(JButton)e.getSource();
		if(btn==btn_1)
		{
			m=Float.parseFloat(num_1.getText())+Float.parseFloat(num_2.getText());
			result.setText(Float.toString(m));
		}
		else if(btn==btn_2)
		{
			m=Float.parseFloat(num_1.getText())-Float.parseFloat(num_2.getText());
			result.setText(Float.toString(m));
		}
		else if(btn==btn_3)
		{
			m=Float.parseFloat(num_1.getText())*Float.parseFloat(num_2.getText());
			result.setText(Float.toString(m));
		}
		else
		{
			m=Float.parseFloat(num_1.getText())/Float.parseFloat(num_2.getText());
			result.setText(Float.toString(m));
		}
	}
}



