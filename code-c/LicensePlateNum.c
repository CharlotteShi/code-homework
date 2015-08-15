#include <stdio.h>
#include <math.h>
int main()
{
    int number; /*车牌号*/
    int i=1;  /*车牌号前两位每位的数字*/
    for(i=1;i<=9;i++)
    {
        int j=0;  /*车牌号后两位每位的数字*/
        for(j=0;j<=9;j++)
        {
            if(j==i)
                break; /*控制前两位与后两位不等*/
            else
                {
                    int c; /*车牌号开方所得数*/
                    number=i*1000+i*100+j*10+j;
                    for (c=1;c<number;c++)
                    {
                        if(c==sqrt((float)number))
                            printf("The number is:%d",number);
                    }
                }
        }
    }
    return 0;
}
