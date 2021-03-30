#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)	// 递减排序
{
	return a > b;
}

void to_array(int n, int num[])	// 将n 的每一位存到num数组中
{
	for (int i = 0; i < 4; i++)
	{
		num[i] = n % 10;
		n /= 10;
	}
}

int to_num(int num[])
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum = sum * 10 + num[i];
	}
	return sum;
}

int main()
{
	int n, MIN, MAX;
	cin >> n;
	int num[5];
	while (1)
	{
		to_array(n, num);
		sort(num, num + 4);	// 从小到大排序
		MIN = to_num(num);
		sort(num, num + 4, cmp);
		MAX = to_num(num);
		n = MAX - MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if (n == 0 || n == 6174) break;
	}
}