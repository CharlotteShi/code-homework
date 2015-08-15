#include <stdio.h>
#include <stdlib.h>

int FindMax(int *pScore,int m,int n,int *prow,int *pcol);

int main()
{
    int *score=NULL;   /*指向第一个考生第一门课的考试成绩*/
    int m,n,ScoreMax; /*定义变量m考生人数，n考试科目，ScoreMax最高分数*/
    int row=0,col=0; /*定义变量row最高分所在行，col最高分所在列*/
    long *Number=NULL; /*指向第一个考生的学号*/
    char **Name=NULL,**Course=NULL; /*指向第一个考生姓名的地址，指向第一门科目的地址*/
    int i,j;   /*定义计数变量*/
    scanf("%d",&m);  /*读入考生人数*/
    scanf("%d",&n);  /*读入考试科目*/
    getchar();
    Number=(long*)malloc(m*sizeof(long)); /*申请存放考号的内存*/
    Name=(char**)malloc(m*sizeof(char*)); /*申请存放姓名的内存*/
    score=(int*)calloc(m*n,sizeof(int));  /*申请存放分数的内存*/
    Course=(char**)malloc(n*sizeof(char*)); /*申请存放科目的内存*/
    for(i=0;i<n;i++)
    {
        Course[i]=(char*)malloc(100*sizeof(char));
        scanf(" %s",Course[i]);
    }
    for(i=0;i<m;i++)
    {
        Name[i]=(char*)malloc(100*sizeof(char));
        scanf("%ld %s",&Number[i],Name[i]);
        for(j=0;j<n;j++)
        {
            scanf("%d",&score[i*n+j]);
        }
    }
    ScoreMax=FindMax(score,m,n,&row,&col);
    printf("Grade\tNumber\tName\tCourse\n");
    printf("%d\t%ld\t%s\t%s\n",ScoreMax,Number[row],Name[row],Course[col]);
	free(Number);
	free(Name);
	free(score);
	free(Course);
    return 0;
}

/*
功能：找出最高分
参数：指针 *pScore指向第一个考生第一门课的考试成绩（列指针）；
    m考生人数；n考试科目；
    指针 *prow 用于返回最高分所在的行；
    指针 *pcol 用于返回最高分所在的列
返回值：返回最高分
*/
int FindMax(int *pScore,int m,int n,int *prow,int *pcol)
{
    int i,j;
    int x=pScore[0*n+0]; /*定义变量x为第一个考生第一门分数，y为最高分*/
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(pScore[i*n+j]>x)
            {
                *prow=i;
                *pcol=j;
                x=pScore[i*n+j];
            }
        }
    }
    return x;
}
