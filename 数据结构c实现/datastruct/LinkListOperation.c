#include "LinkListOperation.h"

//初始化带头结点的链表
//LinkList L是一个头指针，传入其地址&L，在Init函数中使用形参LinkList *L=&L，得到一个二级指针L
bool InitLinkList(LinkList *L){
    *L = (LNode *)malloc(sizeof(LNode));//分配一个头节点，*L即为main中的L
    if(*L==NULL){
        return false;//内存不足分配失败
    }
    (*L)->next = NULL;
    return true;
}

//判断链表是否为空
//LinkList L为一级指针，即为main中的L
bool Empty(LinkList L){
    if(L->next==NULL){
        return true;
    }
    else{
        return false;
    }
}

//头插法建立单链表
//返回的是二级指针，LinkList类型的指针，所以用LinkList *函数类型名
LinkList *List_HeadInsert(LinkList *L){
    LNode *s;
    ElemType x;

    //初始化空链表
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

//尾插法建立单链表
LinkList *List_TailInsert(LinkList *L){
    ElemType x;

    //初始化空链表
    *L = (LNode *)malloc(sizeof(LNode));

    LNode *s, *r=(*L);//s为插入节点指针，r为尾节点指针,先指向头节点

    scanf("%d",&x);
    while(x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;//尾节点next指向插入节点后，尾指针更新
        scanf("%d",&x);
    }
    r->next = NULL;//尾节点指针置空
    return L;
}

//按序号顺序查找
//返回一个节点指针
LNode *GetElem(LinkList L, int i){
    if(i<1){
        return L;//若i为0，返回头指针
    }
    int j=1;
    LNode *p=L->next;
    while(p!=NULL&&j<i){
        p = p->next;
        j++;
    }
    return p;//返回指针指向第i个节点，若i大于表长，返回NULL
}

//按值顺序查找
LNode *LinkList_LocateElem(LinkList L, ElemType e){
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}

//插入节点
bool LinkList_Insert(LinkList L, int i, ElemType e){
    //寻找前驱节点i-1，并检查合法性
    LNode *p;
    p = GetElem(L, i-1);
    if(p==NULL){
        return false;
    }

    //申请一个新节点
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));

    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//删除节点
bool LinkList_Delete(LinkList L, int i){
    LNode *p;
    p = GetElem(L, i-1);
    if(p==NULL){
        return false;
    }

    //q指向待删除节点i
    LNode *q;
    q = p->next;
    p->next = q->next;
    free(q);//释放节点i
    return true;
}

//求表长
int LinkList_Size(LinkList L){
    int i = 0;
    LNode *p=L;
    while(p->next!=NULL){
        i++;
        p = p->next;
    }
    return i;
}

































































