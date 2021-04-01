/*
令Pi表示第i个素数， 现任意给两个正整数M≤N≤ 10^4, 
请输出PM 到PN的所有素数。
*/

#include <iostream>
using namespace std;

const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = { 0 };
void find_prime(int n)
{
	for (int i = 2; i < maxn; i++)
	{
		if (p[i] == false)
		{
			prime[num++] = i;
			if (num >= n) break;	// 只需要n个素数
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
	find_prime(n);
	for (int i = m; i <= n; i++)
	{
		cout << prime[i - 1];
		count++;
		if (count % 10 != 0 && i < n) cout << " ";
		else cout << endl;
	}
}