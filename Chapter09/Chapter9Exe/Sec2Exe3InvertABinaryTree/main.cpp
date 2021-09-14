/*
��������N����㣨 �����Ϊ0 ~ N-1)������ÿ���������Һ��ӽ��ı�ţ�
�Ѹö�������ת������ÿ�����������������������������ת���������
����������к�����������С�
*/

/*��ת�������Ĳ���ֻ��Ҫ���к���������ں����������
�����ʱ����lchild��rchild���ɡ�*/

#include <cstdio>
#include <queue> 
#include <algorithm>
using namespace std;
const int maxn = 110;

struct node {
	// �������ľ�̬д��
	int lchild, rchild;
} Node[maxn];

bool notRoot[maxn] = { false };	// ��¼�Ƿ��Ǹ���㣬 ��ʼ���Ǹ����
int n, num = 0;	// 	nΪ��������numΪ��ǰ�Ѿ�����Ľ�����

// print������������ı��
void print(int id)
{
	printf("%d", id);
	num++;
	if (num < n) printf(" ");
	else printf("\n");
}

// �������
void inOrder(int root)
{
	if (root == -1)
	{
		return;
	}
	inOrder(Node[root].lchild);
	print(root);
	inOrder(Node[root].rchild);
}

// �������
void BFS(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		print(now);
		if (Node[now].lchild != -1) q.push(Node[now].lchild);
		if (Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}

// ��������� ���Է�ת������
void postOrder(int root)
{
	if (root == -1)
	{
		return;
	}
	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);	//�������Һ��ӽ�� 
}

// ��������ַ�ת��Ϊ-1���߽����
int strToNum(char c)
{
	if (c == '-') return -1;
	else {
		notRoot[c - '0'] = true;
		return c - '0';
	}
}

// Ѱ�Ҹ������
int findRoot()
{
	for (int i = 0; i < n; i++)
	{
		if (notRoot[i] == false)
		{
			return i;
		}
	}
}

int main()
{
	char lchild, rchild;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%*c%c %c", &lchild, &rchild);
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();
	postOrder(root);
	BFS(root);
	num = 0;			// ������Ľ�������0
	inOrder(root);
}