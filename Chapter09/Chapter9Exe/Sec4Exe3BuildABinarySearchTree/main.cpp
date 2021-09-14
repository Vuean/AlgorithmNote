/*
��������N����㣨�����ΪO ~ N-1)������ÿ��������
�Һ��ӽ��ı�ţ���������-1��ʾ�� �����Ÿ���һ��N����
�������У���Ҫ����N����������������Ľ���У�ʹ�ö�����
��Ϊһ�ö���������������ö���������Ĳ���������С�
*/
// �����Ĭ��Ϊ0�Ž�㣬 ��˲���ҪѰ�Ҹ���㡣

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;

struct node {
	int data;
	int lchild, rchild;
}Node[maxn];

// nΪ��������inΪ�������У�numΪ�Ѿ����룯����Ľ�����
int n, in[maxn], num = 0;
// ���������������õ���������������������

void inOrder(int root)
{
	if (root == -1)
	{
		return;
	}
	inOrder(Node[root].lchild);
	Node[root].data = in[num++];
	inOrder(Node[root].rchild);
}

// �������
void BFS(int root)
{
	queue<int> q;
	q.push(root);
	num = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		printf("%d", Node[now].data);
		num++;
		if (num < n) printf(" ");
		if (Node[now].lchild != -1) q.push(Node[now].lchild);
		if (Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}

int main()
{
	int lchild, rchild;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &lchild);
		scanf_s("%d", &rchild);
		Node[i].lchild = lchild;
		Node[i].rchild = rchild;
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &in[i]);	// ��������ǰ������
	}
	sort(in, in + n);	// ��С���������Ϊ��������
	inOrder(0);	// ��0 �Ž��Ϊ�������������������������
	BFS(0);
}