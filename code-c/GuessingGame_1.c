#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a,b,c,d,n;  /*�ֱ������������λ���е�ǧ���٣�ʮ����λ��������*/
    int x1,x2,x3,x4,number; /*�����û������ǧ���٣�ʮ����λ��������*/
    int i=1;       /*�����������*/
    srand(time(NULL));
    /*�������һ����λ�������λ��*/
    do{
        a=rand()%9+1;
        b=rand()%10;
        c=rand()%10;
        d=rand()%10;
    }while(a==b||a==c||a==d||b==c||b==d||c==d);
    n=a*1000+b*100+c*10+d;
    printf("Please enter the times that you want to guess:");
    scanf("%d",&number);  /*���û�����µĴ���*/
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
                int j,k;     /*����������������*/
                int guess[4]={x1,x2,x3,x4}; /*�������飬���û���������ֵĸ�λ���*/
                int number[4]={a,b,c,d};    /*�������飬�ɼ����������������ָ�λ���*/
                /*�ֱ�ƥ���λ�ϵ�����*/
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
    /*�����涨������Ϸ�����������*/
    if(i>number)
    {
        printf("Sorry, you haven't guess the right number!");
        printf("%d",n);
    }
    return 0;
}
