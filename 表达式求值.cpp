#include <stdio.h>
int main()
{
	char str[1000]={'\0'};
	gets(str);
	char ch;
	int i=0,j=0;
	int sum[2]={0};
	int result=0;
	for(;str[i]!='\0';i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			while(1)
			{
				if(str[i]>='0'&&str[i]<='9')
				{
					sum[j]=sum[j]*10+(str[i]-'0');
					i++;
					
				}
				else
				{
					j++;
					break;
				} 
			}
		}
		if(str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-'||str[i]=='%')
		ch=str[i];
	}
	if(ch=='*')
	{
		result=sum[0]*sum[1];
	}
	else if(ch=='/')
	{
		result=sum[0]/sum[1];
	}
	else if(ch=='+')
	{
		result=sum[0]+sum[1];
	}
	else if(ch=='%')
	result=sum[0]%sum[1];
	else 
	result=sum[0]-sum[1];
	printf("%d",result);
	return 0;
}

