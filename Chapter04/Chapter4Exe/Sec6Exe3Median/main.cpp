/*
题意：给出两个已经递增的序列S1和S2,长度分别为N和M,求将它们合并成一个新的递增
序列后的中位数（个数为偶数时为左半部分的最后一个数）。
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1000010;
const int INF = 0x7fffffff;
int S1[maxn], S2[maxn];

int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> S1[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> S2[i];
	}

	S1[n] = S2[m] = INF;	// 两个序列的最后一个元素设为int上限
	int medianindex = (n + m - 1) / 2;

	int i = 0, j = 0, count = 0;
	while (count < medianindex)
	{
		if (S1[i] < S2[j]) i++;
		else j++;
		count++;
	}

	if (S1[i] < S2[j])
	{
		cout << "Ans = " << S1[i];
	}
	else
	{
		cout << "Ans = " << S2[j];
	}
}