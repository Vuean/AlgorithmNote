/*
��������������׵�ַ�Լ����ɽ��ĵ�ַ�����ݡ���һ�����ĵ�ַ��
������������׸����ý��ĵ�ַ�������������û�й��ý�㣬�������1��
*/
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 100010;

struct NODE {
	char data;	// ������
	int next;	// ָ����
	bool flag;	// ����Ƿ��ڵ�һ�����г��ֹ�
}node[maxn];

int main()
{
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}

	int s1, s2, n;	// s1��s2 �ֱ��������������׵�ַ
	scanf_s("%d%d%d", &s1, &s2, &n);
	int address, next;;	// ����ַ���̽���ַ
	char data;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}
	int p;
	for (p = s1; p != -1; p = node[p].next)
	{
		node[p].flag = true;
	}
	for (p = s2; p != -1; p = node[p].next) {
		if (node[p].flag == true) break;
	}
	if (p != -1) {
		printf("%05d\n", p);
	}
	else {
		printf("-1\n");
	}
}