/*
题意：
给出一个数字序列与一个数s, 在数字序列中求出所有和值为S的连续子序列（区间下
标左端点小的先输出，左端点相同时右端点小的先输出）。若没有这样的序列，求出和值恰好
大于S的子序列（即在所有和值大于S的子序列中和值最接近S)。假设序列下标从1 开始。
*/

/*
考虑到题目要求输出所有方案， 因此需要对序列进行两次遍历， 其中第一次遍历求出大
于等于S的最接近S的和值nearS; 第二次遍历找到那些和值恰好为nearS的方案并输出， 总
复杂度为O(nlogn)。
*/

/*
注意点：
1. 使用cin和cout可能超时，请使用scanf与printf
*/
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;

// uppert_bound函数返回在[L, R)内第一个大于x的位置
int upper_bound(int L, int R, int x)
{
	int left = L, right = R, mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (sum[mid] > x)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	cin >> n >> S;
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	// 枚举端点
	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + S);
		if (sum[j - 1] - sum[i - 1] == S)	// 查找成功：注意是j-1，而不是j
		{
			nearS = S;	// 最接近S的值就是S
			break;
		}
		else if (j <= n && sum[j] - sum[i - 1] < nearS)
		{
			// 存在大于S的解，并小于nearS
			nearS = sum[j] - sum[i - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);	// 求右端点
		if (sum[j - 1] - sum[i - 1] == nearS)
		{
			printf("%d-%d\n", i, j - 1);
		}
	}
}