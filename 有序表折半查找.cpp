#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct Node{
	int id;
	int num;
}Node;
typedef struct List{
	Node Nodes[100];
	int length;
}List;
void maopao(List *a);
int main()
{
	int i,k,f=0,qian=0,hou=99,t=0,arg;
	srand(time(0));
	List a;
	for(i=0;i<100;i++)
	{
		a.Nodes[i].id=i+1;		
		a.Nodes[i].num=rand()%100+1;
	}	
	for(i=0;i<100;i++)
	{
	printf("%d:%d,",a.Nodes[i].id,a.Nodes[i].num);
	}
	maopao(&a);
	for(i=0;i<100;i++)
	{
	printf("%d:%d,",a.Nodes[i].id,a.Nodes[i].num);
}
	
	printf("\n");
	int b=rand()%100+1;
	printf("要查找的数据:%d\n",b);
	
	while(qian+1!=hou)
	{
		t++;
		arg=(qian+hou)/2;
		if(a.Nodes[arg].num<b)
			qian=arg;
		if(a.Nodes[arg].num>b)
			hou=arg;
		if(a.Nodes[arg].num==b)
		{
			f=1;
			printf("查找结果的位置:%d\n",a.Nodes[arg].id);
			break;
		}
	}
	if(f==0)
		printf("不在数列中\n");
	printf("查找次数:%d",t);
	return 0;
}
void maopao(List *a)
{
	int i,t,j,p;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100-i;j++)
		{
			if(a->Nodes[j].num>a->Nodes[j+1].num)
			{			
				t=a->Nodes[j].num;
				a->Nodes[j].num=a->Nodes[j+1].num;
				a->Nodes[j+1].num=t;
			}
		} 
	}
}
