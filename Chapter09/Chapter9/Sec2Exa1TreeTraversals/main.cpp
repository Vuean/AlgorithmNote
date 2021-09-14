/*
����һ�ö������ĺ���������к�����������У�����ö�
�����Ĳ���������С�
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

int pre[maxn], in[maxn], post[maxn];	// �������򡢺���
int n;	// ������

// ��ǰ�������ĺ�����������Ϊ[postL, postR]��������������Ϊ[inL,inR]
// create�������ع������Ķ������ĸ�����ַ

node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR) {
		return NULL;	// �������г���С�ڵ���0ʱ��ֱ�ӷ���
	}
	node* root = new node;	// �½�һ���µĽ�㣬������ŵ�ǰ�������ĸ����
	root->data = post[postR];	// �½���������Ϊ������ֵ
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == post[postR]) {
			// �������������ҵ�in[k] == post[postR]�Ľ��
			break;
		}
	}
	int numLeft = k - inL;	// �������Ľ�����
	// �����������ĸ�����ַ�� ��ֵ��root ����ָ��
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	// �����������ĸ�����ַ����ֵ��root ����ָ��
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;	// ���ظ�����ַ
}

int num = 0;	// ������Ľ�����
void BFS(node* root) {
	queue<node*> q;
	q.push(root);	// ��������ַ���
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
	BFS(root);	// ��α���
}