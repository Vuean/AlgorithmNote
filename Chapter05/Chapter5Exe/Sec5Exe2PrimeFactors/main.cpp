/*
给出一个int 范围的整数， 按照从小到大的顺序输出其分解为质因数的乘法算式。
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100010;

bool isPrime(int n) {
	if (n == 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i < sqr; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int prime[maxn], pNum = 0;

void findPrime() {
	for (int i = 1; i < maxn; i++) {
		if (isPrime(i)) {
			prime[pNum++] = i;
		}
	}
}

struct factor {
	int x, cnt;
}fac[10];

int main()
{
	findPrime();
	int n, num = 0;
	cin >> n;
	if (n == 1) cout << "1 = 1";
	else {
		cout << n << " = ";
		int sqr = (int)sqrt(n);
		for (int i = 0; i < pNum && prime[i] <= sqr; i++) {
			if (n % prime[i] == 0) {
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while (n % prime[i] == 0) {
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			if (n == 1) break;
		}
		if (n != 1) {
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		for (int i = 0; i < num; i++) {
			if (i > 0) cout << " * ";
			cout << fac[i].x;
			if (fac[i].cnt > 1) {
				cout << "^" << fac[i].cnt;
			}
		}
	}
}