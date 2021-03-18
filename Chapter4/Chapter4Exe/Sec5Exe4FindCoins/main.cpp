/*
����n����������һ��������m, ��n���������Ƿ����һ������a��b(a��b)��
ʹ��a + b = m ����������ж�ԣ� ���a��С����һ�ԡ�
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100010];

// left��right��ʼ�ֱ�λ0��n-1��key��Ϊm-a[i]
int Bin(int left, int right, int key)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == key) return mid;
		else if (a[mid] > key) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main()
{
	int i, n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);

	for (i = 0; i < n; i++)
	{
		int pos = Bin(0, n - 1, m - a[i]);
		if (pos != -1 && i != pos)	// �ҵ�
		{
			cout << "a[i] = " << a[i] << "a[pos]" << a[pos] << endl;
			break;
		}
	}
	if (i == n) cout << "No Solution" << endl;
}