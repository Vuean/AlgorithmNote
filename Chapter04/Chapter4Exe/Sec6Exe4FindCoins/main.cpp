/*
���⣺
����n����������һ��������m, ��n���������Ƿ����һ������a��b(a��b)��
ʹ��a + b = m ����������ж�ԣ� ���a��С����һ�ԡ�
*/

/*
ע��㣺
����ж���𰸣�һ��Ҫ�����С����һ�ԣ���ѭ��˳���������
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn];

void twoPointers(int n, int m)	// nΪԪ�ظ�����mΪ����ĺ�
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		if (a[i] + a[j] == m) break;
		else if (a[i] + a[j] < m) i++;
		else j--;
	}
	if (i < j)	// �н�
	{
		cout << a[i] << " + " << a[j] << endl;
	}
	else
	{
		cout << "No Solution" << endl;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	twoPointers(n, m);
}