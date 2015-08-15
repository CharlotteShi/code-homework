#include <stdio.h>
#define Student 40
#define Counter 11

int main()
{
    int score[Student]; /*定义数组存放每个学生打的分数*/
    int count[Counter]={0}; /*定义数组存放计数变量记录每个分数等级的人数*/
    int n;  /*打分人数*/
    int i,j; /*计数变量*/
    scanf("%d",&n); /*读取打分人数*/
    /*将分数存入数组中*/
    for(i=0;i<n;i++)
    {
        scanf("%d",&score[i]);
    }
    /*匹配找出各个分数的人数并存入数组中*/
    for(i=0;i<n;i++)
    {
        switch(score[i])
        {
            case 1 :count[1]+=1;
                break;
            case 2 :count[2]+=1;
                break;
            case 3 :count[3]+=1;
                break;
            case 4 :count[4]+=1;
                break;
            case 5 :count[5]+=1;
                break;
            case 6 :count[6]+=1;
                break;
            case 7 :count[7]+=1;
                break;
            case 8 :count[8]+=1;
                break;
            case 9 :count[9]+=1;
                break;
            case 10 :count[10]+=1;
                break;
        }
    }
    /*打印结果*/
    printf("Grade\tCount\tHistogram\n");
    for(i=1;i<=10;i++)
    {
        printf("%d\t%d\t",i,count[i]);
        if(count[i]>0)
        {
            for(j=1;j<=count[i];j++)
            {
                printf("%c",'*');
            }
            printf("\n");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}
