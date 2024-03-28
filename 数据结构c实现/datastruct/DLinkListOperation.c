#include "DLinkListOperation.h"
//��ʼ��
bool InitDLinkList(DLinkList *L){
    *L = (DNode *)malloc(sizeof(DNode));
    if(*L==NULL){
        return false;
    }
    (*L)->next = NULL ;
    return true;
}

//ͷ�巨����˫����
DLinkList *DLinkList_HeadInsert(DLinkList *L){
    //��ʼ��
    *L = (DNode *)malloc(sizeof(DNode));
    (*L)->next = NULL;

    ElemType x;
    scanf("%d",&x);
    while(x!=9999){
        //����һ���½ڵ�
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

//����Ų���
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

//��ֵ����
DNode *DLinkList_LocateElem(DLinkList L, ElemType e){
    DNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p = p->next;
    }
    return p;
}

//����ڵ�
bool DLinkList_Insert(DLinkList L, int i, ElemType e){
    DNode *p=DLinkList_GetElem(L, i-1);
    if(p==NULL){
        return false;
    }

    //�����½ڵ�
    DNode *s=(DNode *)malloc(sizeof(DNode));

    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//ɾ���ڵ�
bool DLinkList_Delete(DLinkList L, int i){
    DNode *p=GetElem(L, i-1);
    if(p==NULL){
        return false;
    }

    DNode *q=p->next;//ָ��ɾ���ڵ�i

    p->next = q->next;
    q->next->prior = p;
    free(q);
}







