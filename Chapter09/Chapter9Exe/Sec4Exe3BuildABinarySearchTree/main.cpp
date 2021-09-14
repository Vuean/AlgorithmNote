/*
二叉树有N个结点（结点编号为O ~ N-1)，给出每个结点的左
右孩子结点的编号（不存在用-1表示） 。接着给出一个N个整
数的序列，需要把这N个整数填入二叉树的结点中，使得二叉树
成为一棵二叉查找树。输出这棵二叉查找树的层序遍历序列。
*/
// 根结点默认为0号结点， 因此不需要寻找根结点。

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;

struct node {
	int data;
	int lchild, rchild;
}Node[maxn];

// n为结点个数，in为中序序列，num为已经填入／输出的结点个数
int n, in[maxn], num = 0;
// 中序遍历，将排序好的序列依次填入二叉树结点

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

// 层序遍历
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
		scanf_s("%d", &in[i]);	// 输入排序前的序列
	}
	sort(in, in + n);	// 从小到大排序后为中序序列
	inOrder(0);	// 以0 号结点为根结点进行中序遍历，填入整数
	BFS(0);
}