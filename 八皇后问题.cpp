#include<stdio.h>
void print_board(int board[])
{
	static int cnt = 1;
	printf("ANS: %d\n",cnt++);
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			if(j == board[i])
			printf("O");
			else 
			printf(".");
		}
		printf("\n");
	}
}
int illegal(int n,int board[])
{
	for(int i = 1;i < n;i++){
		for(int j = 0;j < i;j++){
			if(board[i] == board[j]||board[i] - board[j] == i-j||board[i] - board[j] == j-i)
			return 1;
		}}
		return 0;
	
}
void eight_queen(int i,int board[])
{
	if(i>=8)
	print_board(board);
	else{
		for(int j=0;j<8;j++){
			board[i]=j;
			if(!illegal(i+1,board))
			eight_queen(i+1,board);
		}
	}
}
int main()
{
	int  board[8] = {0,0,0,0,0,0,0,0};
	eight_queen(0,board);
	return 0;
}

