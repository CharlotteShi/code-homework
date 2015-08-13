import java.io.*;
import java.net.*;

public class Client
{
	public static void main(String[]args)
	{
		int clientArray[]=new int[100];
		for(int i=0;i<100;i++)
		{
			clientArray[i]=i+1;
		}
		int serverArray[]=new int[100];
		Socket mysocket;
		DataInputStream in=null;
		DataOutputStream out=null;
		try
		{
			mysocket=new Socket("localhost",2333);
			in=new DataInputStream(mysocket.getInputStream());
			out=new DataOutputStream(mysocket.getOutputStream());
			for(int i=0;i<100;i++)
			{
				out.writeInt(clientArray[i]);
			}
			while(true)
			{
				for(int i=0;i<100;i++)
				{
					serverArray[i]=in.readInt();
				}
				if(clientArray[99]!=0)
					break;
			}
			mysocket.close();
		}
		catch(IOException e)
		{
			System.out.println("Not connected");
		}
		for(int i=0;i<100;i++)
		{
			System.out.println(serverArray[i]+" ");
		}
	}
}