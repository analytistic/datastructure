#include "SqListOperation.h"
//�ڶ���
//1.��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ���������ر�ɾ��Ԫ�ص�ֵ���ճ�λ�������һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���˳�
bool Del_Min(SeqList *L, ElemType *value){
    //��գ����ش���
    if(L->length==0){
        return false;
    }

    //�ֱ��¼ֵ��λ��
    *value = L->data[0];
    int pos=0;

    for(int i=0; i<L->length; i++){
        if(*value>L->data[i]){
            *value = L->data[i];
            pos = i;
        }
    }
    L->data[pos] = L->data[(L->length)-1];
    L->length--;//�λ�ã���ɾ�����һ��Ԫ��
    return true;
}

//2.��˳���L������Ԫ�����ã�Ҫ��ռ临�Ӷ�ΪO(1)
//��չһ�£�Ҫ�����ñ���left��right��Ԫ��
void Reverse(SeqList *L, int left, int right){
    //ɨ��ǰ��Σ��������Ԫ�أ�ʱ�临�Ӷ�ΪO(n)
    ElemType temp;
    for(int i=left; i<=left-1+(right-left+1)/2; i++){
        temp = L->data[i-1];
        L->data[i-1] = L->data[right-(i-left)-1];
        L->data[right-(i-left)-1] = temp;
    }
}


//3.�Գ���Ϊn��˳���L����дһ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)���㷨�����㷨ɾ��˳���������ֵΪx������Ԫ��
void Del_X_1(SeqList *L, ElemType e){
    int j=0;//��¼ǰ��λ��
    for(int i=0; i<L->length-j; i++){
        L->data[i]=L->data[i+j];
        if(L->data[i+j]==e){
            j++;
            i--;
        }
    }
    L->length = L->length-j;

}
//�汾2
void Del_X_2(SeqList *L, ElemType e){
    //ʹ��һ��k����¼Ҫɾ��Ԫ�ص�λ��,i���ɨ�裬������Ԫ��
    int k = 0;
    for(int i=0; i<L->length; i++){
        if(L->data[i]!=e){
            L->data[k]=L->data[i];
            k++;
        }
    }
    L->length=k;//ɾ������Ԫ��
}

//4.������˳�����ɾ��s<=x<=t��Ԫ��,��s��t�������˳���Ϊ�գ��򷵻ش���
bool Del_s_t(SeqList *L, ElemType s, ElemType t){
    if(s>t||L->length==0){
        return false;
    }

    //kΪ��ɾ�������׸�λ��i���ɨ��Ѱ�����Ԫ��
    int k=0;
    for(int i=0; i<L->length; i++){
        if(L->data[i]<s||L->data[i]>t){
            L->data[k] = L->data[i];
            k++;
        }
    }

    if(L->length = k){
        return false;//��Ϊk���ʾs���ڱ�������Ԫ�ػ�tС�ڱ�������Ԫ�أ�����ʧ��
    }
    else{
        L->length = k;
        return true;
    }
}

//5.��4���������޸�Ϊ˳�����������������Ч

//6.��*�����*��ɾ�������ظ�Ԫ��
//���������ĳ������O(n)���㷨��Ҫɢ�б�ʵ��
bool Delete_Same(SeqList *L){
    if(L->length==0){
        return false;
    }
    int k=1;//��һ��Ԫ��data[0]�����ܳ�Ϊ��ɾ��Ԫ�أ�k��1��ʼ
    for(int i=1; i<L->length; i++){
        if(L->data[i]!=L->data[i-1]){
           L->data[k]=L->data[i];
           k++;
        }
    }
    L->length = k;
    return true;
}



//7.�����������ϲ�Ϊһ���µ�����������ؽ��
bool Merge(SeqList A, SeqList B, SeqList *C){
    if(A.length+B.length>C->MaxSize){
        return false;//C�������������ش���
    }

    int i=0,j=0,k=0;
    while(i<A.length&&j<B.length){
            if(A.data[i]<=B.data[j]){
                C->data[k++]=A.data[i++];//����C��Ԫ�غ�k++,i++
            }
            else{
                C->data[k++]=B.data[j++];
            }
    }

    //��ʣ�������C���
    //ע�⵽��A����ȫ�ڱ��У����ʱi=A.length
    while(i<A.length){
        C->data[k++] = A.data[i++];
    }
    while(j<B.length){
        C->data[k++] = B.data[j++];
    }
    C->length = k;
    return true;
}

//8.��֪һά����A[m+n]�д��������˳���A,B,��дһ����������������˳����λ��
bool Exchange(SeqList *L, int m, int n){
    //���m��n�Ƿ�Ϸ�
    if((m+n)!=L->length||m<1||n>L->length){
        return false;
    }

    //����Reverse, ʹ���Ϊ[B_n,...B_1,A_m,...,A_1], Ȼ���B���A��ֱ�ʹ��Reverse
    int i=1;//��ֹ����
    Reverse(L, i, m+n);
    Reverse(L, i, n);
    Reverse(L, n+i, m+n);
    return true;
}

//9.˳����е�Ԫ�ص�������Ҫ�����һ���㷨�������ʱ�������ֵΪx��Ԫ�أ����ҵ���������Ԫ�ؽ��������Ҳ����������˳�����ʹ���������
//���Һ�����˳�����O(n),�۰����O(logn)
int SeqList_Binary_Search(SeqList L, ElemType x){
    int low=0,high=L.length-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(L.data[mid]==x){
            return mid+1; //���ҵ�������λ��
            break;//����whileѭ��
        }
        else{
            if(L.data[mid]<x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    /*
    if(L.data[mid]==x){
        return mid+1;//����λ����������±�
    }
    else{
        return false;
    }
    */
    return high+2;//��û�ҵ�����Χx���б��е�λ��
}
//����һ��p��¼�Ƿ���ҳɹ�
int SeqList_Binary_Search_P(SeqList L, ElemType x, int *p){
    int low=0,high=L.length-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(L.data[mid]==x){
            *p = 1;
            return mid+1; //���ҵ�������λ��
            break;//����whileѭ��
        }
        else{
            if(L.data[mid]<x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    /*
    if(L.data[mid]==x){
        return mid+1;//����λ����������±�
    }
    else{
        return false;
    }
    */
    return high+2;//��û�ҵ�����Χx���б��е�λ��
}

//��������
void Ex_9(SeqList *L, int i){
    ElemType x;
    x = L->data[i];
    L->data[i] = L->data[i-1];
    L->data[i-1] = x;
    printf("%d\n",x);
}

//�������˲��ң����������뺯��
void searchExchangeInsert(SeqList *L, ElemType x){
    int i,p=0;
    //���ң�������pֵ����λ��
    i=SeqList_Binary_Search_P(*L, x, &p);
    //printf("%d %d\n",i,p);
    if(p!=1){
        SeqListInsert(L, i, x);
    }
    else{
        Ex_9(L,i);
    }

}

//10.���б���Ԫ��ѭ������p��λ�á�X_0,...,X_(p-1),X_p,...,X_(n-1)--->X_p,...,X_(n-1),X_0,...,X_(p-1)
//���׷��������б�õ�X_(n-1),...,X_p,X_(p-1),...,X_0 Ȼ��ֱ����������ּ��õ����
//�����8����һ�µ�
void Converse(SeqList *L, int p){
    Reverse(L, 1, L->length);
    Reverse(L, 1, L->length-p);
    Reverse(L, L->length-p+1, L->length);

}

//11.����ΪL������S�ĵ�[L/2]λ���ϵ�����Ϊ��λ��������A,B����*�ȳ�*���У���A��B����λ��
/*˼·����A��B��λ���ֱ�Ϊa,b;
��a=b,��a��Ϊ����
��a<b,����A�н�Сһ�룬B�нϴ�룬��Ҫ����������������ͬ
��a>b,����A�нϴ�һ�룬B�н�С�룬��Ҫ����������������ͬ
Ȼ�󲻶��ظ���������ֱ��s1=d1, s2=d2, �͵õ���A+B�м����������ȡС���ɡ�
��Ϊ���۰������ʱ�临�Ӷ�ΪO(logn),������6��int���ռ临�Ӷ�ΪO(1)
*/
int SeqList_Median_Number_Search(SeqList A, SeqList B){
    //��¼˳����������м�
    int s1=0,d1=A.length-1,s2=0,d2=B.length-1;
    int m1,m2;
    while(s1!=d1||s2!=d2){
        m1=(s1+d1)/2;
        m2=(s2+d2)/2;
        if(A.data[m1]==B.data[m2]){
            return m1;
        }
        if(A.data[m1]<B.data[m2]){
            if((d1-s1+1)%2==0){
                s1=m1+1;//����Ϊż��A��Ҫ����ǰ����м��
                d2=m2;//B��Ҫ����ǰ����м��
            }
            else{
                s1=m1+1;
                d2=m2-1;
            }
        }
        else{
            //��m1>m2,�����������������
            if((d2-s2+1)%2==0){
                s2=m2+1;
                d1=m1;
            }
            else{
                s2=m2+1;
                d1=m1-1;
            }
        }
    }
    return A.data[s1]<B.data[s2]?A.data[s1]:B.data[s2];//��ʱs1,s2�Ѿ���A+B���м�����Ԫ�أ����չ���ȡ��Сһ������
}

//12.��֪��������A����(0,5,5,3,5,7,5,5)����������������n/2��5ΪA����Ԫ�ء����һ���㷨�ҳ�A�е���Ԫ�ء��������������Ԫ�أ��������-1
//����㷨���ǲ�̫������ģ�����ע�⵽ͳ��ǰ��ɸѡ�õ���Ԫ��Ҳ����һ���ǳ��ִ�������Ԫ��
//һ���ȽϺ���ķ�����������Ȼ��ȡ�����е��м���A[n/2]���������ż�������м�����Ҫ����β��,��������������м������Ե���ͷ��β��
int Majority( SeqList A){
    int i,c,count=1;//c��¼Ԫ�أ�count��Ϊ������
    c = A.data[0];//��A_0��ʼ
    for(i=1;i<A.length;i++){
        if(c==A.data[i]){
            count++;
        }
        else{
            if(count>0)
                count--;
            else{
                c=A.data[i];
                count = 1;
            }
        }
    }
    printf("%d %d",c, count);
    //ͳ�ƺ�ѡԪ�ص�ʵ�ʳ��ִ���
    if(count>0){
        for(i=count=0;i<A.length;i++){
            if(A.data[i]==c)
                count++;
        }
    }
    if(count>A.length/2){
        return c;
    }
    else{
        return -1;
    }
}

//13.����һ�����飬���һ����ʱ���Ͼ����ܸ�Ц���㷨���ҳ�������δ���ֵ���С������
int findMissMin(SeqList L){


}



























