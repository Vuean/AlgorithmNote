/*
素数对猜想：
定义dn为：dn = Pn+1 - Pn，其中pi 是第i个素数。显然有d1=1且对于n>1
有dn是偶数。“ 素数对猜想” 认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N(< 10^5)，请计算不超过N 的满足猜想的素数对的个数。
*/

/*
思路：
很容易知道，素数对一定是两个奇数。因此可以在1~ n的范围内枚举奇数p, 
如果p和p + 2都是素数，那么令计数器count加1 。
*/

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	int n, count = 0;
	cin >> n;
	for (int i = 3; i + 2 <= n; i += 2)	// 只考虑奇数
	{
		if (isPrime(i) && isPrime(i + 2))
		{
			count++;
		}
	}
	cout << "Count = " << count << endl;
}