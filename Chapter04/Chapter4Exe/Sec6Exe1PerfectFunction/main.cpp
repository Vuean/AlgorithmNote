/*
��Ŀ������
����һ�����������к�������p������������е����ֵ��M����Сֵ��m��
���M��m*p������������ǡ��������С���
���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ�����Թ���һ�����������С�
*/

/*
�����ʽ��
�����һ�и�������������N��p������N�������������ĸ�����
p�Ǹ����Ĳ������ڶ��и���N����������
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int main()
{
	int n, p, a[maxn];
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);		// ��С��������
	int i = 0, j = 0, count = 1;
	while (i < n && j < n)
	{
		while (j < n && a[j] <= (long long)a[i] * p)
		{
			count = max(count, j - i + 1);
			j++;
		}
		i++;
	}
	cout << "Ans = " << count;
}