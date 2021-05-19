/*
����N �������������������β���һ�ó�ʼΪ�յ�AVL���ϣ�
�����������ֵ ��
*/

#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	int v, height;		// vΪ���Ȩֵ��heightΪ��ǰ�����߶�
	node* lchild, * rchild;
} *root;

// ����һ���½��
node* newNode(int v)
{
	node* Node = new node;
	Node->v = v;
	Node->height = 1;		// ����ʼ�߶�Ϊ1
	Node->lchild = Node->rchild = NULL;
	return Node;
}

// ��ȡ��rootΪ�����������ĵ�ǰheight
int getHeight(node* root)
{
	if (root == NULL) return 0;
	return root->height;
}

// ���½��root��height
void updateHeight(node* root)
{
	// max(���ӽ���height���Һ��ӽ���height) + 1;
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

// ������root��ƽ������
int getBalanceFactor(node* root)
{
	// �������߶ȼ��������߶�
	return getHeight(root->lchild) - getHeight(root->rchild);
}

// ����
void L(node* &root)
{
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

// ����
void R(node*& root)
{
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

// ����ȨֵΪv�Ľ��
void insert(node*& root, int v)
{
	if (root == NULL)
	{
		root = newNode(v);
		return;
	}
	if (v < root->v)
	{// v�ȸ����ȨֵС
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
	{// v�ȸ����Ȩֵ��
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

// AVL���Ľ���
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