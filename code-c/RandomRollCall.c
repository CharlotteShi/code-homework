#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 31

/*����ṹ��*/
typedef struct student
{
    long studentID;
    char studentName[10];
}STUDENT;

void ReadFile(struct student *p,int n);
void RollCall(struct student *p,int n,int times[N]);

int main()
{
    int times[N]={0};      /*����������ÿλͬѧ���㵽�Ĵ���*/
    STUDENT *stu=NULL;     /*����ָ��ָ��ѧ�ź�����*/
    stu=(struct student*)malloc(N*sizeof(struct student));  /*�����ڴ�*/
    ReadFile(stu,N);
    srand(time(NULL));
    RollCall(stu,N,times);
    free(stu);                                             /*�ͷ��ڴ�*/
    return 0;
}


/*
�������ܣ����ļ��ж�ȡѧ����Ϣ
����������p ָ���Žṹ������ĵ�һ���洢��Ԫ��n�༶����
��������ֵ����
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
�������ܣ������ȡѧ����������
������p ָ���Žṹ������ĵ�һ���洢��Ԫ��n�༶������timesΪ�����ű������
����ֵ����
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
