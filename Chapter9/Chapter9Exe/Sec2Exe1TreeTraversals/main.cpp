/*
����һ�ö������ĺ���������к�����������У�����ö���
���Ĳ���������С�
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;

struct node {
	int data;
	node* lchild;
	node* rchild;
};

int pre[maxn], in[maxn], post[maxn];	// �������򡢺���
int n;	// ������

// ��ǰ�������ĺ�����������Ϊ[postL, postR]��������������Ϊ[inL, inR]
// create�������ع������Ķ������ĸ�����ַ
node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR) {
		// ���������г���Сǧ����0����ֱ�ӷ���
		return NULL;
	}
	node* root = new node;
	root->data = post[postR];
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == post[postR]) {
			break;
		}
	}
	int numleft = k - inL;	// �������Ľ�����
	// �����������ĸ�����ַ�� ��ֵ��root����ָ��
	root->lchild = create(postL, postL + numleft - 1, inL, k - 1);
	// �����������ĸ�����ַ����ֵ��root ����ָ��
	root->rchild = create(postL + numleft, postR - 1, k+1, inR);
	return root;
}

int num = 0;	// �����������
void BFS(node* root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n) printf(" ");
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);
	}
}

int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &post[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf_s("%d", &in[i]);
	}
	node* root = create(0, n - 1, 0, n - 1);
	BFS(root);
}