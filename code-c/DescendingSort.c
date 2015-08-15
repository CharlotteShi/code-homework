#include <stdio.h>

#define N 31

int Input(long*pnum,char*pname[],int*pscore);
void Sort(long*pnum,char*pname[],int*pscore,int n);
void Print(long*pnum,char*pname[],int*pscore,int n);

int main()
{
   long num[N]; /*��������num���ѧ��*/
   char *name[N]={NULL}; /*����ָ��������ָ��ѧ��������ָ��*/
   int score[N];  /*���������ŷ���*/
   int n;         /*ʵ����������*/
   char names[N][80];
   for(n=0;n<N;n++)
        name[n]=names[n];
   n=Input(num,name,score);
   Sort(num,name,score,n);
   Print(num,name,score,n);
   return 0;
}

/*�Ӽ�������ĳ��ѧ�������30�ˣ���ѧ�š�������ĳ�ſεĳɼ�*/
int Input(long*pnum,char*pname[],int*pscore)
{
    int i=-1;
    do{
        i++;
        scanf("%ld %s %d",pnum+i,pname[i],pscore+i);

    }while(*(pscore+i)>=0 && i<30);
    return i;
}

/*��ѧ���ɼ����մӸ߷ֵ��ͷֵ�˳�����򣨷�����ͬʱ����������*/
void Sort(long*pnum,char*pname[],int*pscore,int n)
{
    int i,j;  /*��������*/
    long temp_num;
    char *temp_name;
    int temp_score;  /*�����м����*/
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

/*��ӡ�ź����ѧ���ɼ���*/
void Print(long*pnum,char*pname[],int*pscore,int n)
{
    printf("Pos\tNum\tName\tGrade\n");
    int i;
    for(i=0;i<n;i++)
    {
       printf("%d\t%ld\t%s\t%d\n",i+1,*(pnum+i),pname[i],*(pscore+i));
    }
}
