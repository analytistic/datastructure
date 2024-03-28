#ifndef SQLISTOPERATION_H_INCLUDED
#define SQLISTOPERATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//���ʼ����
#define InitSize 100

//����Ԫ������
typedef int ElemType;

//����һ��SeqList����
typedef struct SeqList{
    ElemType *data; //��̬��������ָ��
    ElemType MaxSize, length; //�������������͵�ǰ����
}SeqList; //��̬����

void InitSeqList(SeqList *L);
bool SeqListInsert(SeqList *L,int i,ElemType e);
bool SeqListDelete(SeqList *L, int i, ElemType *e);
int LocateElem(SeqList L, ElemType e);
void IncreaseSize(SeqList *L, int len);
void SeqList_Print(SeqList L);
void SeqList_Build(SeqList *L);
#endif // SQLISTOPERATION_H_INCLUDED
