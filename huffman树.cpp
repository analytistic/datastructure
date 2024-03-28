// 赫夫曼编码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#include <malloc.h>
struct Node {
	int weight;	//		权值
	int parent, lchild, rchild;
};
//统计每个字符出现的次数
void Statis_char(int char_freque[]) {
	FILE * fp;
	fp = fopen("a.txt", "r");
	char c;
	while ((c = fgetc(fp)) != EOF ) {

		if (c >= 97)
			char_freque[c - 97]++;
		else if (c >= 65)
			char_freque[c - 39]++;
		else if (c == ',')
			char_freque[52]++;
		else if (c == ' ')
			char_freque[53]++;
		else if (c == '.')
			char_freque[54]++;
		else	//有的编译器可能无法使用exit函数，把此else语句注释掉就可以了
		{
			printf("非法字符\n");
			exit(EOVERFLOW);
		}
	}
	fclose(fp);
}
//统计总共有多少种不同的字符
int Statis_n(int char_freque[]) {
	int n = 0;
	for (int i = 0; i < 55; i++)
		if (char_freque[i] != 0)
			n++;
	return n;
}
//对现在的m棵树进行初始化
void Init_tree(Node HT[], char ture_form[], int char_freque[], char character[], int m) {
	int i, j;
	for (i = 0, j = 1; i < 55; i++)
		if (char_freque[i] != 0) {
			HT[j] = { char_freque[i],0,0,0 };
			ture_form[j] = character[i];	//第j个叶子结点对应的字符为ture_form[j]
			j++;
		}
	for (; j <= m; j++)
		HT[j] = { 0,0,0,0 };

}
//从前k个结点中选取两个parent为0且weight最小的结点
void Select(Node * HT, int k, int * i, int * j) {
	int min1, min2;
	min1 = min2 = 2000;	//假设任何一个字符的权值都不超过2000.
	for (int t = 1; t <= k; t++) {
		if (HT[t].parent == 0) {
			if (HT[t].weight < min1) {
				min1 = HT[t].weight;
				*i = t;
			}
			else if (HT[t].weight < min2) {
				min2 = HT[t].weight;
				*j = t;
			}
		}
	}
}
//建立赫夫曼树
void Creat_HT(Node * HT, int n, int m) {
	int i;
	int  s1, s2;
	for (i = n + 1; i <= m; i++) {
		Select(HT, i - 1, &s1, &s2);
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[s1].parent = HT[s2].parent = i;
	}

}
//对每一个字符进行编码，逆序编码
char * * Huf_code(Node * HT, int n) {
	char * cd = (char *)malloc(n * sizeof(char));
	char * * HC = (char * *)malloc((n + 1) * sizeof(char *));	//此处注意分配的char *类型的存储空间，而不是char类型
	cd[n - 1] = '\0';	//所有字符的编码长度不会超过（n - 1）
	int p;
	int start;
	int c;
	for (int i = 1; i <= n; i++) {
		c = i;
		start = n - 1;
		p = HT[i].parent;
		while (p != 0) {
			if (HT[p].lchild == c)
				cd[--start] = '0';
			if (HT[p].rchild == c)
				cd[--start] = '1';
			c = p;
			p = HT[c].parent;
		}
		HC[i] = (char *)malloc((n - start) * sizeof(char));

		strcpy(HC[i], &cd[start]);

	}
	return HC;
}
//读取文章，并生成此文章的赫夫曼编码到文件b.txt中。
void read_creat_code(char * * HC, int n, char * ture_form) {
	FILE * fp_r = fopen("a.txt", "r");
	FILE * fp_w = fopen("b.txt", "w");
	char c = fgetc(fp_r);
	int i, j;
	while (c != EOF) {
		for (i = 1; i <= n; i++) {
			if (c == ture_form[i])	//判断当前读入的字符在原码中的位置
				break;
		}
		c = HC[i][0];
		for (j = 1; c != '\0'; j++) {
			fputc(c, fp_w);
			c = HC[i][j];
		}
		c = fgetc(fp_r);
	}
	fclose(fp_r);
	fclose(fp_w);
}
//判断当前存储在数组code中的编码是否为有效编码
int judge_valid(char ** HC, char code[], int n) {
	for (int i = 1; i <= n; i++)
		if (strcmp(code, HC[i]) == 0)
			return i;
	return 0;
}
//译码
void decode(char ** HC, int n, char ture_form[]) {
	FILE * fpr, *fpw;
	fpr = fopen("b.txt", "r");
	fpw = fopen("c.txt", "w");
	char code[10] = { 0 };	//默认所有字符的编码长度不超过9，（字符数组最后一个元素为'\0'）
	for (int i = 0; i < 10; i++) {
		if ((code[i] = fgetc(fpr)) == EOF)
			break;	//已经读到文件的末尾
		int state;	//若当前编码无效，则state为0，否则为当前编码对应字符在数组ture_form中的位置
		state = judge_valid(HC, code, n);
		if (state != 0) {	//若编码有效，则把对应字符写到文件里，并让下一个读到的赫夫曼码放到code[0]里面
			fputc(ture_form[state], fpw);
			i = -1;
			for (int j = 0; j < 10; j++)	//清空此临时数组
				code[j] = '\0';
		}
	}
	fclose(fpr);
	fclose(fpw);
}
int main()
{

	int n;	//总共出现了n种不同的字符
	int m;	//所需总的结点个数
	int i;	//临时变量
	char * ture_form;	//文章中出现的字符用此数组存储
	char character[55];		//存储所有可能出现的字符
	int char_freque[55] = { 0 };	//记录每个字符出现的次数
	Node * HT;		//结点类型的指针，用来指向Huffman树的m个结点
	//初始化文章中所有可能出现的字符
	for (i = 0; i <= 25; i++)
		character[i] = i + 97;
	for (i = 26; i <= 51; i++)
		character[i] = i + 39;
	character[52] = ',';
	character[53] = ' ';
	character[54] = '.';

	Statis_char(char_freque);	//统计每个字符出现的次数
	n = Statis_n(char_freque);		//统计总共出现了多少种不同的字符
	printf("%d",n);
	m = 2 * n - 1;		//构建此Huffman树所需的节点个数
	HT = (Node *)malloc((m + 1) * sizeof(Node));		//第零个存储空间不用
	ture_form = (char *)malloc((n + 1) * sizeof(char));	//共有n种不同的字符，这n种字符用数组ture_form存储，第零个存储空间不用
	Init_tree(HT, ture_form, char_freque, character, m);	//初始化Huffman树的每个结点
	Creat_HT(HT, n, m);		//建立Huffman树
	char * * HC;		//HC[i]指向第i个字符的Huffman编码
	HC = (char * *)malloc((n + 1) * sizeof(char *));	//第0个存储空间不用
	HC = Huf_code(HT, n);	//对n个字符进行编码
	read_creat_code(HC, n, ture_form);	//读取文章，并对整篇文章进行编码
	decode(HC, n, ture_form);		//读取Huffman编码并译码
}



