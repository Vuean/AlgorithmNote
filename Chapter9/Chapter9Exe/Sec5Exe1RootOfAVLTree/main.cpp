/*
给出N 个正整数，将它们依次插入一棵初始为空的AVL树上，
求插入后根结点的值 。
*/

#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	int v, height;		// v为结点权值，height为当前子树高度
	node* lchild, * rchild;
} *root;

// 生成一个新结点
node* newNode(int v)
{
	node* Node = new node;
	Node->v = v;
	Node->height = 1;		// 结点初始高度为1
	Node->lchild = Node->rchild = NULL;
	return Node;
}

// 获取以root为根结点的子树的当前height
int getHeight(node* root)
{
	if (root == NULL) return 0;
	return root->height;
}

// 更新结点root的height
void updateHeight(node* root)
{
	// max(左孩子结点的height，右孩子结点的height) + 1;
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

// 计算结点root的平衡因子
int getBalanceFactor(node* root)
{
	// 左子树高度减右子树高度
	return getHeight(root->lchild) - getHeight(root->rchild);
}

// 左旋
void L(node* &root)
{
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

// 右旋
void R(node*& root)
{
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

// 插入权值为v的结点
void insert(node*& root, int v)
{
	if (root == NULL)
	{
		root = newNode(v);
		return;
	}
	if (v < root->v)
	{// v比根结点权值小
		insert(root->lchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == 2)
		{
			if (getBalanceFactor(root->lchild) == 1)
			{// LL
				R(root);
			}
			else if (getBalanceFactor(root->lchild) == -1)
			{// LR
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{// v比根结点权值大
		insert(root->rchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == -2)
		{
			if (getBalanceFactor(root->rchild) == -1)
			{// RR
				L(root);
			}
			else if (getBalanceFactor(root->rchild) == 1)
			{// RL
				R(root->rchild);
				L(root);
			}
		}
	}
}

// AVL树的建立
node* Create(int data[], int n)
{
	node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		insert(root, data[i]);
	}
	return root;
}

int main()
{
	int n, v;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &v);
		insert(root, v);
	}
	printf("%d\n", root->v);
}