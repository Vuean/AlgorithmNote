/*
给出散列表长TSize和欲插入的元素，将这些元素按读入的顺序插入散列表中，
其中散列函数为H(key) = key % TSize，解决冲突采用只往正向增加的
二次探查法（即二次方探查法）。另外，如果题目给出的TSize不是素数，
那么需要将TSize重新赋值为第一个比TSize大的素数再进行元素插入。
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 11111;

bool IsPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i < sqr; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

bool HashTable[MAXN] = { 0 };	// 为false则i位未被使用号

int main()
{
	int N, TSize, a;
	cin >> TSize >> N;
	while (!IsPrime(TSize))
	{
		TSize++;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		int M = a % TSize;
		if (!HashTable[M])	// M号位未被使用，则已找到
		{
			HashTable[M] = true;
			if (i == 0) cout << M;
			else cout << " " << M;
		}
		else
		{
			int step;	// 二次方探查法
			for (step = 1; step < TSize; step++)
			{
				M = (a + step * step) % TSize;
				if (!HashTable[M])
				{
					HashTable[M] = true;
					if (i == 0) cout << M;
					else cout << " " << M;
					break;
				}
			}
			if (step >= TSize)	// 找不到插入的地方
			{
				if (i > 0) cout << " ";
				cout << "-";
			}
		}
	}

}