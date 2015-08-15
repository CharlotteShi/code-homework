#include <stdio.h>
#include <stdlib.h>

/*定义结构体*/
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
    int m; /*定义变量表示实际人数*/
    STUDENT *stu=NULL; /*定义指针指向学号姓名和分数*/
    int *sum=NULL;     /*指向第一个学生的总分*/
    float *ave=NULL;   /*指向第一个学生的平均分*/
    scanf("%d",&m);    /*输入实际人数*/
    stu=(struct student*)malloc(m*sizeof(struct student)); /*申请内存存放结构体*/
    sum=(int *)malloc(m*sizeof(int));                      /*申请内存存放总分*/
    ave=(float *)malloc(m*sizeof(float));                  /*申请内存存放平均分*/
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
函数功能：读取数据
函数参数：p 指向存放结构体变量的第一个存储单元，n班级实际人数；
返回值： 无
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
函数功能：计算每个学生的总分和平均分
函数参数：p指向存放结构体变量的第一个存储单元
                 psum 指向存放总分的第一个存储单元
                 pave指向存放平均分的第一个存储单元
                 n班级实际人数
返回值：无
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
函数功能：将每个学生按照平均分由高到低排序
函数参数：p 指向存放结构体变量的第一个存储单元
                psum 指向存放总分的第一个存储单元，
                pave 指向存放平均分的第一个存储单元
                n 班级实际人数
返回值：无
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
函数功能：打印学生成绩表
函数参数：p指向存放结构体变量的第一个存储单元
                psum 指向存放总分的第一个存储单元
                pave 指向存放平均分的第一个存储单元
                n 班级实际人数
返回值：无
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
    fprintf(fp,"名次\t学号\t姓名\t英语\t计算机\t数学\t总分\t平均分\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d\t%ld\t%s\t%d\t%d\t%d\t%d\t%.0f\n",i+1,p[i].studentID,p[i].studentName,p[i].score[0],p[i].score[1],p[i].score[2],psum[i],pave[i]);
    }
    fclose(fp);
}

