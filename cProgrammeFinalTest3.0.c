/*
kliorange
2015.11.28
实践练习 4：
每位学生信息包括：学号、
姓名、性别、学院、10 门
成绩。共有不超过 100 位同学的信息存放在 ASCII 文件StudentInfo.txt 中；
不超过10 个学院的信息存放在
CodeInfo.txt 中，性别代码
存放在 SexInfo.txt 中，均为
代码和其对应的名称。

要求：
1.定义至少包含以上学生信息和学院代码的 结构体类型和指针（或 数组）变量。
2.函数实现从文件中输入信息到定义的数据中。
3.函数实现排序(1)：学生 平均成绩的降序排序， 并输出所有信息到显示屏。
4.函数实现排序（2）：学 生姓名的升序排序，并 输出所有信息到显示器。
5.函数实现查询（1）：根据学号查询学生信息， 并输出该生信息，并输出所有信息到显示器。
6.函数实现查询（2）：根据姓名查询学生信息， 并输出该姓名的学生
*/

//Need to change the information from figure to character
#include<stdio.h>
#include<string.h>

struct stuData
{
	char id[7];
	char name[32];
	//'1' mean male,'0' mean female
	char sex[5];
	char academy[32];
	double score[10];
	double ave;
};

//The function about menu
int menu() //主菜单
{
	int a = 0;
	int flag=0;
	printf("\n\t\t\t菜单\n");
	printf("\t\t\t#*****************************************#\n");
	printf("\t\t\t# 1将学生信息按名字从大到小排序并输出     #\n");
	printf("\t\t\t# 2将学生信息按平均成绩从小到大排序并输出 #\n");
	printf("\t\t\t# 3查找学生资料                           #\n");
	printf("\t\t\t# 4---关闭                                #\n");
	printf("\t\t\t#*****************************************#\n");
	printf("\t\t\t请选择(1-4) =:");
	do
	{
		if(flag!=0)
			printf("Please input the number in order\n!");
		scanf("%d", &a);
		flag++;
	}while(a>0&&a<5);

	return a;
}

int main()
{
	int i = 0, j = 0, select = 0;
	struct stuData STU[100];
	FILE *fp;
	int menu();
	void sortOutput(struct stuData STU[], int a);
	void searchInformation(struct stuData STU[]);
	int changeSexAndAcademy(struct stuData *STU);

	if ((fp = fopen("StudentInfo.txt", "r")) == NULL)
	{
		printf("Can't open the file");
		return -1;
	}
	//Read the students' information
	for (i = 0; i<100; i++)
	{
		fscanf(fp, "%s %s %s %s",
			&STU[i].id, &STU[i].name, &STU[i].sex, &STU[i].academy);
		for (j = 0; j<10; j++)
			fscanf(fp, "%lf", &STU[i].score[j]);
	}
	fclose(fp);

	//Calculate the average score
	for (i = 0; i<100; i++)
	{
		STU[i].ave = 0;
		for (j = 0; j<10; j++)
		{
			STU[i].ave += (STU[i].score[j]);
		}
		STU[i].ave /= 10;
	}
	//Change the number to the acadmy name
	changeSexAndAcademy(STU);
	while (1)
	{
		select = menu();
		switch (select)
		{
		case 1:sortOutput(STU, 0);
			break;

		case 2:sortOutput(STU, 1);
			break;

		case 3:searchInformation(STU);
			break;

		case 4: return 0;
		}

	}
	return 0;
}

//The function to search the information by student's ID
//and output the imfomation to the screen
//DONE
void searchInformation(struct stuData STU[])
{
	int i = 0, j = 0, a = 0;
	int flag=0;
	char search[99];
	system("cls"); //清屏
	printf("\n\t\t\t查找学生信息\n");
	printf("\t\t\t#***********************#\n");
	printf("\t\t\t# 1通过名字查找学生     #\n");
	printf("\t\t\t# 2通过学号查找学生     #\n");
	printf("\t\t\t# 3---关闭              #\n");
	printf("\t\t\t#***********************#\n");
	printf("\t\t\t请选择(1-3) =:");
	do
	{
		if(flag!=0)
			printf("Please input the number in order\n!");
		scanf("%d", &a);
		flag++;
	}while(search<4&&search>0);

	if (a == 1)
	{
		printf("Please input the name which you want search.");
		scanf("%s", search);

		for (i = 0; i<100; i++)
		{
			if (strcmp(STU[i].name, search) == 0)
			{
				printf("\t\t\tThe student's ID:%s\n"
					"\t\t\tThe student's NAME:%s\n"
					"\t\t\tThe student's SEX:%s\n"
					"\t\t\tThe student's Average Score:%.2lf\n"
					"\t\t\tThe student's Academy is %s\n",
					STU[i].id, STU[i].name, STU[i].sex, STU[i].ave, STU[i].academy);
				for (j = 0; j<10; j++)
				{
					if (j == 0)
						printf("\t\t\tThe student's %dst SCORE:%.0lf\n",
							j + 1, STU[i].score[j]);
					else if (j == 1)
						printf("\t\t\tThe student's %dnd SCORE:%.0lf\n",
							j + 1, STU[i].score[j]);
					else if (j == 2)
						printf("\t\t\tThe student's %drd SCORE:%.0lf\n",
							j + 1, STU[i].score[j]);
					else if (j>2)
						printf("\t\t\tThe student's %dth SCORE:%.0lf\n",
							j + 1, (STU[i].score[j]));
				}
				return;
			}
		}
		printf("\t\t\tCan't find %s\n", search);
	}
	//The function to search the information by student's ID
	//and output the imfomation to the screen
	else if (a == 2)
	{
		printf("\t\t\tPlease input the id which you want search.");
		scanf("%s", search);

		for (i = 0; i<100; i++)
		{
			if (strcmp(STU[i].id, search) == 0)
			{
				printf("\t\t\tThe student's ID:%s\n"
					"\t\t\tThe student's NAME:%s\n"
					"\t\t\tThe student's SEX:%s\n"
					"\t\t\tThe student's Average Score:%.2lf\n"
					"\t\t\tThe student's Academy is %s\n",
					STU[i].id, STU[i].name, STU[i].sex,
					STU[i].ave, STU[i].academy);
				for (j = 0; j<10; j++)
				{
					if (j == 0)
						printf("\t\t\tThe student's %dst SCORE:%.0lf\n",
							j + 1, (STU[i].score[j]));
					else if (j == 1)
						printf("\t\t\tThe student's %dnd SCORE:%.0lf\n",
							j + 1, (STU[i].score[j]));
					else if (j == 2)
						printf("\t\t\tThe student's %drd SCORE:%.0lf\n",
							j + 1, (STU[i].score[j]));
					else if (j>2)
						printf("\t\t\tThe student's %dth SCORE:%.0lf\n",
							j + 1, (STU[i].score[j]));
				}
				return;
			}
		}
		printf("\t\t\tCan't find %s\n", search);
		return;
	}
	return;
}


//The function to sort the name from high to low
//And sort the average score from low to high
//A==0 for highname A!=0 for downAve
//and output the imfomation to the screen
//DONE

void sortOutput(struct stuData STU[], int a)
{
	//Use the insert sort
	int i = 0, j = 0, k = 0, z = 0;
	char key1[32], key2[32], key3[32], key5[32];
	double key4 = 0, key6[10] = { 0 };

	if (a == 0)
	{
		for (i = 1; i<100; i++)
		{
			strcpy(key1, STU[i].name);
			strcpy(key2, STU[i].id);
			strcpy(key3, STU[i].sex);
			key4 = STU[i].ave;
			strcpy(key5, STU[i].academy);
			for (z = 0; z<10; z++)
				key6[z] = STU[i].score[z];

			for (j = 0; j<i; j++)
			{
				if (strcmp(STU[j].name, key1)<0)
				{
					//Make the data move backward
					for (k = i - 1; k >= j; k--)
					{
						strcpy(STU[k + 1].name, STU[k].name);
						strcpy(STU[k + 1].id, STU[k].id);
						strcpy(STU[k + 1].sex, STU[k].sex);
						STU[k + 1].ave = STU[k].ave;
						strcpy(STU[k + 1].academy, STU[k].academy);
						for (z = 0; z<10; z++)
							STU[k + 1].score[z] = STU[k].score[z];
					}
					//Insert the data

					strcpy(STU[j].name, key1);
					strcpy(STU[j].id, key2);
					strcpy(STU[j].sex, key3);
					STU[j].ave = key4;
					strcpy(STU[j].academy, key5);
					for (z = 0; z<10; z++)
						STU[j].score[z] = key6[z];
					break;
				}
			}
		}
	}
	else
	{
		for (i = 1; i<100; i++)
		{
			strcpy(key1, STU[i].name);
			strcpy(key2, STU[i].id);
			strcpy(key3, STU[i].sex);
			key4 = STU[i].ave;
			strcpy(key5, STU[i].academy);
			for (z = 0; z<10; z++)
				key6[z] = STU[i].score[z];

			for (j = 0; j<i; j++)
			{
				if (STU[j].ave>key4)
				{
					//Make the data move backward
					for (k = i - 1; k >= j; k--)
					{
						strcpy(STU[k + 1].name, STU[k].name);
						strcpy(STU[k + 1].id, STU[k].id);
						strcpy(STU[k + 1].sex, STU[k].sex);
						STU[k + 1].ave = STU[k].ave;
						strcpy(STU[k + 1].academy, STU[k].academy);
						for (z = 0; z<10; z++)
							STU[k + 1].score[z] = STU[k].score[z];
					}
					//Insert the data

					strcpy(STU[j].name, key1);
					strcpy(STU[j].id, key2);
					strcpy(STU[j].sex, key3);
					STU[j].ave = key4;
					strcpy(STU[j].academy, key5);
					for (z = 0; z<10; z++)
						STU[j].score[z] = key6[z];
					break;
				}
			}
		}
	}

	//Output the information
	for (i = 0; i<100; i++)
	{
		printf("\t\t\tThe student's ID:%s\n"
			"\t\t\tThe student's NAME:%s\n"
			"\t\t\tThe student's SEX:%s\n"
			"\t\t\tThe student's Average Score:%.2lf\n"
			"\t\t\tThe student's Academy is %s\n",
			STU[i].id, STU[i].name, STU[i].sex, STU[i].ave, STU[i].academy);
		for (j = 0; j<10; j++)
		{
			if (j == 0)
				printf("\t\t\tThe student's %dst SCORE:%.0lf\n",
					j + 1, (STU[i].score[j]));
			else if (j == 1)
				printf("\t\t\tThe student's %dnd SCORE:%.0lf\n",
					j + 1, (STU[i].score[j]));
			else if (j == 2)
				printf("\t\t\tThe student's %drd SCORE:%.0lf\n",
					j + 1, (STU[i].score[j]));
			else if (j>2)
				printf("\t\t\tThe student's %dth SCORE:%.0lf\n",
					j + 1, (STU[i].score[j]));
		}
	}
	printf("\n");
	return;
}

//Change the figure to characters
//DONE
int changeSexAndAcademy(struct stuData *STU)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i<100; i++)
	{
		if (*STU[i].sex == '1')
			strcpy(STU[i].sex, "男");
		else if (*STU[i].sex == '0')
			strcpy(STU[i].sex, "女");
		switch (*STU[i].academy)
		{
			case '0':
				strcpy(STU[i].academy, "信息学院");
				break;
			case '1':
				strcpy(STU[i].academy, "计算机学院");
				break;
			case '2':
				strcpy(STU[i].academy, "文法学院");
				break;
			case '3':
				strcpy(STU[i].academy, "外国语学院");
				break;
			case '4':
				strcpy(STU[i].academy, "数理学院");
				break;
			case '5':
				strcpy(STU[i].academy, "会金学院");
				break;
			case '6':
				strcpy(STU[i].academy, "化工学院");
				break;
			case '7':
				strcpy(STU[i].academy, "商学院");
				break;
			case '8':
				strcpy(STU[i].academy, "航空学院");
				break;
			case '9':
				strcpy(STU[i].academy, "艺术学院");
				break;
		}
	}
	return 0;
}
