/*
题意：
给出n个正整数和一个正整数m, 问n个数字中是否存在一对数字a和b(a≤b)，
使得a + b = m 成立。如果有多对， 输出a最小的那一对。
*/

/*
注意点：
如果有多组答案，一定要输出最小的那一对（由循环顺序决定）。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn];

void twoPointers(int n, int m)	// n为元素个数，m为所求的和
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		if (a[i] + a[j] == m) break;
		else if (a[i] + a[j] < m) i++;
		else j--;
	}
	if (i < j)	// 有解
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