#include <stdio.h>
#define Student 30

int Input(long num[],int score[][3]);
/*输入学生学号及各门成绩，返回班级实际人数*/
void Total1(int score[][3],float sum1[],float aver1[],int n);
/*计算每个学生的总分和平均分*/
void Total2(int score[][3],float sum2[],float aver2[],int n);
/*计算每门课的总分和平均分*/
void Total3(long num[],int score[][3],float sum1[],float aver1[],int n);
/*对每个学生按照总分由高到低排序*/
void Print(long num[],int score[][3],float sum1[],float aver1[],float sum2[],float aver2[],int n);
/*打印学生成绩表及每门课的总分和平均分*/

int main()
{
    int n;                 /*定义为班级实际人数*/
    long num[Student];     /*存放学号*/
    int score[Student][3];        /*存放分数*/
    float sum1[Student];   /*存放每个学生的总分*/
    float aver1[Student];  /*存放每个学生的平均分*/
    float sum2[3]={0};         /*存放每门课的总分*/
    float aver2[3]={0};        /*存放每门课的平均分*/
    n=Input(num,score);
    Total1(score,sum1,aver1,n);
    Total2(score,sum2,aver2,n);
    Total3(num,score,sum1,aver1,n);
    Print(num,score,sum1,aver1,sum2,aver2,n);
    return 0;
}

int Input(long num[],int score[][3])
{
    int i=-1;
    do{
        i++;
        scanf("%ld%d%d%d",&num[i],&score[i][0],&score[i][1],&score[i][2]);
    }while(num[i]>0 && i<30);
    return i;
}

void Total1(int score[][3],float sum1[],float aver1[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        sum1[i]=score[i][0]+score[i][1]+score[i][2];
        aver1[i]=(float)sum1[i]/3;
    }
}

void Total2(int score[][3],float sum2[],float aver2[],int n)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<n;j++)
        {
            sum2[i]+=(float)score[j][i];
        }
        aver2[i]=sum2[i]/n;
    }
}

void Total3(long num[],int score[][3],float sum1[],float aver1[],int n)
{
    int i,j,k;                   /*计数变量*/
    float temp1,temp2;
    long temp3;
    int temp4; /*中间变量*/
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(sum1[j]>sum1[i])
            {
                temp1=sum1[j];
                sum1[j]=sum1[i];
                sum1[i]=temp1;                /*对总分进行由高到低排序*/
                temp2=aver1[j];
                aver1[j]=aver1[i];
                aver1[i]=temp2;              /*根据总分排序变化调整平均分排序*/
                temp3=num[j];
                num[j]=num[i];
                num[i]=temp3;               /*根据总分排序变化调整学号排序*/
                for(k=0;k<3;k++)
                {
                    temp4=score[j][k];
                    score[j][k]=score[i][k];
                    score[i][k]=temp4;
                }                           /*根据总分排序变化调整各科分数排序*/
            }
        }
    }
}

void Print(long num[],int score[][3],float sum1[],float aver1[],float sum2[],float aver2[],int n)
{
    printf("Pos\tNumber\tGrad1\tGrad2\tGrad3\tSum1\tAver1\n");
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%d\t%ld\t%d\t%d\t%d\t%.0f\t%.0f\n",i+1,num[i],score[i][0],score[i][1],score[i][2],sum1[i],aver1[i]);
    }
    printf( "No\tSum2\tAver2\n");
    for(j=0;j<3;j++)
    {
        printf("%d\t%.0f\t%.0f\n",j+1,sum2[j],aver2[j]);
    }
}
