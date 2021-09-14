/*
给出一棵二叉树的后序遍历序列和中序遍历序列，求这棵二
叉树的层序遍历序列。
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};

int pre[maxn], in[maxn], post[maxn];	// 先序、中序、后序
int n;	// 结点个数

// 当前二叉树的后序序列区间为[postL, postR]，中序序列区间为[inL,inR]
// create函数返回构建出的二叉树的根结点地址

node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR) {
		return NULL;	// 后序序列长度小于等于0时，直接返回
	}
	node* root = new node;	// 新建一个新的结点，用来存放当前二叉树的根结点
	root->data = post[postR];	// 新结点的数据域为根结点的值
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == post[postR]) {
			// 在中序序列中找到in[k] == post[postR]的结点
			break;
		}
	}
	int numLeft = k - inL;	// 左子树的结点个数
	// 返回左子树的根结点地址， 赋值给root 的左指针
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	// 返回右子树的根结点地址，赋值给root 的右指针
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;	// 返回根结点地址
}

int num = 0;	// 己输出的结点个数
void BFS(node* root) {
	queue<node*> q;
	q.push(root);	// 将根结点地址入队
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		cout << now->data;
		num++;
		if (num < n) cout << " ";
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);
	} 
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
	}
	node* root = create(0, n - 1, 0, n - 1);
	BFS(root);	// 层次遍历
}