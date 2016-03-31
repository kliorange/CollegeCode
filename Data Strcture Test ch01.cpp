/*
	kliorange
	2016.03.31
	Test 1:
	���������������������ͷ��㣩�Ļ���������
	�����������롢ɾ�������ҡ������
	��������������������������������Ϊ�ձ�
	������ĳ��ȡ���ȡĳλ�ý������ݡ�������㡣
	���μ��̲�19ҳ��
*/
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct
{
	char no[10];
	char name[10];
	int score;
}ElemType;      //ѧ����Ϣ

typedef struct LNode
{
	ElemType data;
	struct  LNode *next;
}LNode,*LinkList;

//Initialize the LinkList
Status InitList(LinkList &L)
{
	//Build a Linear List 
	L=( (LinkList)malloc(sizeof(LNode) ) );
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;
}

//Delete a elememnt
void LiskDelete(LinkList &L,int i,ElemType &e )
{

}

//Output a element
void OutputList( LinkList L )
{

}



//Research a element
Status LocateElem( LinkList L, ElemType e, Status(*compare)(ElemType,ElemType) )
{

}

//Clear the LinkList
void ClearList( LinkList &L )
{
	
}


//Caculate the length of the LinkList
void ListLength( LinkList L )
{
	
}

//Get the info which in the specific element
Status GetElem(int L,int i,ElemType &e)
{

}


 Status ListInsert(LinkList L,int i,ElemType e) 
 {
	 int j=0;				//Caculater
	 LinkList S,P=L;		//Def S & P Head pointer
	 while( P && j<(i-1) )
	 {
		 //Goto next Node until find the (i-1)th Node
		  j++;				
		  P=P->next;
	 }
	 //Judge the head pointer is out of the List or not
	 if(!P|| j>(i-1) )	
		 return ERROR;
	 //Insert the element 'e' between (i-1) and i element
	 S=(LinkList)malloc(sizeof(LNode));
	 S->data=e;
	 S->next=P->next;
	 P->next=S;
	 return OK;	 
}
