/*
kliorange
2015.11.28
ʵ���ģ�
�ɼ������Σ��ṹ�����飩 ĳ����ĩ���Կ�ĿΪ
��ѧ��MT����Ӣ�EN�� ������PH��������� ������ 30 �˲μӿ� �ԣ�
ѧ�ſ���������� ��Ŵ��档���Ժ�Ҫ ��
��1������ÿ��ѧ���� �ֺܷ�ƽ���֣�
��2�����ֳܷɼ��ɸ� �����ų��ɼ������Σ�
��3����ӡ�����α� ����ڰ���ѧ����š� ���Ʒ������ֺܷ�ƽ���֣�
��4����������һ��ѧ �ţ��ܹ����ҳ���ѧ�� �ڰ༶�е��������� ���Է�����
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
//��ӡ�����α� ����ڰ���ѧ����š� ���Ʒ������ֺܷ�ƽ����
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
//��������һ��ѧ�ţ��ܹ����ҳ���ѧ���ڰ༶�е��������俼�Է�����
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
    ����ÿ��ѧ���� �ֺܷ�ƽ���֣�
    ���ֳܷɼ��ɸߵ����ų��ɼ������Σ�
    ��ӡ�����α� ����ڰ���ѧ����š����Ʒ������ֺܷ�ƽ���֣�
    ��������һ��ѧ�ţ��ܹ����ҳ���ѧ���ڰ༶�е��������俼�Է�����
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

