#include<stdio.h>
#include<windows.h>
#include<time.h>

#define MaxSize 100
#define M 40
#define N 40
typedef struct
{   int i,j;    //新中国        
    int pre;    //��·������һ�����ڶ����е��±�   
}SqQueue; 
SqQueue Qu[42*42];  //����˳���ѭ������
int front=0,rear=0; 
int mg[M+2][N+2];
void initInterface()
{
	int i,j;
	srand(time(0));
	for(i=0;i<42;i++)
	{
		for(j=0;j<42;j++)
		{
			if(i==0||i==41||j==0||j==41)
				mg[i][j]=1;
			else if(rand()%2==0)
				mg[i][j]=0;
			else
				mg[i][j]=1;
		}
	}
	mg[1][1]=0;
	mg[40][40]=0;
} 
void drawInterface()
{
	int i,j;
	for(i=0;i<42;i++)
	{
		for(j=0;j<42;j++)
		{
			if(mg[i][j]==0)
			{
			
			printf("??");    //����ŵ�
			}
			else if(mg[i][j]==1)
			{
			
			printf("??");    //������ŵ�
			}
			else if(mg[i][j]==2)
			{
			
			printf("?��");	//·����
			}
			else if(mg[i][j]==-1) //���Թ������ܴﵽĿ�ĵ��·��
			{
								
			printf("??");	
			}
		}
		printf("\n");
	} 
}
void print(SqQueue Qu[],int front)    //�������
{   
    for(int i=front;i>0;i=Qu[i].pre)
    {
		mg[Qu[i].i][Qu[i].j]=2;
        printf("(%d,%d)->",Qu[i].i,Qu[i].j); 
   }
	printf("\n");
}
int mgpath1(int xi,int yi,int xe,int ye)	//����·��Ϊ:(xi,yi)->(xe,ye)
{   
	int i, j, di, i1, j1;
    rear++;
    Qu[rear].i=xi; Qu[rear].j=yi; Qu[rear].pre=-1; //(xi,yi)����
	mg[xi][yi]=-1;		        //���丳ֵ-1,�Ա���ع����ظ�����
    while(front!=rear)		    //�Ӳ���ѭ��
    {   
		front++;
        i=Qu[front].i; j=Qu[front].j; //����
        if (i==xe && j==ye)	    //�ҵ��˳���,���·��
        {  
			print(Qu, front);	//����print�������·��
            return 1;		//�ҵ�һ��·��ʱ������
        }
        for (di=0;di<8;di++)    //ѭ��ɨ��ÿ����λ
        {	
          switch(di)
          {
			case 0:i1=i-1;   j1=j-1; break;
			case 1:i1=i-1;   j1=j;	 break;
            case 2:i1=i-1;   j1=j+1; break;
			case 3:i1=i;  	 j1=j+1; break;
			case 4:i1=i+1;   j1=j+1; break;
			case 5:i1=i+1;   j1=j;	 break;
            case 6:i1=i+1;   j1=j-1; break;
            case 7:i1=i;  	 j1=j-1; break;          

          }
          if(mg[i1][j1]==0)
          {   
			rear++;
            Qu[rear].i=i1; Qu[rear].j=j1; 
            Qu[rear].pre=front;	//(i1��j1)�������
			mg[i1][j1]=-1;	//���丳ֵ-1
          }
        }//for
    }//while
    return 0;
}//mgpath1
 
int main()
{ 
	system("cls");
	initInterface();
	drawInterface();
    if(!mgpath1(M,N,1,1))
        printf("?????????n");
	else
		drawInterface();
    return 1;
}

