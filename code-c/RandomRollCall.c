#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 31

/*定义结构体*/
typedef struct student
{
    long studentID;
    char studentName[10];
}STUDENT;

void ReadFile(struct student *p,int n);
void RollCall(struct student *p,int n,int times[N]);

int main()
{
    int times[N]={0};      /*定义数组存放每位同学被点到的次数*/
    STUDENT *stu=NULL;     /*定义指针指向学号和姓名*/
    stu=(struct student*)malloc(N*sizeof(struct student));  /*申请内存*/
    ReadFile(stu,N);
    srand(time(NULL));
    RollCall(stu,N,times);
    free(stu);                                             /*释放内存*/
    return 0;
}


/*
函数功能：从文件中读取学生信息
函数参数：p 指向存放结构体变量的第一个存储单元，n班级人数
函数返回值：无
*/
void ReadFile(struct student *p,int n)
{
    int i;
    FILE *fp;
    if((fp=fopen("..\\student.txt","r"))==NULL)
    {
        printf("Fail to open student.txt!\n");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%ld",&p[i].studentID);
        fscanf(fp,"%s",p[i].studentName);
    }
    fclose(fp);
}


/*
函数功能：随机抽取学生并输出结果
参数：p 指向存放结构体变量的第一个存储单元，n班级人数，times为数组存放被点次数
返回值：无
*/
void RollCall(struct student *p,int n,int times[N])
{
    int m;
    char answer;
    do{
        m=rand()%N;
        printf("%ld\t%s\n",p[m].studentID,p[m].studentName);
        times[m]++;
        printf("The student has been called %d times!\n",times[m]);
        printf("Do you want to continue?(input n or y)\n");
        scanf(" %c",&answer);
    }while(answer=='y');
    if(answer=='n')
        exit(0);
}
