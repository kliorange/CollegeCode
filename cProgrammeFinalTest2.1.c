/*
kliorange
2015.11.28
实验三：
1.学生成绩统计（一维数组）从键盘输入一个班（全班最多不超过 30人）学生某门课的成绩，当输入成绩为负值时，输入结束，分别实现下列功能：
（1）统计不及格人数并打印不及格学生名单；
（2）统计成绩在全班平均分及平均分之上的学生人数，并打印这些学生的名单；
（3）以直方图方式统 计各分数段的学生人 数及所占的百分比。形 式如下：


分段	人数	图形
<60   3（10%）***
60‐69	8（…） ********
70‐79	7（…） *******
80‐89	8（…） ********
>=90	4（…） ****
*/

#include<stdio.h>
//Printf the students under or beyond a score
void line(double n,double score[],char name[][32],int a)
{
    int i=0;
    for( i=0 ; i<30 ; i++ )
    {
        if(score[i]<0)break;
        else if(a==0&&score[i]<n)
            printf("%s\n",name[i]);
        else if(a==1&&score[i]>n)
            printf("%s\n",name[i]);
    }
    return ;
}

//Put *
void putStar(int a)
{
    int i=0;
    for( i = 0 ; i<a ; i++ )printf("*");
    printf("\n");
    return ;
}
//Judge the the number who in the a to b
int judgeNum(double score[],int a,int b)
{
    int num=0,i=0;
    double percent=0;
    for( i=0 ; i<30 ; i++ )
    {
        if(score[i]<0)break;
        else if(score[i]>a&&score[i]<b)num++;
    }
    return num;
}

//Caculate the percent
void printfPercent(double score[],int num)
{
    double sum=0;
    int i=0;
    for( i=0 ; i<30 ; i++ )
    {
        if(score[i]<0)break;
        sum++;
    }
    printf("  %-4.2lf%%  ",num/sum*100);
    return ;
}

//Caculate the number of the students who fail the exam
int failNum(double score[],char name[][32])
{
    int i=0;
    int num=0;
    for( i=0 ; i<30 ; i++ )
    {
        if(score[i]<0)break;
        else if(score[i]<60)
            num++;
    }
    return num;
}

//Caculate the average
double aveScore(double score[])
{
    int i=0,num=0;
    double ave=0;
    for( i=0 ; i<30 ; i++ )
    {
        if(score[i]<0)break;
        else
        {
            ave+=score[i];
            num++;
        }
    }
    return ave/num;
}

//Caculate the number of the students who before the average score
//And printf the students who beyond the average score
int aveNum(double score[],char name[][32])
{
    int num=0,i=0;
    double ave=0;
    for( i=0 ; i<30 ; i++ )
        {
            if(score[i]<0)break;
            else ave+=score[i];
        }
        ave/=i;
        for( i=0 ; i<30 ; i++ )
        {
            if(score[i]<0)break;
            else if(score[i]>ave)
                num++;
        }
    return num;
}

int main()
{
    double score[30];
    char name[30][32];
    int i=0;
	void line(double n,double score[],char name[][32],int a);
	void putStar(int a);
	int judgeNum(double score[],int a,int b);
	void printPercent(double score[],int num);
	int failNum(double score[],char name[][32]);
	double aveScore(double score[]);
	int aveNum(double score[],char name[][32]);

    printf("Please input the score：");
    while(scanf("%lf",&score[i]),score[i]>0)
    {
        printf("\nPlease input the students name：");
        scanf("%s",&name[i]);

        printf("\nPlease input the score：");
        i++;
    }
    printf("\nThis exam have %d student%c fail in total\n",
           failNum(score,name),failNum(score,name)>0?'s':' ');
    line(60,score,name,0);//Find out and printf the students who fail the exam

    printf("\nThis exam have %d student%c beyond the average score in total\n",
        aveNum(score,name),aveNum(score,name)>0?'s':' ');
    line(aveScore(score),score,name,1);//Find out and printf the students who beyond the average

    printf("\n分段    人数    图形    \n");
    printf("0 -60    %d    ",judgeNum(score,0,60));
    printfPercent(score,judgeNum(score,0,60));
    putStar(judgeNum(score,0,60));

    printf("60-69    %d    ",judgeNum(score,60,69));
    printfPercent(score,judgeNum(score,60,69));
    putStar(judgeNum(score,60,69));

    printf("70-79    %d    ",judgeNum(score,70,79));
    printfPercent(score,judgeNum(score,70,79));
    putStar(judgeNum(score,70,79));

    printf("80-89    %d    ",judgeNum(score,80,89));
    printfPercent(score,judgeNum(score,80,89));
    putStar(judgeNum(score,80,89));

    printf("90-100   %d    ",judgeNum(score,90,100));
    printfPercent(score,judgeNum(score,90,100));
    putStar(judgeNum(score,90,100));

    return 0;
}

/*
Please input the score：100

Please input the students name：jack

Please input the score：98

Please input the students name：daniel

Please input the score：80

Please input the students name：tom

Please input the score：45

Please input the students name：kaka

Please input the score：95

Please input the students name：lisa

Please input the score：12

Please input the students name：lexi

Please input the score：56

Please input the students name：kliorange

Please input the score：-9

This exam have 3 students fail in total
kaka
lexi
kliorange

This exam have 4 students beyond the average score in total
jack
daniel
tom
lisa

分段    人数    图形
0 -60    3      42.86%  ***
60-69    0      0.00%
70-79    0      0.00%
80-89    0      0.00%
90-100   2      28.57%  **

Process returned 0 (0x0)   execution time : 36.174 s
Press any key to continue.
*/
