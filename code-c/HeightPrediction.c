#include <stdio.h>
int main()
{
    int myHight,faHight,moHight; /*��������ҵ���ߣ�������ߣ�ĸ�����*/
    char sex,diet,sports,replay; /*��������Ա���ʳ���˶�����������*/
    do{
        printf("Input your sex:\n");
        scanf(" %c",&sex); /*��ȡ�Ա�*/
        printf("Input your father's hight:\n");
        scanf("%d",&faHight); /*��ȡ�������*/
        printf("Input your mother's hight:\n");
        scanf("%d",&moHight); /*��ȡĸ�����*/
        if(sex=='m' || sex=='M')
            myHight=(faHight+moHight)*0.54;
        else if(sex=='f' || sex=='F')
            myHight=(faHight*0.923+moHight)/2; /*�����Ա����*/
        printf("Do you like sports?\n");
        scanf(" %c",&sports); /*��ȡ�˶���Ϣ*/
        printf("Do you like diet?\n");
        scanf(" %c",&diet); /*��ȡ��ʳ��Ϣ*/
        if(diet=='y' || diet=='Y')
            myHight=myHight*(1+0.015); /*������ʳ����*/
        if(sports=='y'||sports=='Y')
            myHight=myHight*(1+0.02); /*�����˶�����*/
        printf("Your hight is:%d\n",myHight);
        printf("Do you want to continue(y(Y)|n(N))?\n");
        scanf(" %c",&replay); /*�ж��Ƿ����*/
    }while(replay=='y'||replay=='Y');
    if(replay=='n'||replay=='N')
        printf("Over!"); /*Ԥ�����*/
    return 0;
}
