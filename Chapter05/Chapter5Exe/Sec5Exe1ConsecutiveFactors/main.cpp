/*
����һ��������N,��һ��������������ʹ��N �ܱ�������������ĳ˻�����������ж��������
������������������ķ�����������ж��ַ�����������е�һ������С�ķ�����
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