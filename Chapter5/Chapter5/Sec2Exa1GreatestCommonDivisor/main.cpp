/*
�����������������������Լ����
*/

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << "Ans = " << gcd(m, n);
	}
}