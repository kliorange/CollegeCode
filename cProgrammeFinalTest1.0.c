/*
kliorange
2015.11.22
cProgrammeFinalTest1.0：循环结构编程（猜数游戏）
编程先由计算机“想一个 1～100 之间的数
请人猜，如果人猜对了，则结束游戏，
并在屏幕上输出人猜了多少次才猜对此数，
以此来反映猜数者“猜”的水平；
否则计算机给出提示，告诉人所猜的数是太大还是太小，最多可以猜 10 次，
如果猜了 10 次仍未猜中的话，结束游戏。
编程先由计算机“想” 一个 1～100 之间的数请人猜，
如果人猜对了，在屏幕上输出人猜了多少次才猜对此数，
以此来反映猜数者 “猜”的水平，则结束游 戏；
否则计算机给出提 示，告诉人所猜的数是 太大还是太小，
最多可以猜 10 次，
如果猜了 10 次仍未猜中的话， 则停止本次猜数，
然后 继续猜下一个数。
每次运行程序可以反复猜多个数，直到操作者想停止时才结束。
*/
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int sum=0;
    int i=0,guest=0,judge=0;
    //i For loop control variable.
    srand( (unsigned int)( time(NULL) ) );
    while(1)
    {
        judge=rand();
        judge%=100+1;
        sum=1;
        printf("Game begin now!\n"
		"If you want quit the game input ‘-1’\n");
        for(i=1; i<=10; i++)
        {
			do
			{
				if(flag!=0)
					printf("Please input the guest number in order\n");
				scanf("%d",&guest);
				if(guest==-1)
					return 0;
				flag++;
			}while(guest<0||guest>100);

            if(guest==judge)
            {
                printf("You guest the number with %d try",sum);
                return 0;
            }
            else if(guest>judge)printf("the number is smaller than you think!");
            else printf("the number is bigger than you think!");
            printf("you only have %d chance\n",10-sum);
            sum++;
        }
    }
    return 0;
}
