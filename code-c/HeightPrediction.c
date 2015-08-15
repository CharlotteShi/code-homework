#include <stdio.h>
int main()
{
    int myHight,faHight,moHight; /*定义变量我的身高，父亲身高，母亲身高*/
    char sex,diet,sports,replay; /*定义变量性别，饮食，运动，继续测试*/
    do{
        printf("Input your sex:\n");
        scanf(" %c",&sex); /*获取性别*/
        printf("Input your father's hight:\n");
        scanf("%d",&faHight); /*获取父亲身高*/
        printf("Input your mother's hight:\n");
        scanf("%d",&moHight); /*获取母亲身高*/
        if(sex=='m' || sex=='M')
            myHight=(faHight+moHight)*0.54;
        else if(sex=='f' || sex=='F')
            myHight=(faHight*0.923+moHight)/2; /*根据性别计算*/
        printf("Do you like sports?\n");
        scanf(" %c",&sports); /*获取运动信息*/
        printf("Do you like diet?\n");
        scanf(" %c",&diet); /*获取饮食信息*/
        if(diet=='y' || diet=='Y')
            myHight=myHight*(1+0.015); /*根据饮食计算*/
        if(sports=='y'||sports=='Y')
            myHight=myHight*(1+0.02); /*根据运动计算*/
        printf("Your hight is:%d\n",myHight);
        printf("Do you want to continue(y(Y)|n(N))?\n");
        scanf(" %c",&replay); /*判断是否继续*/
    }while(replay=='y'||replay=='Y');
    if(replay=='n'||replay=='N')
        printf("Over!"); /*预测结束*/
    return 0;
}
