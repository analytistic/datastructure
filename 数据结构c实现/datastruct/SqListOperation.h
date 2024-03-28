#ifndef SQLISTOPERATION_H_INCLUDED
#define SQLISTOPERATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//表初始长度
#define InitSize 100

//表中元素类型
typedef int ElemType;

//定义一个SeqList类型
typedef struct SeqList{
    ElemType *data; //动态分配数组指针
    ElemType MaxSize, length; //数组的最大容量和当前个数
}SeqList; //动态数组

void InitSeqList(SeqList *L);
bool SeqListInsert(SeqList *L,int i,ElemType e);
bool SeqListDelete(SeqList *L, int i, ElemType *e);
int LocateElem(SeqList L, ElemType e);
void IncreaseSize(SeqList *L, int len);
void SeqList_Print(SeqList L);
void SeqList_Build(SeqList *L);
#endif // SQLISTOPERATION_H_INCLUDED
