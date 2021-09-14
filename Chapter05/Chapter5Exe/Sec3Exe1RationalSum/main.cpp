/*
给出n 个分数，求分数的和。分数前面可能有负号。
若答案为假分数，则要按照带分数的形式输出；
整数则按整数输出；否则按真分数输出。
*/

/*
注意点：
1. 数据范围为int , 因此两个分母相乘时， 最大可以达到long long
2. 必须在每一步加法后都进行约分，如果等全部加完后才约分，则会溢出。
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

struct Fraction
{
	ll up, down;
};

Fraction reduction(Fraction result)
{
	if (result.down < 0)
	{
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0)
	{
		result.down = 1;
	}
	else
	{
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

Fraction add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down + f1.down * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

void showResult(Fraction r)
{
	reduction(r);
	if (r.down == 1) printf("%lld\n", r.up);
	else if (abs(r.up) > r.down)
	{
		printf("%lld %lld/%lld\n", r.up / r.down, abs(r.up) % r.down, r.down);
	}
	else
	{
		printf("%lld/%lld\n", r.up, r.down);
	}
}

int main()
{
	int n;
	cin >> n;
	Fraction sum, temp;
	sum.up = 0; sum.down = 1;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	showResult(sum);
}