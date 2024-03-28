// �շ�������.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#include <malloc.h>
struct Node {
	int weight;	//		Ȩֵ
	int parent, lchild, rchild;
};
//ͳ��ÿ���ַ����ֵĴ���
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
		else	//�еı����������޷�ʹ��exit�������Ѵ�else���ע�͵��Ϳ�����
		{
			printf("�Ƿ��ַ�\n");
			exit(EOVERFLOW);
		}
	}
	fclose(fp);
}
//ͳ���ܹ��ж����ֲ�ͬ���ַ�
int Statis_n(int char_freque[]) {
	int n = 0;
	for (int i = 0; i < 55; i++)
		if (char_freque[i] != 0)
			n++;
	return n;
}
//�����ڵ�m�������г�ʼ��
void Init_tree(Node HT[], char ture_form[], int char_freque[], char character[], int m) {
	int i, j;
	for (i = 0, j = 1; i < 55; i++)
		if (char_freque[i] != 0) {
			HT[j] = { char_freque[i],0,0,0 };
			ture_form[j] = character[i];	//��j��Ҷ�ӽ���Ӧ���ַ�Ϊture_form[j]
			j++;
		}
	for (; j <= m; j++)
		HT[j] = { 0,0,0,0 };

}
//��ǰk�������ѡȡ����parentΪ0��weight��С�Ľ��
void Select(Node * HT, int k, int * i, int * j) {
	int min1, min2;
	min1 = min2 = 2000;	//�����κ�һ���ַ���Ȩֵ��������2000.
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
//�����շ�����
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
//��ÿһ���ַ����б��룬�������
char * * Huf_code(Node * HT, int n) {
	char * cd = (char *)malloc(n * sizeof(char));
	char * * HC = (char * *)malloc((n + 1) * sizeof(char *));	//�˴�ע������char *���͵Ĵ洢�ռ䣬������char����
	cd[n - 1] = '\0';	//�����ַ��ı��볤�Ȳ��ᳬ����n - 1��
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
//��ȡ���£������ɴ����µĺշ������뵽�ļ�b.txt�С�
void read_creat_code(char * * HC, int n, char * ture_form) {
	FILE * fp_r = fopen("a.txt", "r");
	FILE * fp_w = fopen("b.txt", "w");
	char c = fgetc(fp_r);
	int i, j;
	while (c != EOF) {
		for (i = 1; i <= n; i++) {
			if (c == ture_form[i])	//�жϵ�ǰ������ַ���ԭ���е�λ��
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
//�жϵ�ǰ�洢������code�еı����Ƿ�Ϊ��Ч����
int judge_valid(char ** HC, char code[], int n) {
	for (int i = 1; i <= n; i++)
		if (strcmp(code, HC[i]) == 0)
			return i;
	return 0;
}
//����
void decode(char ** HC, int n, char ture_form[]) {
	FILE * fpr, *fpw;
	fpr = fopen("b.txt", "r");
	fpw = fopen("c.txt", "w");
	char code[10] = { 0 };	//Ĭ�������ַ��ı��볤�Ȳ�����9�����ַ��������һ��Ԫ��Ϊ'\0'��
	for (int i = 0; i < 10; i++) {
		if ((code[i] = fgetc(fpr)) == EOF)
			break;	//�Ѿ������ļ���ĩβ
		int state;	//����ǰ������Ч����stateΪ0������Ϊ��ǰ�����Ӧ�ַ�������ture_form�е�λ��
		state = judge_valid(HC, code, n);
		if (state != 0) {	//��������Ч����Ѷ�Ӧ�ַ�д���ļ��������һ�������ĺշ�����ŵ�code[0]����
			fputc(ture_form[state], fpw);
			i = -1;
			for (int j = 0; j < 10; j++)	//��մ���ʱ����
				code[j] = '\0';
		}
	}
	fclose(fpr);
	fclose(fpw);
}
int main()
{

	int n;	//�ܹ�������n�ֲ�ͬ���ַ�
	int m;	//�����ܵĽ�����
	int i;	//��ʱ����
	char * ture_form;	//�����г��ֵ��ַ��ô�����洢
	char character[55];		//�洢���п��ܳ��ֵ��ַ�
	int char_freque[55] = { 0 };	//��¼ÿ���ַ����ֵĴ���
	Node * HT;		//������͵�ָ�룬����ָ��Huffman����m�����
	//��ʼ�����������п��ܳ��ֵ��ַ�
	for (i = 0; i <= 25; i++)
		character[i] = i + 97;
	for (i = 26; i <= 51; i++)
		character[i] = i + 39;
	character[52] = ',';
	character[53] = ' ';
	character[54] = '.';

	Statis_char(char_freque);	//ͳ��ÿ���ַ����ֵĴ���
	n = Statis_n(char_freque);		//ͳ���ܹ������˶����ֲ�ͬ���ַ�
	printf("%d",n);
	m = 2 * n - 1;		//������Huffman������Ľڵ����
	HT = (Node *)malloc((m + 1) * sizeof(Node));		//������洢�ռ䲻��
	ture_form = (char *)malloc((n + 1) * sizeof(char));	//����n�ֲ�ͬ���ַ�����n���ַ�������ture_form�洢��������洢�ռ䲻��
	Init_tree(HT, ture_form, char_freque, character, m);	//��ʼ��Huffman����ÿ�����
	Creat_HT(HT, n, m);		//����Huffman��
	char * * HC;		//HC[i]ָ���i���ַ���Huffman����
	HC = (char * *)malloc((n + 1) * sizeof(char *));	//��0���洢�ռ䲻��
	HC = Huf_code(HT, n);	//��n���ַ����б���
	read_creat_code(HC, n, ture_form);	//��ȡ���£�������ƪ���½��б���
	decode(HC, n, ture_form);		//��ȡHuffman���벢����
}



