#include  <stdio.h>
#include  <math.h>
int main()
{
    int n;                  /* ����ڱ������� */
    float rate;        /* ��������ʱ������� */
    double capital;     /* ����������� */
    double deposit;     /* ����֮�ͱ������� */
    scanf("%f,%d,%lf", &rate, &n, &capital);
    deposit = capital * pow(1 + rate, n); /* ����������֮�� */
    printf("deposit=%.4f\n", deposit); /* ��ӡ�������֮�� */
    return 0;
}
