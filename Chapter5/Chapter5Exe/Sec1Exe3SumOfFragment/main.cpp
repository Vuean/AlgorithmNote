/*
数列的片段和:
给定一个正数数列，可以从中截取任意的连续的几个数，称为“片段“。
例如，给定数列{0.1, 0.2, 0.3, 0.4}，则有(0.1)、（0.1,0.2)、
（0.1,0.2, 0.3)、（0.1,0.2, 0.3, 0.4)、(0.2)、（0.2,0.3)、
(0.2, 0.3, 0.4)、（0.3)、(0.3,0.4)及(0.4) 这10 个片段。
给定正整数数列，求出全部片段包含的所有数之和。
如本例中10 个片段总和是0.1 + 0.3+ 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0 。
*/

/*
思路：
如果当前是第i个数，那么其总出现次数等于i*(n + 1 - i) 。
因此只要遍历i，然后累计总出现次数即可。
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	double v, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		ans += v * i * (n + 1 - i);
	}
	cout << "Ans = " << ans << endl;
}