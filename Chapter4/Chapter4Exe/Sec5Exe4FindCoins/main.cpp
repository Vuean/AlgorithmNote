/*
给出n个正整数和一个正整数m, 问n个数字中是否存在一对数字a和b(a≤b)，
使得a + b = m 成立。如果有多对， 输出a最小的那一对。
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100010];

// left和right初始分别位0和n-1，key即为m-a[i]
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
		if (pos != -1 && i != pos)	// 找到
		{
			cout << "a[i] = " << a[i] << "a[pos]" << a[pos] << endl;
			break;
		}
	}
	if (i == n) cout << "No Solution" << endl;
}