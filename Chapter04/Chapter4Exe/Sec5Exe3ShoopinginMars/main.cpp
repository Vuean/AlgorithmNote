/*
���⣺
����һ������������һ����s, ������������������к�ֵΪS�����������У�������
����˵�С�����������˵���ͬʱ�Ҷ˵�С�������������û�����������У������ֵǡ��
����S�������У��������к�ֵ����S���������к�ֵ��ӽ�S)�����������±��1 ��ʼ��
*/

/*
���ǵ���ĿҪ��������з����� �����Ҫ�����н������α����� ���е�һ�α��������
�ڵ���S����ӽ�S�ĺ�ֵnearS; �ڶ��α����ҵ���Щ��ֵǡ��ΪnearS�ķ���������� ��
���Ӷ�ΪO(nlogn)��
*/

/*
ע��㣺
1. ʹ��cin��cout���ܳ�ʱ����ʹ��scanf��printf
*/
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;

// uppert_bound����������[L, R)�ڵ�һ������x��λ��
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
	// ö�ٶ˵�
	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + S);
		if (sum[j - 1] - sum[i - 1] == S)	// ���ҳɹ���ע����j-1��������j
		{
			nearS = S;	// ��ӽ�S��ֵ����S
			break;
		}
		else if (j <= n && sum[j] - sum[i - 1] < nearS)
		{
			// ���ڴ���S�Ľ⣬��С��nearS
			nearS = sum[j] - sum[i - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);	// ���Ҷ˵�
		if (sum[j - 1] - sum[i - 1] == nearS)
		{
			printf("%d-%d\n", i, j - 1);
		}
	}
}