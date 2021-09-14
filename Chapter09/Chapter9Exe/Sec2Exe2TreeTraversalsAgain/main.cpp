/*
用栈来模拟一棵二义树的先序和中序遍历过程，求这棵二叉树的后序遍历序列。
*/

# include <cstdio>
# include <cstring>
#include <stack>
# include <algorithm>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};

int pre[maxn], in[maxn], post[maxn];
int n;
// 当前二叉树的先序序列区间为[preL, preR ] ，中序序列区间为[inL, inR]
// create函数返回构建出的二叉树的根结点地址
node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == pre[preL]) {
			break;
		}
	}
	int numLeft = k - inL;	// 左子树的结点个数
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}

int num = 0;
void postOrder(node* root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d", root->data);
	num++;
	if (num < n) printf(" ");
}

int main()
{
	scanf_s("%d", &n);
	char str[5];
	stack<int> st;
	int x, preIndex = 0, inIndex = 0;	// 入栈元素、先序序列位置及中序序列位置
	for (int i = 0; i < 2 * n; i++) {
		scanf_s("%s", str);
		if (strcmp(str, "Push") == 0) {
			// 入栈
			scanf_s("%d", &x);
			pre[preIndex++] = x;
			st.push(x);
		}
		else {
			// 出栈
			in[inIndex++] = x;
			st.pop();
		}
	}
	node* root = create(0, n - 1, 0, n - 1);
	postOrder(root);
}