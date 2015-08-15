#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a,b,c,d,n;  /*分别定义随机产生四位数中的千，百，十，个位及该数字*/
    int x1,x2,x3,x4,number; /*定义用户输入的千，百，十，个位及该数字*/
    int i=1;       /*定义计数变量*/
    srand(time(NULL));
    /*随机生成一个各位相异的四位数*/
    do{
        a=rand()%9+1;
        b=rand()%10;
        c=rand()%10;
        d=rand()%10;
    }while(a==b||a==c||a==d||b==c||b==d||c==d);
    n=a*1000+b*100+c*10+d;
    printf("Please enter the times that you want to guess:");
    scanf("%d",&number);  /*由用户输入猜的次数*/
    do{
            printf("Please input the number that you guess:");
            scanf("%1d",&x1);
            scanf("%1d",&x2);
            scanf("%1d",&x3);
            scanf("%1d",&x4);
            if(n==x1*1000+x2*100+x3*10+x4)
            {
                printf("Congratulations!");
            }
            else
            {
                int x=0,y=0;
                int j,k;     /*定义两个计数变量*/
                int guess[4]={x1,x2,x3,x4}; /*定义数组，由用户输入的数字的各位组成*/
                int number[4]={a,b,c,d};    /*定义数组，由计算机随机产生的数字各位组成*/
                /*分别匹配各位上的数字*/
                for(j=0;j<4;j++)
                {
                    for(k=0;k<4;k++)
                    {
                        if(guess[j]==number[k])
                            y+=1;
                        if(guess[j]==number[k] && j==k)
                            x+=1;
                    }
                }
                printf("%dA%dB\n",x,y);
            }
            i+=1;
        }while(n!=x1*1000+x2*100+x3*10+x4 && i<=number);
    /*超出规定次数游戏结束，输出答案*/
    if(i>number)
    {
        printf("Sorry, you haven't guess the right number!");
        printf("%d",n);
    }
    return 0;
}
