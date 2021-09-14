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
int main()
{
	int n, p, a[maxn];
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);		// 从小到大排序
	int i = 0, j = 0, count = 1;
	while (i < n && j < n)
	{
		while (j < n && a[j] <= (long long)a[i] * p)
		{
			count = max(count, j - i + 1);
			j++;
		}
		i++;
	}
	cout << "Ans = " << count;
}