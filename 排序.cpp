#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int cmp=0;
int move=0;
typedef struct{
	int r[201];
}SqList;

void Init(SqList &L){
	int i;
	for(i=0;i<201;i++){
		L.r[i]=0;
	}
}
//随机数据 
void randdata(SqList &L){
	int i;
	for (i=0;i<201;i++){
		L.r[i]=rand();
	}
}

//单增数据
void  danzengdata(SqList &L){
	int i,a;
	L.r[0]=0;
	srand((unsigned)time(NULL));
	for(i=1;i<201;i++){
		
		a=rand()%10;
		L.r[i]=L.r[i-1]+a; 
	}
}

//单减数据
void  danjiandata(SqList &L){
	int i,a;
	L.r[0]=3782;
	srand((unsigned)time(0));
	for(i=1;i<201;i++){
		
		a=rand()%10;
		L.r[i]=L.r[i-1]-a; 
	}
} 

//近似单增数据
void  jinsizengdata(SqList &L){
	int i,a;
	L.r[0]=300;
	srand((unsigned)time(0));
	for(i=1;i<201;i++){
		
		a=rand()%10-4;
		L.r[i]=L.r[i-1]-a; 
	}
}  

//近似单调减数据
 void  jinsijiandata(SqList &L){
	int i,a;
	L.r[0]=300;
	srand((unsigned)time(0));
	for(i=1;i<201;i++){
		
		a=rand()%10-7;
		L.r[i]=L.r[i-1]-a; 
	}
} 

void HeapAdjust(SqList &L,int s,int m){
	int j;
	L.r[0]=L.r[s];
	for (j=2*s;j<=m;j*=2){
		if(j+1<=m&&L.r[j]>L.r[j+1] ) {
			j++;
			cmp=cmp+2;
		}
		if(L.r[0]<=L.r[j])  {
			cmp++;
			break;
		}
		L.r[s]=L.r[j];
		move++;
		s=j;
	}
	L.r[s]=L.r[0];
	move++;
	
}

void Swap(SqList &L,int m,int n){
	int temp;
	temp=L.r[m];

	L.r[m]=L.r[n];
	L.r[n]=temp;
	move=move+2;
}
void HeapSort(SqList &L){
	int i;
	for (i=200/2;i>=1;i--){
		HeapAdjust (L,i,200);
	}
	for (i=200;i>1;i--){
		printf("%d\n",L.r[1]);
		Swap(L,1,i);
		HeapAdjust(L,1,i-1);
	}
}

int main(){
	SqList L;
	Init(L);
//	randdata(L);
//	danzengdata(L);
//	danjiandata(L);
//	jinsizengdata(L);
	jinsijiandata(L);
	HeapSort(L);
//	printdata(L);
	printf("比较次数：%d,移动次数：%d",cmp,move);
}












