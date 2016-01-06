/*
kliorange
2015.11.28
实验四：
成绩排名次（结构体数组） 某班期末考试科目为
数学（MT）、英语（EN） 和物理（PH），有最多 不超过 30 人参加考 试，
学号可以用输入的 序号代替。考试后要 求：
（1）计算每个学生的 总分和平均分；
（2）按总分成绩由高 到低排出成绩的名次；
（3）打印出名次表， 表格内包括学生编号、 各科分数、总分和平均分；
（4）任意输入一个学 号，能够查找出该学生 在班级中的排名及其 考试分数。
*/

#include<stdio.h>
#include<string.h>
struct data
{
    int id;
    double MT,EN,PH;
    double sum,ave;
};

//Rank the score from high to low or rank the score from low to high
//a is the number of students. b is rank from high to low or from low to high
void rank(struct data score[],int a,int b)
{
    int i=0 , j=0;
    double temp=0;
    for( i=0 ; i<a-1 ; i++ )
    {
        for( j=i+1 ; j<a ; j++)
        {
            if(b==1&&score[i].sum<score[j].sum)
            {
                score[31]=score[i];
                score[i]=score[j];
                score[j]=score[31];
            }
            else if(b==0&&score[i].sum>score[j].sum)
            {
                score[31]=score[i];
                score[i]=score[j];
                score[j]=score[31];
            }
        }
    }
    return ;
}




//Print the list
//打印出名次表， 表格内包括学生编号、 各科分数、总分和平均分
void printflist(struct data score[],int a)

{
    int i=0;
for( i=0 ; i<a ; i++ )

    {
        printf("Student ID : %d\n"
               "The MT EN PH score is : %-4.2lf %-4.2lf %-4.2lf\n"
               "And the sum is : %-4.2lf\n"
               "The average score is : %-4.2lf\n\n",
               score[i].id,score[i].MT,score[i].EN,
score[i].PH,score[i].sum,score[i].ave);
    }
    return ;
}

//Search the students
//任意输入一个学号，能够查找出该学生在班级中的排名及其考试分数。
void searchid(struct data score[],int a)
{
    int i = 0 ;
    printf("Please input the students ID : ");
    scanf("%d",&i);
    for( i=0 ; i<a ; i++ )
        if(score[i].id==i)break;
    printf("Student ID : %d\n"
               "The MT EN PH score is : %-4.2lf %-4.2lf %-4.2lf\n"
               "And the sum is : %-4.2lf\n"
               "The average score is : %-4.2lf\n\n",
               score[i].id,score[i].MT,score[i].EN,score[i].PH,
score[i].sum,score[i].ave);
    return ;
}

int main()
{
    int a=0,b=0,i=0;
    /*
    计算每个学生的 总分和平均分；
    按总分成绩由高到低排出成绩的名次；
    打印出名次表， 表格内包括学生编号、各科分数、总分和平均分；
    任意输入一个学号，能够查找出该学生在班级中的排名及其考试分数。
    */
    struct data score[31];
    printf("How many students you will input?");
    scanf("%d",&a);
    for( i=0 ; i<a ; i++ )
    {
        printf("Please input the data about students id MT EN PH ");
        scanf("%d %lf %lf %lf",score[i].id,score[i].MT,score[i].EN,score[i].PH);
    }

printf("\nWhich rank you want to see? "
"From high to low '1' From low to high '0' ");
    scanf("%d",&b);

    rank(score,a,b);
    printflist(score,b);

    printf("\nYou can search the students information with ID :");
    searchid(score,b);

    return 0;
}

