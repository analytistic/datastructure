#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char a[100];
	gets(a);
	int n,i=0;
	n=strlen(a);
	int N=0,I,k,sum=0,d,j,l,J;
	while(a[i]!='\0'){
	    if(!isdigit(a[i])){
			printf("%c",a[i]);
			i++;
		}
		else{
			N=0;
			I=i;
			d=0;
			sum=0;
			while(isdigit(a[I])){
				N++;
				I++;
			}
			for(j=i;j<=(I-1);j++,d++){
				k=1;
				for(l=1;l<N-d;l++){
					k=k*10;
				}
				sum=sum+(int(a[j])-48)*k;
			}
			for(J=1;J<sum;J++){
				printf("%c",a[i-1]);
			}
			i=I;
		}
	}
	printf("\n");
	return 0;
}
