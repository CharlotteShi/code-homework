public class Jaspar
{
	public static void main(String[]args)
	{
		int Explorer[]=new int[30]; /* 定义数组Explorer存放30个探险者，初始值都为0*/
		int n=Explorer.length;      /*n为数组初始长度即总人数*/
		int i,j,k;
		for(i=0,j=0,k=0;k<n/2;i=(i+1)%n)
		{
			if(Explorer[i]==0)
			{
				j=(j+1)%9;
			}
			if(j==0&&Explorer[i]==0)
			{
				k++;
				Explorer[i]=1;   /*值变为1代表站在该位置的人会被扔到海里*/
			}
		}
		System.out.println("If you start counting from the first one, then Catholics should stand in the following locations:");
		for(i=0;i<n;i++)
		{
			if(Explorer[i]==0)
			{
				System.out.println(i+1);
			}
		}
	}
}