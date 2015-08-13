import java.util.*;
import javax.swing.*;

public class printContinuousNum
{
	public static void main(String[]args)
	{
		int n;
		String input;
		input=JOptionPane.showInputDialog("Input a number:");
		n=Integer.parseInt(input);
		for(int i=2;(2*i-1)*(2*i-1)-1<8*n;i++)
		{
			if((n-i*(i-1)/2)%i==0)
			{
				int x=(n-i*(i-1)/2)/i;
				int j=0;
				while(j<i)
				{
					System.out.println(x+"");
					x++;
					j++;
				}
				System.out.println();
			}
		}
	}
}