#include<stdio.h>
#include<math.h>
int main()
{
     printf("请输入a边 b边 c边 我可以求出三角形的面积");
     double a=0,b=0,c=0,P=0,sum=0;
     scanf("%lf%lf%lf",&a,&b,&c);
     P = (a+b+c)/2;
     sum = sqrt(P*(P-a)*(P-b)*(P-c));
     printf("面积S3为%lf",sum);
    return 0;
}
