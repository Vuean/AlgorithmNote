/*
����һ������n(n��2^30)�� ��1~n�����������������1�ĸ�����
*/
#include <iostream>
using namespace std;
int main()
{
	int n, a = 1, ans = 0;
	int left, now, right;
	cin >> n;
	while (n / a != 0)
	{
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if (now == 0) ans += left * a;
		else if (now == 1) ans += left * a + right + 1;
		else ans += (left + 1) * a;
		a *= 10;
	}
	cout << ans << endl;
}