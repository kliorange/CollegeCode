#include<stdio.h>
#include<math.h>
int main()
{
     printf("������a�� b�� c�� �ҿ�����������ε����");
     double a=0,b=0,c=0,P=0,sum=0;
     scanf("%lf%lf%lf",&a,&b,&c);
     P = (a+b+c)/2;
     sum = sqrt(P*(P-a)*(P-b)*(P-c));
     printf("���S3Ϊ%lf",sum);
    return 0;
}
