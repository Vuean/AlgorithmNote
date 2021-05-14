/*
给出N个非负整数，要用它们构建一棵完全二叉排序树。
输出这棵完全二叉排序树的层序遍历序列。
*/
// 对一棵二叉排序树来说， 其中序遍历序列是递增的

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
//n 为结点数， number用以存放结点权值， CBT用以存放完全二叉树
// index从小到大枚举number数组

int n, number[maxn], CBT[maxn], index = 0;

// 中序遍历
void inOrder(int root)
{
	if (root > n) return;	// 空结点， 直接返回
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
	sort(number, number + n);	// 从小到大排序
	inOrder(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", CBT[i]);
		if (i < n) printf(" ");
	}
}