/*
给定任一个各位数字不完全相同的四位正整数，如果先把四个数字按非递增排序，
再按非递减排序，然后用第一个数字减第二个数字，将得到一个新的数字。
一直重复这样做，很快会停在有“数字黑洞”之称的6174, 这个神奇的数字也叫Kaprekar 常数。
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)	// 递减排序cmp
{
	return a > b;
}

void to_array(int n, int num[])	// 将n 的每一位存到num 数组中
{
	for (int i = 0; i < 4; i++)
	{
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[])	// 将num 数组转换为数字
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
		sort(num, num + 4);
		MIN = to_number(num);
		sort(num, num + 4, cmp);
		MAX = to_number(num);
		n = MAX - MIN;
		// cout << MAX << " - " << MIN << " = " << n << endl;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if (n == 0 || n == 6174) break;
	}
}