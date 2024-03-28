#include "SqListOperation.h"
//第二章
//1.从顺序表中删除具有最小值的元素（假设唯一），并返回被删除元素的值，空出位置由最后一个元素填补，若顺序表为空，则显示错误信息并退出
bool Del_Min(SeqList *L, ElemType *value){
    //表空，返回错误
    if(L->length==0){
        return false;
    }

    //分别记录值和位序
    *value = L->data[0];
    int pos=0;

    for(int i=0; i<L->length; i++){
        if(*value>L->data[i]){
            *value = L->data[i];
            pos = i;
        }
    }
    L->data[pos] = L->data[(L->length)-1];
    L->length--;//填补位置，并删除最后一个元素
    return true;
}

//2.将顺序表L的所有元素逆置，要求空间复杂度为O(1)
//拓展一下，要求逆置表中left到right的元素
void Reverse(SeqList *L, int left, int right){
    //扫描前半段，与后半表交换元素，时间复杂度为O(n)
    ElemType temp;
    for(int i=left; i<=left-1+(right-left+1)/2; i++){
        temp = L->data[i-1];
        L->data[i-1] = L->data[right-(i-left)-1];
        L->data[right-(i-left)-1] = temp;
    }
}


//3.对长度为n的顺序表L，编写一个时间复杂度为O(n),空间复杂度为O(1)的算法，该算法删除顺序表中所有值为x的数据元素
void Del_X_1(SeqList *L, ElemType e){
    int j=0;//记录前移位数
    for(int i=0; i<L->length-j; i++){
        L->data[i]=L->data[i+j];
        if(L->data[i+j]==e){
            j++;
            i--;
        }
    }
    L->length = L->length-j;

}
//版本2
void Del_X_2(SeqList *L, ElemType e){
    //使用一个k，记录要删除元素的位序,i向后扫描，并交换元素
    int k = 0;
    for(int i=0; i<L->length; i++){
        if(L->data[i]!=e){
            L->data[k]=L->data[i];
            k++;
        }
    }
    L->length=k;//删除后续元素
}

//4.从有序顺序表中删除s<=x<=t的元素,若s或t不合理或顺序表为空，则返回错误
bool Del_s_t(SeqList *L, ElemType s, ElemType t){
    if(s>t||L->length==0){
        return false;
    }

    //k为待删除段中首个位序，i向后扫描寻找替代元素
    int k=0;
    for(int i=0; i<L->length; i++){
        if(L->data[i]<s||L->data[i]>t){
            L->data[k] = L->data[i];
            k++;
        }
    }

    if(L->length = k){
        return false;//表长为k则表示s大于表中所有元素或t小于表中所有元素，返回失败
    }
    else{
        L->length = k;
        return true;
    }
}

//5.将4题中条件修改为顺序表，上述代码依旧有效

//6.从*有序表*中删除所有重复元素
//若将条件改成无序表，O(n)的算法需要散列表实现
bool Delete_Same(SeqList *L){
    if(L->length==0){
        return false;
    }
    int k=1;//第一个元素data[0]不可能成为待删除元素，k从1开始
    for(int i=1; i<L->length; i++){
        if(L->data[i]!=L->data[i-1]){
           L->data[k]=L->data[i];
           k++;
        }
    }
    L->length = k;
    return true;
}



//7.将两个有序表合并为一个新的有序表，并返回结果
bool Merge(SeqList A, SeqList B, SeqList *C){
    if(A.length+B.length>C->MaxSize){
        return false;//C表容量不够返回错误
    }

    int i=0,j=0,k=0;
    while(i<A.length&&j<B.length){
            if(A.data[i]<=B.data[j]){
                C->data[k++]=A.data[i++];//更新C表元素后，k++,i++
            }
            else{
                C->data[k++]=B.data[j++];
            }
    }

    //将剩余表连在C表后
    //注意到若A表已全在表中，则此时i=A.length
    while(i<A.length){
        C->data[k++] = A.data[i++];
    }
    while(j<B.length){
        C->data[k++] = B.data[j++];
    }
    C->length = k;
    return true;
}

//8.已知一维数组A[m+n]中存放有两个顺序表A,B,编写一个函数互换这两个顺序表的位置
bool Exchange(SeqList *L, int m, int n){
    //检查m，n是否合法
    if((m+n)!=L->length||m<1||n>L->length){
        return false;
    }

    //调用Reverse, 使表变为[B_n,...B_1,A_m,...,A_1], 然后对B表和A表分别使用Reverse
    int i=1;//防止出错
    Reverse(L, i, m+n);
    Reverse(L, i, n);
    Reverse(L, n+i, m+n);
    return true;
}

//9.顺序表中的元素递增有序，要求设计一个算法，用最短时间查找数值为x的元素，若找到将其与后继元素交换，若找不到将其插入顺序表，并使表递增有序
//查找函数，顺序查找O(n),折半查找O(logn)
int SeqList_Binary_Search(SeqList L, ElemType x){
    int low=0,high=L.length-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(L.data[mid]==x){
            return mid+1; //若找到，返回位序
            break;//跳出while循环
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
        return mid+1;//返回位序而非数组下标
    }
    else{
        return false;
    }
    */
    return high+2;//若没找到，范围x在列表中的位序
}
//增加一个p记录是否查找成功
int SeqList_Binary_Search_P(SeqList L, ElemType x, int *p){
    int low=0,high=L.length-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(L.data[mid]==x){
            *p = 1;
            return mid+1; //若找到，返回位序
            break;//跳出while循环
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
        return mid+1;//返回位序而非数组下标
    }
    else{
        return false;
    }
    */
    return high+2;//若没找到，范围x在列表中的位序
}

//交换函数
void Ex_9(SeqList *L, int i){
    ElemType x;
    x = L->data[i];
    L->data[i] = L->data[i-1];
    L->data[i-1] = x;
    printf("%d\n",x);
}

//最后调用了查找，交换，插入函数
void searchExchangeInsert(SeqList *L, ElemType x){
    int i,p=0;
    //查找，并返回p值，和位序
    i=SeqList_Binary_Search_P(*L, x, &p);
    //printf("%d %d\n",i,p);
    if(p!=1){
        SeqListInsert(L, i, x);
    }
    else{
        Ex_9(L,i);
    }

}

//10.将列表中元素循环左移p个位置。X_0,...,X_(p-1),X_p,...,X_(n-1)--->X_p,...,X_(n-1),X_0,...,X_(p-1)
//容易发现逆置列表得到X_(n-1),...,X_p,X_(p-1),...,X_0 然后分别逆置两部分即得到结果
//此题和8题是一致的
void Converse(SeqList *L, int p){
    Reverse(L, 1, L->length);
    Reverse(L, 1, L->length-p);
    Reverse(L, L->length-p+1, L->length);

}

//11.长度为L的升序S的第[L/2]位置上的数称为中位数，现有A,B两个*等长*序列，求A，B的中位数
/*思路：设A，B中位数分别为a,b;
若a=b,则a即为所求
若a<b,舍弃A中较小一半，B中较大半，且要求两次舍弃长度相同
若a>b,舍弃A中较大一半，B中较小半，且要求两次舍弃长度相同
然后不断重复上述操作直到s1=d1, s2=d2, 就得到了A+B中间的两个数，取小即可。
因为是折半操作，时间复杂度为O(logn),设置了6个int，空间复杂度为O(1)
*/
int SeqList_Median_Number_Search(SeqList A, SeqList B){
    //记录顺序表两边与中间
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
                s1=m1+1;//若表长为偶，A需要舍弃前面和中间点
                d2=m2;//B需要保留前面和中间点
            }
            else{
                s1=m1+1;
                d2=m2-1;
            }
        }
        else{
            //若m1>m2,将两表操作互换即可
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
    return A.data[s1]<B.data[s2]?A.data[s1]:B.data[s2];//此时s1,s2已经是A+B表中间两个元素，按照规则取较小一个即可
}

//12.已知整数序列A，如(0,5,5,3,5,7,5,5)，则其中数量大于n/2的5为A的主元素。设计一个算法找出A中的主元素。若存在则输出主元素；否则输出-1
//这个算法还是不太容易想的，并且注意到统计前的筛选得到的元素也并不一定是出现次数最多的元素
//一个比较好想的方法是先排序，然会取序列中的中间数A[n/2]，如果共有偶数个，中间数需要等于尾数,如果共奇数个，中间数可以等于头或尾数
int Majority( SeqList A){
    int i,c,count=1;//c记录元素，count作为计数器
    c = A.data[0];//从A_0开始
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
    //统计候选元素的实际出现次数
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

//13.给定一个数组，设计一个在时间上尽可能搞笑的算法，找出数组中未出现的最小正整数
int findMissMin(SeqList L){


}



























