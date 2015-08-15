#include <stdio.h>

 int main()
 {
     int magic[5][5]; /*定义二维数组存储矩阵中的元素*/
     int sum[12];    /*定义数组存储每一行每一列及对角线的元素之和*/
     int i,j,n;      /*计数变量*/
     int counter=0;  /*计数变量*/
	 /*读取矩阵中的元素存到数组magic中*/
     for(i=0;i<5;i++)
     {
         for(j=0;j<5;j++)
         {
             scanf("%d",&magic[i][j]);
         }
     }
	 /*在数组sum中添加每一行的元素之和*/
     for(i=0;i<5;i++)
     {
         int x=0;
         x=magic[i][0]+magic[i][1]+magic[i][2]+magic[i][3]+magic[i][4];
         sum[i]=x;
     }
	 /*在数组sum中添加每一列的元素之和*/
     for(j=0;j<5;j++)
     {
         int x=0;
         x=magic[0][j]+magic[1][j]+magic[2][j]+magic[3][j]+magic[4][j];
         sum[j+5]=x;
     }
	 /*在数组sum中添加对角线元素之和*/
     sum[10]=magic[0][0]+magic[1][1]+magic[2][2]+magic[3][3]+magic[4][4];
     sum[11]=magic[0][4]+magic[1][3]+magic[2][2]+magic[3][1]+magic[4][0];
	 /*判断sum中元素是否有相等的并输出结果*/
     for(n=0;n<11;n++)
     {
         if(sum[n]!=sum[n+1])
            counter+=1;
     }
     if(counter==0)
     {
             for(i=0;i<5;i++)
             {
                 for(j=0;j<5;j++)
                 {
                     printf("%4d",magic[i][j]);
                 }
                 printf("\n");
             }
     }
     else
     {
         printf("No");
     }
     return 0;
 }
