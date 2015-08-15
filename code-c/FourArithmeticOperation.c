#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Computer(int a,int b,int op); /*定义运算函数*/
void Print(int flag);             /*定义打印函数*/
int main()
{
    int a,b,op; /*定义随机数变量*/
    int flag,i; /*定义计数变量*/
    int sum=0,count=0,times=0; /*定义分数，错误次数，循环次数变量*/
    srand(time(NULL));
    for(i=1;i<=10;i++)
    {
        flag=Computer(a,b,op);
        Print(flag);
        if(flag==1)
        {
            sum+=10;
            times+=1;
        }
        else if(flag==0)
        {
            count+=1;
            times+=1;
        }

    }
    /*达到10次输出分数和做错的题数*/
    if(times==10)
    {
        printf("%d\n%d",sum,count);
    }
    return 0;
}

int Computer(int a,int b,int op)
{
    do{
        int answer; /*保存用户输入的回答*/
        a=rand()%10+1;
        b=rand()%10+1;
        op=rand()%4+1;
        /*加法运算*/
        if(op==1)
        {
            printf("%d+%d=",a,b);
            scanf("%d",&answer);
            if(answer==a+b)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        /*减法运算*/
        else if(op==2)
        {
            if(a>=b)
            {
                printf("%d-%d=",a,b);
                scanf("%d",&answer);
                if(answer==a-b)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                printf("%d-%d=",b,a);
                scanf("%d",&answer);
                if(answer==b-a)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        /*乘法运算*/
        else if(op==3)
        {
            printf("%d*%d=",a,b);
            scanf("%d",&answer);
            if(answer==a*b)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        /*除法运算*/
        else if(op==4)
        {
            if(a%b==0)
            {
                printf("%d/%d=",a,b);
                scanf("%d",&answer);
                if(answer==a/b)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }while(a%b!=0);
    return 0;
}

/*打印运算结果函数*/
void Print(int flag)
{
    if(flag==1)
    {
        printf("Right!\n");
    }
    else if(flag==0)
    {
        printf("Not correct!\n");
    }
}
