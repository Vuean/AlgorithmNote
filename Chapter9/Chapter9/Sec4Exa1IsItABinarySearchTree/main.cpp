/*
给出N个正整数来作为一棵二叉排序树的结点插入顺序，
问：这串序列是否是该二叉排序树的先序序列或是该
二叉排序树的镜像树的先序序列。所谓镜像树是指交换
二叉树的所有结点的左右子树而形成的树（也即左子树
所有结点数据域大于或等于根结点，而根结点数据域小于
右子树所有结点的数据域）。如果是镜像树，则输出YES，
并输出对应的树的后序序列；否则，输出NO。
*/

/*
思路：
通过给定的插入序列，构建出二叉排序树。对镜像树的先序遍历
只需要在原树的先序遍历时交换左右子树的访问顺序即可，
下面是示例代码：
*/

/*
镜像树先序遍历，结果存放于vi
void preOrderMirror(node* root, vector<int>& vi) {
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->right, vi);	// 先遍历右子树， 再遍历左子树
	preOrderMirror(root->left, vi);
}
*/

#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int data;
	node *left, *right;
};

void insert(node*& root, int data)
{
	if (root == NULL) {
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	if (data < root->data) insert(root->left, data);
	else insert(root->right, data);
}

// 先序遍历， 结果存在vi
void preOrder(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

// 镜像树先序遍历， 结果存放于vi
void preOrderMirror(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->right, vi);
	preOrderMirror(root->left, vi);
}

// 后序遍历， 结果存放于vi
void postOrder(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
}

// 镜像树后序遍历，结果存放于vi
void postOrderMirror(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	postOrderMirror(root->right, vi);
	postOrderMirror(root->left, vi);
	vi.push_back(root->data);
}

// origin 存放初始序列
// pre、post 为先序、后序， preM、postM 为镜像树先序、后序
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
		insert(root, data);
	}
	preOrder(root, pre);				// 求先序
	preOrderMirror(root, preM);	// 求镜像树先序
	postOrder(root, post);
	postOrderMirror(root, postM);
	if (origin == pre) {
		// 初始序列等于先序序列
		printf("YES\n");
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i < post.size() - 1) printf(" ");
		}
	}
	else if (origin == preM) {
		// 初始序列等于镜像树先序序列
		printf("YES\n");
		for (int i = 0; i < postM.size(); i++) {
			printf("%d", postM[i]);
			if (i < postM.size() - 1) printf(" ");
		}
	}
	else {
		printf("NO\n");
	}
}