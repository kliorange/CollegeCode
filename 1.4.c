#include<stdio.h>
int main()
{
    float a = 1.2;
    float b = 2.3;
    float c = 0;
    c = a;
    a = b;
    b = c;
    printf("%f,%f",a,b);
    return 0;
}
