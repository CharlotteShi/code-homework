#include <stdio.h>
#include <stdlib.h>

int FindMax(int *pScore,int m,int n,int *prow,int *pcol);

int main()
{
    int *score=NULL;   /*ָ���һ��������һ�ſεĿ��Գɼ�*/
    int m,n,ScoreMax; /*�������m����������n���Կ�Ŀ��ScoreMax��߷���*/
    int row=0,col=0; /*�������row��߷������У�col��߷�������*/
    long *Number=NULL; /*ָ���һ��������ѧ��*/
    char **Name=NULL,**Course=NULL; /*ָ���һ�����������ĵ�ַ��ָ���һ�ſ�Ŀ�ĵ�ַ*/
    int i,j;   /*�����������*/
    scanf("%d",&m);  /*���뿼������*/
    scanf("%d",&n);  /*���뿼�Կ�Ŀ*/
    getchar();
    Number=(long*)malloc(m*sizeof(long)); /*�����ſ��ŵ��ڴ�*/
    Name=(char**)malloc(m*sizeof(char*)); /*�������������ڴ�*/
    score=(int*)calloc(m*n,sizeof(int));  /*�����ŷ������ڴ�*/
    Course=(char**)malloc(n*sizeof(char*)); /*�����ſ�Ŀ���ڴ�*/
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
���ܣ��ҳ���߷�
������ָ�� *pScoreָ���һ��������һ�ſεĿ��Գɼ�����ָ�룩��
    m����������n���Կ�Ŀ��
    ָ�� *prow ���ڷ�����߷����ڵ��У�
    ָ�� *pcol ���ڷ�����߷����ڵ���
����ֵ��������߷�
*/
int FindMax(int *pScore,int m,int n,int *prow,int *pcol)
{
    int i,j;
    int x=pScore[0*n+0]; /*�������xΪ��һ��������һ�ŷ�����yΪ��߷�*/
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
