/*
给出N个正整数来作为一棵二叉排序树的结点插入顺序，问这串
序列是否是该二叉排序树的先序序列或是该二叉排序树的镜像
树的先序序列。所谓镜像树是指交换二叉树的所有结点的左右
子树而形成的树（也即左子树所有结点数据域大于或等于根结点
，而根结点数据域小于右子树所有结点的数据域）。如果是，
则输出"YES",并输出对应的树的后序序列；否则，输出"NO"。
*/

/*
思路:
通过给定的插入序列，构建出二叉排序树。对镜像树的先序遍
历只需要在原树的先序遍历时交换左右子树的访问顺序即可.
*/

#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int data;
	node* left, * right;
};

// 插入结点，构建二叉查找树
void insert(node* &root, int data)
{
	if (root == NULL)
	{
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	if (data < root->data) insert(root->left, data);
	else insert(root->right, data);
}

// 先序遍历，存入vector
void preOrder(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

// 镜像先序遍历，存入vector
void preOrderMirror(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->right, vi);
	preOrderMirror(root->left, vi);
}

// 后序遍历，存入vector
void postOrder(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
}

// 镜像树后序遍历，存入vector
void postOrderMirror(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	postOrderMirror(root->right, vi);
	postOrderMirror(root->left, vi);
	vi.push_back(root->data);
}

// origin 为初始序列，pre、post为先序、后序，preM、postM 为镜像树先序、后序
vector<int> origin, pre, preM, post, postM;

int main()
{
	int n, data;
	node* root = NULL;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &data);
		origin.push_back(data);
		insert(root, data);	// 将data插入二叉树
	}
	preOrder(root, pre);						// 求先序
	preOrderMirror(root, preM);		// 求镜像树先序
	postOrder(root, post);					// 求后序
	postOrderMirror(root, postM);	// 求镜像树后序
	if (origin == pre)
	{
		printf("YES\n");
		for (int i = 0; i < post.size(); i++)
		{
			printf("%d", post[i]);
			if (i < post.size() - 1) printf(" ");
		}
	}
	else if (origin == preM)
	{// 初始序列等于镜像树先序序列
		printf("YES\n");
		for (int i = 0; i < postM.size(); i++)
		{
			printf("%d", postM[i]);
			if (i < postM.size() - 1) printf(" ");
		}
	}
	else
	{
		printf("NO\n");
	}
}