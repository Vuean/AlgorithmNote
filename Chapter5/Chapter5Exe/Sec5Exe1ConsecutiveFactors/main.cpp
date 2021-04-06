/*
给出一个正整数N,求一段连续的整数，使得N 能被这段连续整数的乘积整除。如果有多个方案，
输出连续整数个数最多的方案；如果还有多种方案，输出其中第一个数最小的方案。
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL n;
	cin >> n;
	LL sqr = (LL)sqrt(1.0 * n);
	LL ansI = 0, ansLen = 0;
	for (LL i = 2; i <= sqr; i++)
	{
		LL temp = 1, j = i;
		while (1) {
			temp *= j;
			if (n % temp != 0)  break;
			if (j - i + 1 > ansLen) {
				ansI = i;
				ansLen = j - i + 1;
			}
			j++;
		}
	}
	if (ansLen == 0) {
		cout << n << endl;
	}
	else {
		cout << ansLen << endl;
		for (LL i = 0; i < ansLen; i++) {
			cout << ansI + i;
			if (i < ansLen - 1) {
				cout << " * ";
			}
		}
	}
}