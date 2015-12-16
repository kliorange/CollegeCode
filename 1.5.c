#include<stdio.h>
int main()
{
    printf("请输入圆的直径，我会计算面积^_^");
    double D=0,sum=0;
    scanf("%lf",&D);
    sum = (D/2)*(D/2)*3.14;
    printf("面积S1为%lf",sum);
    return 0;
}
