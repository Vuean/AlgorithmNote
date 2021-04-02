/*
给出正整数N和进制radix，如果N是素数，且N在radix进制下反转后的数
在十进制下也是素数，则输出“Yes"; 否则输出"No”。
*/

#include <iostream>
#include <cmath>
using namespace std;

int d[111];

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

// 进制转换并倒转
void TranseReverse(int& n, int radix)
{
	int len = 0;
	while (n != 0)
	{
		d[len++] = n % radix;
		n /= radix;
	}
	for (int i = 0; i < len; i++)
	{
		n = n * radix + d[i];
	}
}

int main()
{
	int n, radix;
	while (scanf_s("%d", &n) != EOF)
	{
		if (n < 0) break;	// 当n 是负数时， 退出循环
		cin >> radix;
		if (!isPrime(n)) {
			cout << "No" << endl;
		}
		else {
			int len = 0;
			// 进制转换
			do {
				d[len++] = n % radix;
				n /= radix;
			} while (n != 0);
			for (int i = 0; i < len; i++)
			{
				n = n * radix + d[i];
			}
			// TranseReverse(n, radix);
			if (isPrime(n)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}