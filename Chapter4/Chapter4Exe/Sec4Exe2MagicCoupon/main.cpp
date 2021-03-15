/*
����:
�����������ϣ� �������������зֱ�ѡȡ��ͬ������Ԫ�ؽ���һ��һ��ˣ� ���ܵõ���
�˻�֮������Ƕ��١�
*/
#include<iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int coupon[maxn], product[maxn];

int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> coupon[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> product[i];
	}

	// ��С��������
	sort(coupon, coupon + n);
	sort(product, product + m);

	int i = 0, j, ans = 0;
	while (i < n && i < m && coupon[i] < 0 && product[i] < 0)
	{
		ans += coupon[i] * product[i];
		i++;
	}
	i = n - 1;
	j = m - 1;
	while (i >= 0 && j >= 0 && coupon[i] > 0 && product[i] > 0)
	{
		ans += coupon[i] * product[i];
		i--;
		j--;
	}
	cout << "Ans = " << ans << endl;
}