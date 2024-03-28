#include "SqListOperation.h"
//初始化顺序表
void InitSeqList(SeqList *L){
    L->data = (ElemType *)malloc(sizeof(ElemType)*InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

//插入操作
//返回值为0或1，所以用bool
bool SeqListInsert(SeqList *L, int i, ElemType e){
    if(i<1||i>L->length+1){
        return false;//判断i是否有效
    }
    if(L->length>=L->MaxSize){
        return false;//判断存储空间是否已满
    }
    for(int j=L->length+1; j>=i-1; j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;//顺序表第i个位置data[i-1]=e
    L->length++;//顺序表长度加1
    return true;
}

//删除操作
bool SeqListDelete(SeqList *L, int i, ElemType *e){
    if(i<1||i>L->length){
        return false;//判断删除范围
    }
    *e = L->data[i-1];//传出删除元素给*e
    for(int j=i; j<L->length; j++){
        L->data[j-1] = L->data[j];//从表i位置的元素data[i-1]依次前移元素
    }
    L->length--;//顺序表长度减1
    return true;
}

//查找操作
//不需要改变元素，直接传入L，防止顺序表被修改
int LocateElem(SeqList L, ElemType e){
    for(int i=1; i<=L.length; i++){
        if(L.data[i-1]==e){
            return i;//返回位序i的元素data[i-1]
        }
    }
    return 0;//未找到返回0
}

//增加动态数组长度
void IncreaseSize(SeqList *L, int len){
    ElemType *p = L->data;
    L->data = (ElemType *)malloc(sizeof(ElemType)*(L->MaxSize+len));
    for(int i=1; i<=L->length; i++){
        L->data[i-1] = p[i-1];//将数据复制到新区域
    }
    L->MaxSize = L->MaxSize +len;
    free(p);//释放原来的存储空间
}

//输出顺序表
void SeqList_Print(SeqList L){
    for(int i=0; i<L.length; i++){
        printf("%d ", L.data[i]);
    }
}

//顺序表建立
void SeqList_Build(SeqList *L){
    InitSeqList(L);
    int i=0;
    ElemType x;
    scanf("%d", &x);
    while(x!=9999){
        L->data[i] = x;
        i++;
        L->length++;
        scanf("%d", &x);
    }

}



