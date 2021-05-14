/*
����N���Ǹ�������Ҫ�����ǹ���һ����ȫ������������
��������ȫ�����������Ĳ���������С�
*/
// ��һ�ö�����������˵�� ��������������ǵ�����

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
//n Ϊ������� number���Դ�Ž��Ȩֵ�� CBT���Դ����ȫ������
// index��С����ö��number����

int n, number[maxn], CBT[maxn], index = 0;

// �������
void inOrder(int root)
{
	if (root > n) return;	// �ս�㣬 ֱ�ӷ���
	inOrder(root * 2);
	CBT[root] = number[index++];
	inOrder(root * 2 + 1);
}

int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &number[i]);
	}
	sort(number, number + n);	// ��С��������
	inOrder(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", CBT[i]);
		if (i < n) printf(" ");
	}
}