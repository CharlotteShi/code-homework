#include <stdio.h>
int main()
{
    int prime,count,x;
    int num=0;
    for(prime=100;prime<200;prime++)
    {
        count=0; /*count为prime除1和本身外的约数个数*/
        for(x=2;x<prime;x++)
        {
            if(prime%x==0)
                count+=1;
        }
        if(count==0)
        {
            printf("%4d",prime);
            num+=1; /*num为每一行输出的素数个数*/
            if(num%6==0)
                printf("\n");
        }
    }
    return 0;
}
