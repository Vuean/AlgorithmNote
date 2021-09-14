// 方法一：暴力法

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int maxn = 100001;
bool isPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int Prime[maxn], num = 0;
bool p[maxn] = { 0 };

// n为个数
void Find_Prime(int n)
{
	for (int i = 1; i < maxn; i++)
	{
		if (isPrime(i))
		{
			Prime[num++] = i;
			p[i] = true;
			if (num >= n) break;
		}
	}
}

// 筛选法
void Find_Prime2(int n)
{
	for (int i = 2; i < maxn; i++)
	{
		if (p[i] == false)
		{
			Prime[num++] = i;
			if (num >= n) break;
			for (int j = i + i; j < maxn; j += i)
			{
				p[j] = true;
			}
		}
	}
}

int main()
{
	int m, n, count = 0;
	cin >> m >> n;
	Find_Prime2(n);
	for (int i = m; i <= n; i++)
	{
		cout << Prime[i - 1];
		count++;
		if (count % 10 != 0 && i < n) cout << " ";
		else cout << endl;
	}
}