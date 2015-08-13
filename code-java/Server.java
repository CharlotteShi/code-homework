import java.io.*;
import java.net.*;

public class Server
{
	public static void main(String[]args)
	{
		int clientArray[]=new int[100];
		ServerSocket server=null;
		Socket you=null;
		DataInputStream in=null;
		DataOutputStream out=null;
		try
		{
			server=new ServerSocket(2333);
		}
		catch(IOException e1)
		{
			System.out.println("Error:"+e1);
		}
		try
		{
			you=server.accept();
			in=new DataInputStream(you.getInputStream());
			out=new DataOutputStream(you.getOutputStream());
			while(true)
			{
				for(int i=0;i<100;i++)
				{
					clientArray[i]=in.readInt();
				}
				if(clientArray[99]!=0)
					break;
			}
			for(int i=0;i<100;i++)
			{
				System.out.println(clientArray[i]);
				out.writeInt(clientArray[i]*2);
			}
			you.close();
		}
		catch(IOException e)
		{
			System.out.println("Erro:"+e);
		}
	}
}