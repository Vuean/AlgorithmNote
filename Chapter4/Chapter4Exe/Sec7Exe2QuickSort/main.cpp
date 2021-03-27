/*
题目描述：
著名的快速排序算法里有一个经典的划分过程：通常采用某种方法取一个元素作为主元，
通过交换，把比主元小的元素放到其左边，把比主元大的元素放到其右边。给定划分后的N
个互不相同的正整数的排列，请问有多少个阮素可能是划分前选取的主元？
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3fffffff; // `一个很大的数

// a为序列，leftMax和rightmin分别为左边最大的数和右边最小的数
int a[MAXN], leftMax[MAXN], rightMin[MAXN];
// ans记录所有主元，num为主元个数
int ans[MAXN], num = 0;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	leftMax[0] = 0;
	for (int i = 1; i < n; i++)
	{
		leftMax[i] = max(leftMax[i - 1], a[i-1]);
	}
	rightMin[n - 1] = INF;	// A[n-1]右边没有比它小的数
	for (int i = n - 2; i >= 0; i--)
	{
		rightMin[i] = min(rightMin[i + 1], a[i + 1]);
	}
	for (int i = 0; i < n; i++)
	{
		if (leftMax[i] < a[i] && rightMin[i] > a[i])
		{
			ans[num++] = a[i];	// 记录主元
		}
	}
	cout << "NUM = " << num << endl;
	for (int i = 0; i < num; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}