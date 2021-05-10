/*
��ջ��ģ��һ�ö����������������������̣�����ö������ĺ���������С�
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
// ��ǰ��������������������Ϊ[preL, preR ] ��������������Ϊ[inL, inR]
// create�������ع������Ķ������ĸ�����ַ
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
	int numLeft = k - inL;	// �������Ľ�����
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
	int x, preIndex = 0, inIndex = 0;	// ��ջԪ�ء���������λ�ü���������λ��
	for (int i = 0; i < 2 * n; i++) {
		scanf_s("%s", str);
		if (strcmp(str, "Push") == 0) {
			// ��ջ
			scanf_s("%d", &x);
			pre[preIndex++] = x;
			st.push(x);
		}
		else {
			// ��ջ
			in[inIndex++] = x;
			st.pop();
		}
	}
	node* root = create(0, n - 1, 0, n - 1);
	postOrder(root);
}