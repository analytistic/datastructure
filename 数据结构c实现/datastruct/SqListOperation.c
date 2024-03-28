#include "SqListOperation.h"
//��ʼ��˳���
void InitSeqList(SeqList *L){
    L->data = (ElemType *)malloc(sizeof(ElemType)*InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}

//�������
//����ֵΪ0��1��������bool
bool SeqListInsert(SeqList *L, int i, ElemType e){
    if(i<1||i>L->length+1){
        return false;//�ж�i�Ƿ���Ч
    }
    if(L->length>=L->MaxSize){
        return false;//�жϴ洢�ռ��Ƿ�����
    }
    for(int j=L->length+1; j>=i-1; j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;//˳����i��λ��data[i-1]=e
    L->length++;//˳����ȼ�1
    return true;
}

//ɾ������
bool SeqListDelete(SeqList *L, int i, ElemType *e){
    if(i<1||i>L->length){
        return false;//�ж�ɾ����Χ
    }
    *e = L->data[i-1];//����ɾ��Ԫ�ظ�*e
    for(int j=i; j<L->length; j++){
        L->data[j-1] = L->data[j];//�ӱ�iλ�õ�Ԫ��data[i-1]����ǰ��Ԫ��
    }
    L->length--;//˳����ȼ�1
    return true;
}

//���Ҳ���
//����Ҫ�ı�Ԫ�أ�ֱ�Ӵ���L����ֹ˳����޸�
int LocateElem(SeqList L, ElemType e){
    for(int i=1; i<=L.length; i++){
        if(L.data[i-1]==e){
            return i;//����λ��i��Ԫ��data[i-1]
        }
    }
    return 0;//δ�ҵ�����0
}

//���Ӷ�̬���鳤��
void IncreaseSize(SeqList *L, int len){
    ElemType *p = L->data;
    L->data = (ElemType *)malloc(sizeof(ElemType)*(L->MaxSize+len));
    for(int i=1; i<=L->length; i++){
        L->data[i-1] = p[i-1];//�����ݸ��Ƶ�������
    }
    L->MaxSize = L->MaxSize +len;
    free(p);//�ͷ�ԭ���Ĵ洢�ռ�
}

//���˳���
void SeqList_Print(SeqList L){
    for(int i=0; i<L.length; i++){
        printf("%d ", L.data[i]);
    }
}

//˳�����
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



