/*
最大连续子序列和问题如下：给定一个数字序列A1，A2，...，An，求i，j(1≤i≤j≤n)，使得Ai+...+Aj最大，输出这个最大和。
*/

#include<cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int A[maxn], dp[maxn];      // A[i]存放序列，dp[i]存放以A[i]结尾的连续序列的最大和
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}
	// 边界
	dp[0] = A[0];
	for (int i = 1; i < n; i++)
	{
		// 状态转移方程
		dp[i] = max(A[i], dp[i - 1] + A[i]);
	}

	// dp[i]存放以A[i]结尾的连续序列的最大和，需要遍历i得到最大的才是结果
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		if (dp[i] > dp[k])
		{
			k = i;
		}
	}
	printf("%d", dp[k]);
}
