/*
����������N�ͽ���radix�����N����������N��radix�����·�ת�����
��ʮ������Ҳ���������������Yes"; �������"No����
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

// ����ת������ת
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
		if (n < 0) break;	// ��n �Ǹ���ʱ�� �˳�ѭ��
		cin >> radix;
		if (!isPrime(n)) {
			cout << "No" << endl;
		}
		else {
			int len = 0;
			// ����ת��
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