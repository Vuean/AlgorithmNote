/*
题意:
给出两个集合， 从这两个集合中分别选取相同数量的元素进行一对一相乘， 问能得到的
乘积之和最大是多少。
*/
#include<iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int coupon[maxn], product[maxn];

int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> coupon[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> product[i];
	}

	// 从小到大排序
	sort(coupon, coupon + n);
	sort(product, product + m);

	int i = 0, j, ans = 0;
	while (i < n && i < m && coupon[i] < 0 && product[i] < 0)
	{
		ans += coupon[i] * product[i];
		i++;
	}
	i = n - 1;
	j = m - 1;
	while (i >= 0 && j >= 0 && coupon[i] > 0 && product[i] > 0)
	{
		ans += coupon[i] * product[i];
		i--;
		j--;
	}
	cout << "Ans = " << ans << endl;
}