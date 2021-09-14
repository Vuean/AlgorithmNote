/*
给出一个数字n(n≤2^30)， 求1~n的所有数字里面出现1的个数。
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