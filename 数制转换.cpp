#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define STACK_INIT_SIZE 100   //存储空间初始分配 
#define STACKINCREMENT 10     //存储空间分配增量 

typedef struct{
	char *base;           //栈底 
	char *top;		      //栈顶 
	int stacksize;        //当前已分配的存储空间 
}SqStack;

int InitStack(SqStack &S)    //传入的是引用 
{
	S.base=(char *)malloc(STACKINCREMENT*sizeof(char));
	if(!S.base)
		exit(0);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return 1;
}

void Push(SqStack &S,char e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(char *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(char));
		if(!S.base)
			exit(0);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;                //原指针指向赋值，指针++ 
	 
}

int Pop(SqStack &S,char &e)
{
	if(S.top==S.base)
		return 0;
	e=*--S.top; 
	return 1;
}

int StackEmpty(SqStack &S)
{
	if(S.top==S.base)
		return 1;
	else 
		return 0;
}

char mod_16(int x,int mod)
{
	int y=x%mod;
	switch(y)
	{
		case 10:
			return 'a';
		case 11:
			return 'b';
		case 12:
			return 'c';
		case 13:
			return 'd';
		case 14:
			return 'e';
		case 15:
			return 'f';
		default:
			return y+'0';
	}
}

void conversion(int N)
{
	SqStack S;
	InitStack(S);
	
	char e;
	
	while(N)
	{
		Push(S,mod_16(N,16));
		N=N/16;
	}
	while(!StackEmpty(S))
	{
		Pop(S,e);
		printf("%c",e);
	}
}
int main()
{
	int N;
	srand(time(0));
	N=rand()%89999+10000;
	printf("要查找的数据n=%d\n",N);
	printf("转换后的十六进制数:");
	conversion(N);
	printf("\n");
	printf("标准十六进制输出:%x\n",N);	
}

