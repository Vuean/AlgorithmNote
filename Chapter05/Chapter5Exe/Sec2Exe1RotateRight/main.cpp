/*
一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，
将每个整数循环向右移M（M>=0）个位置，即将A中的数据由
（A0,A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-1）
（最后M个数循环移至最前面的M个位置）。
如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
*/

#include <iostream>
using namespace std;

int gcd(int a, int b)	// 求最大公约数
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int a[110];
	int n, m, temp, pos, next;
	// temp 为临时变量，pos存放当前处理的位置
	// next为下一个要处理的位置
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	m = m % n;
	if (m != 0)
	{
		int d = gcd(m, n);
		for (int i = n - m; i < n - m + d; i++)
		{
			temp = a[i];
			pos = i;	// 记录当前要处理的位置
			do
			{
				// 计算下一个要处理的位置
				next = (pos - m + n) % n;
				// 如果下一个位置不是初始点
				// 则把下一个位置的元素赋值给当前处理位置
				if (next != 1) a[pos] = a[next];
				else a[pos] = temp;
				pos = next;
			} while (pos != 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}