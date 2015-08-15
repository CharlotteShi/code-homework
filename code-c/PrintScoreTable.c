#include <stdio.h>
#define Student 30

int Input(long num[],int score[][3]);
/*����ѧ��ѧ�ż����ųɼ������ذ༶ʵ������*/
void Total1(int score[][3],float sum1[],float aver1[],int n);
/*����ÿ��ѧ�����ֺܷ�ƽ����*/
void Total2(int score[][3],float sum2[],float aver2[],int n);
/*����ÿ�ſε��ֺܷ�ƽ����*/
void Total3(long num[],int score[][3],float sum1[],float aver1[],int n);
/*��ÿ��ѧ�������ܷ��ɸߵ�������*/
void Print(long num[],int score[][3],float sum1[],float aver1[],float sum2[],float aver2[],int n);
/*��ӡѧ���ɼ���ÿ�ſε��ֺܷ�ƽ����*/

int main()
{
    int n;                 /*����Ϊ�༶ʵ������*/
    long num[Student];     /*���ѧ��*/
    int score[Student][3];        /*��ŷ���*/
    float sum1[Student];   /*���ÿ��ѧ�����ܷ�*/
    float aver1[Student];  /*���ÿ��ѧ����ƽ����*/
    float sum2[3]={0};         /*���ÿ�ſε��ܷ�*/
    float aver2[3]={0};        /*���ÿ�ſε�ƽ����*/
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
    int i,j,k;                   /*��������*/
    float temp1,temp2;
    long temp3;
    int temp4; /*�м����*/
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(sum1[j]>sum1[i])
            {
                temp1=sum1[j];
                sum1[j]=sum1[i];
                sum1[i]=temp1;                /*���ֽܷ����ɸߵ�������*/
                temp2=aver1[j];
                aver1[j]=aver1[i];
                aver1[i]=temp2;              /*�����ܷ�����仯����ƽ��������*/
                temp3=num[j];
                num[j]=num[i];
                num[i]=temp3;               /*�����ܷ�����仯����ѧ������*/
                for(k=0;k<3;k++)
                {
                    temp4=score[j][k];
                    score[j][k]=score[i][k];
                    score[i][k]=temp4;
                }                           /*�����ܷ�����仯�������Ʒ�������*/
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
