/*
kliorange
2015.11.22
ʵ����ϰ 1��ѭ���ṹ��̣�������Ϸ��
������ɼ��������һ�� 1��100 ֮�����
���˲£�����˲¶��ˣ��������Ϸ��
������Ļ������˲��˶��ٴβŲ¶Դ�����
�Դ�����ӳ�����ߡ��¡���ˮƽ��
��������������ʾ�����������µ�����̫����̫С�������Բ� 10 �Σ�
������� 10 ����δ���еĻ���������Ϸ��
������ɼ�������롱 һ�� 1��100 ֮��������˲£�
����˲¶��ˣ�����Ļ������˲��˶��ٴβŲ¶Դ�����
�Դ�����ӳ������ ���¡���ˮƽ��������� Ϸ��
�������������� ʾ�����������µ����� ̫����̫С��
�����Բ� 10 �Σ�
������� 10 ����δ���еĻ��� ��ֹͣ���β�����
Ȼ�� ��������һ������
ÿ�����г�����Է����¶������ֱ����������ֹͣʱ�Ž�����
*/
#include<time.h>
#include<stdio.h>
int main()
{
    int sum=0;
    int i=0,guest=0,judge=0;
    srand( (unsigned int)( time(NULL) ) );
    while(1)
    {
        judge=rand();
        judge%=100+1;
        sum=1;
        printf("Game begin now!\n"
"If you want quit the game input ��-1��\n");
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
