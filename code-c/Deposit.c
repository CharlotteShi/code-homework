#include  <stdio.h>
#include  <math.h>
int main()
{
    int n;                  /* 存款期变量声明 */
    float rate;        /* 存款年利率变量声明 */
    double capital;     /* 存款本金变量声明 */
    double deposit;     /* 本利之和变量声明 */
    scanf("%f,%d,%lf", &rate, &n, &capital);
    deposit = capital * pow(1 + rate, n); /* 计算存款利率之和 */
    printf("deposit=%.4f\n", deposit); /* 打印存款利率之和 */
    return 0;
}
