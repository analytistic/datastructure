#include "DLinkListOperation.h"
//初始化
bool InitDLinkList(DLinkList *L){
    *L = (DNode *)malloc(sizeof(DNode));
    if(*L==NULL){
        return false;
    }
    (*L)->next = NULL ;
    return true;
}

//头插法建立双链表
DLinkList *DLinkList_HeadInsert(DLinkList *L){
    //初始化
    *L = (DNode *)malloc(sizeof(DNode));
    (*L)->next = NULL;

    ElemType x;
    scanf("%d",&x);
    while(x!=9999){
        //创建一个新节点
        DNode *s;
        s = (DNode *)malloc(sizeof(DNode));

        if((*L)->next!=NULL){
                (*L)->next->prior = s;
        }
        s->data = x;
        s->next = (*L)->next;
        s->prior = (*L);
        (*L)->next = s;

        scanf("%d", &x);
    }
    return L;
}

//按序号查找
DNode *DLinkList_GetElem(DLinkList L, int i){
    if(i==0){
        return L;
    }
    if(i<0){
        return NULL;
    }

    DNode *p;
    p = L->next;
    int j=1;
    while(p!=NULL&&j<i){
        p = p->next;
        j++;
    }
    return p;
}

//按值查找
DNode *DLinkList_LocateElem(DLinkList L, ElemType e){
    DNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p = p->next;
    }
    return p;
}

//插入节点
bool DLinkList_Insert(DLinkList L, int i, ElemType e){
    DNode *p=DLinkList_GetElem(L, i-1);
    if(p==NULL){
        return false;
    }

    //申请新节点
    DNode *s=(DNode *)malloc(sizeof(DNode));

    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//删除节点
bool DLinkList_Delete(DLinkList L, int i){
    DNode *p=GetElem(L, i-1);
    if(p==NULL){
        return false;
    }

    DNode *q=p->next;//指向被删除节点i

    p->next = q->next;
    q->next->prior = p;
    free(q);
}







