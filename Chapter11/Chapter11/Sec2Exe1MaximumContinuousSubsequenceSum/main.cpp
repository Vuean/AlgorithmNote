/*
������������к��������£�����һ����������A1��A2��...��An����i��j(1��i��j��n)��ʹ��Ai+...+Aj������������͡�
*/

#include<cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int A[maxn], dp[maxn];      // A[i]������У�dp[i]�����A[i]��β���������е�����
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}
	// �߽�
	dp[0] = A[0];
	for (int i = 1; i < n; i++)
	{
		// ״̬ת�Ʒ���
		dp[i] = max(A[i], dp[i - 1] + A[i]);
	}

	// dp[i]�����A[i]��β���������е����ͣ���Ҫ����i�õ����Ĳ��ǽ��
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
