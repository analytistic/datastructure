#include<stdio.h>
void print_ans(int n0,int *arr,int len){
	static int cnt = 0;
	printf("[%03d] %d = ",++cnt,n0);
	for(int i=0;i<len;i++)
	printf(" %d +",arr[i]);
	printf("\b\b      \n");
}
void split_int(int n0,int n,int pos,int *arr)
{
	if(n==0)
	print_ans(n0,arr,pos);
	else for(int i=1;i<=n;i++){
		arr[pos++]=i;
	split_int(n0,n-i,pos,arr);
		pos--;
	}
}
void test_split_int()
{
	int arr[1000];
	split_int(10,10,0,arr);
}
int main()
{
	test_split_int();
	return 0;
}

