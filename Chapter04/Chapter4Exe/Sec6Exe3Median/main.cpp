/*
���⣺���������Ѿ�����������S1��S2,���ȷֱ�ΪN��M,�����Ǻϲ���һ���µĵ���
���к����λ��������Ϊż��ʱΪ��벿�ֵ����һ��������
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

	S1[n] = S2[m] = INF;	// �������е����һ��Ԫ����Ϊint����
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