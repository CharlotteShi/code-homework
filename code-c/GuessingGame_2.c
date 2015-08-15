#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MakeMagic(void); /*定义数字生成函数*/
int Match(int magic,int guess);  /*定义判断匹配函数*/

int main()
{
    int magic,guess; /*定义随机生成数和用户猜测数*/
    int counter=0,ret,flag; /*定义计数变量,判断合法输入变量和返回值变量*/
    char reply;      /*保存用户输入的回答*/
    do{
        counter=0;  /*猜下一个数前将计数器清零*/
        magic=MakeMagic();
        do{
            printf("Please guess a magic number:");
            ret=scanf("%d",&guess);
            while(ret!=1)  /*若输入错误则重新输入*/
            {
                while(getchar()!='\n'); /*清除缓冲区中的非法字符*/
                printf("Please guess a magic number:");
                ret=scanf("%d",&guess);
            }
            counter++;
            flag=Match(guess,magic);
        }while(flag!=3 && counter<10); /*猜不对但未超过10次继续猜*/
        printf("counter = %d\n",counter);
        printf("Do you want to continue(Y/N or y/n)?"); /*提示是否继续*/
        scanf(" %c",&reply);
    }while(reply=='Y'||reply=='y'); /*回答为Y或y继续*/
    return 0;
}

/*数字生成函数*/
int MakeMagic(void)
{
    int x;
    srand(time(NULL));
    x=rand()%100+1;
    return x;
}

/*判断匹配函数*/
int Match(int guess,int magic)
{
    if(guess>magic)
    {
        printf("Wrong! Too big!\n");
        return 1;
    }
    else if(guess<magic)
    {
        printf("Wrong! Too small!\n");
        return 2;
    }
    else
    {
        printf("Right!\n");
        return 3;
    }
}

