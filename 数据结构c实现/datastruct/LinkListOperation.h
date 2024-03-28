#ifndef LINKLISTOPERATION_H_INCLUDED
#define LINKLISTOPERATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

//����һ���ڵ����ͣ�������ָ��
typedef struct LNode{
    ElemType data;//������
    struct LNode *next;//ָ����
}LNode, *LinkList;

//�������������
bool InitLinkList(LinkList *L);
bool Empty(LinkList L);
LinkList *List_HeadInsert(LinkList *L);
LinkList *List_TailInsert(LinkList *L);
LNode *GetElem(LinkList L, int i);
LNode *LinkList_LocateElem(LinkList L, ElemType e);
bool LinkList_Insert(LinkList L, int i, ElemType e);
bool LinkList_Delete(LinkList L, int i);
int LinkList_Size(LinkList L);






#endif // LINKLISTOPERATION_H_INCLUDED
