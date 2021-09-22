/*
��һ�����������У��ҵ�һ����������У����Բ���������ʹ������������ǲ��½����ǵݼ����ġ�
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100;
int A[N], dp[N];
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &A[i]);
	}

	int ans = -1;       // ��¼����dp[i]
	for (int i = 1; i <= n; i++)
	{
		// ��˳������dp[i]��ֵ
		dp[i] = 1;  // �߽��ʼ����
		for (int j = 1; j < i; j++)
		{
			if (A[i] >= A[j] && (dp[j] + 1 > dp[i]))
			{
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
}