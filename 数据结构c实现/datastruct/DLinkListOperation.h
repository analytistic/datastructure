#ifndef DLINKLISTOPERATION_H_INCLUDED
#define DLINKLISTOPERATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;



//����һ��˫����ڵ�
typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

//˫�����������
bool InitDLinkList(DLinkList *L);
DLinkList *DLinkList_HeadInsert(DLinkList *L);
DNode *DLinkList_GetElem(DLinkList L, int i);
DNode *DLinkList_LocateElem(DLinkList L, ElemType e);
bool DLinkList_Insert(DLinkList L, int i, ElemType e);
bool DLinkList_Delete(DLinkList L, int i);
#endif // DLINKLISTOPERATION_H_INCLUDED
