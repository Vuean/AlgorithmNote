/*
һ������A�д���N��N>0�����������ڲ�����ʹ�����������ǰ���£�
��ÿ������ѭ��������M��M>=0����λ�ã�����A�е�������
��A0,A1����AN-1���任Ϊ��AN-M ���� AN-1 A0 A1����AN-M-1��
�����M����ѭ��������ǰ���M��λ�ã���
�����Ҫ���ǳ����ƶ����ݵĴ��������٣�Ҫ�������ƶ��ķ�����
*/

#include <iostream>
using namespace std;

int gcd(int a, int b)	// �����Լ��
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int a[110];
	int n, m, temp, pos, next;
	// temp Ϊ��ʱ������pos��ŵ�ǰ�����λ��
	// nextΪ��һ��Ҫ�����λ��
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	m = m % n;
	if (m != 0)
	{
		int d = gcd(m, n);
		for (int i = n - m; i < n - m + d; i++)
		{
			temp = a[i];
			pos = i;	// ��¼��ǰҪ�����λ��
			do
			{
				// ������һ��Ҫ�����λ��
				next = (pos - m + n) % n;
				// �����һ��λ�ò��ǳ�ʼ��
				// �����һ��λ�õ�Ԫ�ظ�ֵ����ǰ����λ��
				if (next != 1) a[pos] = a[next];
				else a[pos] = temp;
				pos = next;
			} while (pos != 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}