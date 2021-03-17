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
int n, p, a[maxn];

// ���ֲ���
// binarySearch������[i+1, n-1]��Χ���ҵ�һ������x������λ��

int binarySearch(int i, long long x)
{
	if (a[n - 1] <= x) return n;	// �����������������x���򷵻�n
	int l = i + 1, r = n - 1, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (a[mid] <= x)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return l;
}

int main()
{
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		// ��a[i+1]~a[n-1]�в��ҵ�һ������a[i]*p������������λ��
		int j = binarySearch(i, (long long) a[i] * p);
		ans = max(ans, j - i);
	}
	cout << "Ans = " << ans;
}