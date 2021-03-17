/*
题目描述：
给定一个正整数数列和正整数p，设这个数列中的最大值是M，最小值是m，
如果M≤m*p，则这个数列是“完美数列”。
现在给定参数p和一些正整数，请你从中选择尽可能多的数以构成一个“完美数列”
*/

/*
输入格式：
输入第一行给出两个正整数N和p，其中N是输入正整数的个数，
p是给定的参数。第二行给出N个正整数。
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n, p, a[maxn];

// 二分查找
// binarySearch函数在[i+1, n-1]范围内找第一个大于x的数的位置

int binarySearch(int i, long long x)
{
	if (a[n - 1] <= x) return n;	// 如果所有数都不大于x，则返回n
	int l = i + 1, r = n - 1, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (a[mid] <= x)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return l;
}

int main()
{
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		// 在a[i+1]~a[n-1]中查找第一个超过a[i]*p的数，返回其位置
		int j = binarySearch(i, (long long) a[i] * p);
		ans = max(ans, j - i);
	}
	cout << "Ans = " << ans;
}