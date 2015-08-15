#include <stdio.h>
#include <stdlib.h>

/*����ṹ��*/
typedef struct student
{
    long studentID;
    char studentName[10];
    int score[3];
}STUDENT;

void Input(struct student *p,int n);
void Total1(struct student *p,int*psum,float*pave,int n);
void Sort(struct student *p,int*psum,float*pave,int n);
void Print(struct student *p,int*psum,float*pave,int n);

int main()
{
    int m; /*���������ʾʵ������*/
    STUDENT *stu=NULL; /*����ָ��ָ��ѧ�������ͷ���*/
    int *sum=NULL;     /*ָ���һ��ѧ�����ܷ�*/
    float *ave=NULL;   /*ָ���һ��ѧ����ƽ����*/
    scanf("%d",&m);    /*����ʵ������*/
    stu=(struct student*)malloc(m*sizeof(struct student)); /*�����ڴ��Žṹ��*/
    sum=(int *)malloc(m*sizeof(int));                      /*�����ڴ����ܷ�*/
    ave=(float *)malloc(m*sizeof(float));                  /*�����ڴ���ƽ����*/
    Input(stu,m);
    Total1(stu,sum,ave,m);
    Sort(stu,sum,ave,m);
    Print(stu,sum,ave,m);
    free(stu);
    free(sum);
    free(ave);
    return 0;
}

/*
�������ܣ���ȡ����
����������p ָ���Žṹ������ĵ�һ���洢��Ԫ��n�༶ʵ��������
����ֵ�� ��
*/
void Input(struct student *p,int n)
{
    int i,j;
    FILE *fp;
    if((fp=fopen("D:\\data.txt","w"))==NULL)
    {
        printf("Failure to open data.txt!\n");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        scanf("%ld",&p[i].studentID);
        fprintf(fp,"%ld\t",p[i].studentID);
        scanf("%s",p[i].studentName);
        fprintf(fp,"%s\t",p[i].studentName);
        for(j=0;j<3;j++)
        {
            scanf("%d",&p[i].score[j]);
            fprintf(fp,"%d\t",p[i].score[j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    if((fp=fopen("D:\\data.txt","r"))==NULL)
    {
        printf("Failure to open data.txt!\n");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%ld",&p[i].studentID);
        fscanf(fp,"%s",p[i].studentName);
        for(j=0;j<3;j++)
        {
            fscanf(fp,"%d",&p[i].score[j]);
        }
    }
    fclose(fp);
}

/*
�������ܣ�����ÿ��ѧ�����ֺܷ�ƽ����
����������pָ���Žṹ������ĵ�һ���洢��Ԫ
                 psum ָ�����ֵܷĵ�һ���洢��Ԫ
                 paveָ����ƽ���ֵĵ�һ���洢��Ԫ
                 n�༶ʵ������
����ֵ����
*/
void Total1(struct student *p,int*psum,float*pave,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        psum[i]=0;
        for(j=0;j<3;j++)
        {
            psum[i]=psum[i]+p[i].score[j];
        }
        pave[i]=(float)psum[i]/3;
    }
}

/*
�������ܣ���ÿ��ѧ������ƽ�����ɸߵ�������
����������p ָ���Žṹ������ĵ�һ���洢��Ԫ
                psum ָ�����ֵܷĵ�һ���洢��Ԫ��
                pave ָ����ƽ���ֵĵ�һ���洢��Ԫ
                n �༶ʵ������
����ֵ����
*/
void Sort(struct student *p,int*psum,float*pave,int n)
{
    int i,j;
    STUDENT temp_stu;
    int temp_sum;
    float temp_ave;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pave[j]>pave[i])
            {
                temp_ave=pave[i];
                pave[i]=pave[j];
                pave[j]=temp_ave;
                temp_sum=psum[i];
                psum[i]=psum[j];
                psum[j]=temp_sum;
                temp_stu=p[i];
                p[i]=p[j];
                p[j]=temp_stu;
            }
        }
    }
}

/*
�������ܣ���ӡѧ���ɼ���
����������pָ���Žṹ������ĵ�һ���洢��Ԫ
                psum ָ�����ֵܷĵ�һ���洢��Ԫ
                pave ָ����ƽ���ֵĵ�һ���洢��Ԫ
                n �༶ʵ������
����ֵ����
*/
void Print(struct student *p,int*psum,float*pave,int n)
{
    FILE *fp;
    int i;
    if((fp=fopen("D:\\Output.txt","w"))== NULL)
    {
        printf("Failure to open Output.txt!\n");
        exit(0);
    }
    fprintf(fp,"����\tѧ��\t����\tӢ��\t�����\t��ѧ\t�ܷ�\tƽ����\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d\t%ld\t%s\t%d\t%d\t%d\t%d\t%.0f\n",i+1,p[i].studentID,p[i].studentName,p[i].score[0],p[i].score[1],p[i].score[2],psum[i],pave[i]);
    }
    fclose(fp);
}

