#include "LinkListOperation.h"

//��ʼ����ͷ��������
//LinkList L��һ��ͷָ�룬�������ַ&L����Init������ʹ���β�LinkList *L=&L���õ�һ������ָ��L
bool InitLinkList(LinkList *L){
    *L = (LNode *)malloc(sizeof(LNode));//����һ��ͷ�ڵ㣬*L��Ϊmain�е�L
    if(*L==NULL){
        return false;//�ڴ治�����ʧ��
    }
    (*L)->next = NULL;
    return true;
}

//�ж������Ƿ�Ϊ��
//LinkList LΪһ��ָ�룬��Ϊmain�е�L
bool Empty(LinkList L){
    if(L->next==NULL){
        return true;
    }
    else{
        return false;
    }
}

//ͷ�巨����������
//���ص��Ƕ���ָ�룬LinkList���͵�ָ�룬������LinkList *����������
LinkList *List_HeadInsert(LinkList *L){
    LNode *s;
    ElemType x;

    //��ʼ��������
    *L = (LNode *)malloc(sizeof(LNode));
    (*L)->next = NULL;

    scanf("%d", &x);
    while(x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = (*L)->next;
        (*L)->next = s;
        scanf("%d",&x);
    }
    return L;
}

//β�巨����������
LinkList *List_TailInsert(LinkList *L){
    ElemType x;

    //��ʼ��������
    *L = (LNode *)malloc(sizeof(LNode));

    LNode *s, *r=(*L);//sΪ����ڵ�ָ�룬rΪβ�ڵ�ָ��,��ָ��ͷ�ڵ�

    scanf("%d",&x);
    while(x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;//β�ڵ�nextָ�����ڵ��βָ�����
        scanf("%d",&x);
    }
    r->next = NULL;//β�ڵ�ָ���ÿ�
    return L;
}

//�����˳�����
//����һ���ڵ�ָ��
LNode *GetElem(LinkList L, int i){
    if(i<1){
        return L;//��iΪ0������ͷָ��
    }
    int j=1;
    LNode *p=L->next;
    while(p!=NULL&&j<i){
        p = p->next;
        j++;
    }
    return p;//����ָ��ָ���i���ڵ㣬��i���ڱ�������NULL
}

//��ֵ˳�����
LNode *LinkList_LocateElem(LinkList L, ElemType e){
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}

//����ڵ�
bool LinkList_Insert(LinkList L, int i, ElemType e){
    //Ѱ��ǰ���ڵ�i-1�������Ϸ���
    LNode *p;
    p = GetElem(L, i-1);
    if(p==NULL){
        return false;
    }

    //����һ���½ڵ�
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));

    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//ɾ���ڵ�
bool LinkList_Delete(LinkList L, int i){
    LNode *p;
    p = GetElem(L, i-1);
    if(p==NULL){
        return false;
    }

    //qָ���ɾ���ڵ�i
    LNode *q;
    q = p->next;
    p->next = q->next;
    free(q);//�ͷŽڵ�i
    return true;
}

//���
int LinkList_Size(LinkList L){
    int i = 0;
    LNode *p=L;
    while(p->next!=NULL){
        i++;
        p = p->next;
    }
    return i;
}

































































