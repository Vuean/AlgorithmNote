/*
�����Բ��룺
����dnΪ��dn = Pn+1 - Pn������pi �ǵ�i����������Ȼ��d1=1�Ҷ���n>1
��dn��ż������ �����Բ��롱 ��Ϊ�����������������Ҳ�Ϊ2����������
�ָ�������������N(< 10^5)������㲻����N ���������������Եĸ�����
*/

/*
˼·��
������֪����������һ����������������˿�����1~ n�ķ�Χ��ö������p, 
���p��p + 2������������ô�������count��1 ��
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
	for (int i = 3; i + 2 <= n; i += 2)	// ֻ��������
	{
		if (isPrime(i) && isPrime(i + 2))
		{
			count++;
		}
	}
	cout << "Count = " << count << endl;
}