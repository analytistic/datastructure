#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define STACK_INIT_SIZE 100   //�洢�ռ��ʼ���� 
#define STACKINCREMENT 10     //�洢�ռ�������� 

typedef struct{
	char *base;           //ջ�� 
	char *top;		      //ջ�� 
	int stacksize;        //��ǰ�ѷ���Ĵ洢�ռ� 
}SqStack;

int InitStack(SqStack &S)    //����������� 
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
	*S.top++=e;                //ԭָ��ָ��ֵ��ָ��++ 
	 
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
	printf("Ҫ���ҵ�����n=%d\n",N);
	printf("ת�����ʮ��������:");
	conversion(N);
	printf("\n");
	printf("��׼ʮ���������:%x\n",N);	
}

