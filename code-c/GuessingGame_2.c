#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MakeMagic(void); /*�����������ɺ���*/
int Match(int magic,int guess);  /*�����ж�ƥ�亯��*/

int main()
{
    int magic,guess; /*����������������û��²���*/
    int counter=0,ret,flag; /*�����������,�жϺϷ���������ͷ���ֵ����*/
    char reply;      /*�����û�����Ļش�*/
    do{
        counter=0;  /*����һ����ǰ������������*/
        magic=MakeMagic();
        do{
            printf("Please guess a magic number:");
            ret=scanf("%d",&guess);
            while(ret!=1)  /*�������������������*/
            {
                while(getchar()!='\n'); /*����������еķǷ��ַ�*/
                printf("Please guess a magic number:");
                ret=scanf("%d",&guess);
            }
            counter++;
            flag=Match(guess,magic);
        }while(flag!=3 && counter<10); /*�²��Ե�δ����10�μ�����*/
        printf("counter = %d\n",counter);
        printf("Do you want to continue(Y/N or y/n)?"); /*��ʾ�Ƿ����*/
        scanf(" %c",&reply);
    }while(reply=='Y'||reply=='y'); /*�ش�ΪY��y����*/
    return 0;
}

/*�������ɺ���*/
int MakeMagic(void)
{
    int x;
    srand(time(NULL));
    x=rand()%100+1;
    return x;
}

/*�ж�ƥ�亯��*/
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

