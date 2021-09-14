/*
二叉树有N个结点（ 结点编号为0 ~ N-1)，给出每个结点的左右孩子结点的编号，
把该二叉树反转（即把每个结点的左右子树都交换），输出反转后二叉树的
层序遍历序列和中序遍历序列。
*/

/*反转二叉树的操作只需要进行后序遍历，在后序遍历访问
根结点时交换lchild和rchild即可。*/

#include <cstdio>
#include <queue> 
#include <algorithm>
using namespace std;
const int maxn = 110;

struct node {
	// 二叉树的静态写法
	int lchild, rchild;
} Node[maxn];

bool notRoot[maxn] = { false };	// 记录是否不是根结点， 初始均是根结点
int n, num = 0;	// 	n为结点个数，num为当前已经输出的结点个数

// print函数输出结点过的编号
void print(int id)
{
	printf("%d", id);
	num++;
	if (num < n) printf(" ");
	else printf("\n");
}

// 中序遍历
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

// 层序遍历
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

// 后序遍历， 用以反转二叉树
void postOrder(int root)
{
	if (root == -1)
	{
		return;
	}
	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);	//交换左右孩子结点 
}

// 将输入的字符转换为-1或者结点编号
int strToNum(char c)
{
	if (c == '-') return -1;
	else {
		notRoot[c - '0'] = true;
		return c - '0';
	}
}

// 寻找根结点编号
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
	num = 0;			// 已输出的结点个数置0
	inOrder(root);
}