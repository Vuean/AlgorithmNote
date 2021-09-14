/*
����N������������Ϊһ�ö����������Ľ�����˳��
�ʣ��⴮�����Ƿ��Ǹö������������������л��Ǹ�
�����������ľ��������������С���ν��������ָ����
�����������н��������������γɵ�����Ҳ��������
���н����������ڻ���ڸ���㣬�������������С��
���������н��������򣩡�����Ǿ������������YES��
�������Ӧ�����ĺ������У��������NO��
*/

/*
˼·��
ͨ�������Ĳ������У��������������������Ծ��������������
ֻ��Ҫ��ԭ�����������ʱ�������������ķ���˳�򼴿ɣ�
������ʾ�����룺
*/

/*
�����������������������vi
void preOrderMirror(node* root, vector<int>& vi) {
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->right, vi);	// �ȱ����������� �ٱ���������
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

// ��������� �������vi
void preOrder(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

// ��������������� ��������vi
void preOrderMirror(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->right, vi);
	preOrderMirror(root->left, vi);
}

// ��������� ��������vi
void postOrder(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
}

// �����������������������vi
void postOrderMirror(node* root, vector<int>& vi)
{
	if (root == NULL) return;
	postOrderMirror(root->right, vi);
	postOrderMirror(root->left, vi);
	vi.push_back(root->data);
}

// origin ��ų�ʼ����
// pre��post Ϊ���򡢺��� preM��postM Ϊ���������򡢺���
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
	preOrder(root, pre);				// ������
	preOrderMirror(root, preM);	// ����������
	postOrder(root, post);
	postOrderMirror(root, postM);
	if (origin == pre) {
		// ��ʼ���е�����������
		printf("YES\n");
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i < post.size() - 1) printf(" ");
		}
	}
	else if (origin == preM) {
		// ��ʼ���е��ھ�������������
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