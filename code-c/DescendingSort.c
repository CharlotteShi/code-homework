#include <stdio.h>

#define N 31

int Input(long*pnum,char*pname[],int*pscore);
void Sort(long*pnum,char*pname[],int*pscore,int n);
void Print(long*pnum,char*pname[],int*pscore,int n);

int main()
{
   long num[N]; /*定义数组num存放学号*/
   char *name[N]={NULL}; /*定义指针数组存放指向学生姓名的指针*/
   int score[N];  /*定义数组存放分数*/
   int n;         /*实际输入人数*/
   char names[N][80];
   for(n=0;n<N;n++)
        name[n]=names[n];
   n=Input(num,name,score);
   Sort(num,name,score,n);
   Print(num,name,score,n);
   return 0;
}

/*从键盘输入某班学生（最多30人）的学号、姓名及某门课的成绩*/
int Input(long*pnum,char*pname[],int*pscore)
{
    int i=-1;
    do{
        i++;
        scanf("%ld %s %d",pnum+i,pname[i],pscore+i);

    }while(*(pscore+i)>=0 && i<30);
    return i;
}

/*将学生成绩按照从高分到低分的顺序排序（分数相同时不作交换）*/
void Sort(long*pnum,char*pname[],int*pscore,int n)
{
    int i,j;  /*计数变量*/
    long temp_num;
    char *temp_name;
    int temp_score;  /*定义中间变量*/
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(pscore+j)>*(pscore+i))
            {
                temp_score=*(pscore+j);
                *(pscore+j)=*(pscore+i);
                *(pscore+i)=temp_score;
                temp_num=*(pnum+j);
                *(pnum+j)=*(pnum+i);
                *(pnum+i)=temp_num;
                temp_name=pname[j];
                pname[j]=pname[i];
                pname[i]=temp_name;
            }
        }
    }
}

/*打印排好序的学生成绩表*/
void Print(long*pnum,char*pname[],int*pscore,int n)
{
    printf("Pos\tNum\tName\tGrade\n");
    int i;
    for(i=0;i<n;i++)
    {
       printf("%d\t%ld\t%s\t%d\n",i+1,*(pnum+i),pname[i],*(pscore+i));
    }
}
