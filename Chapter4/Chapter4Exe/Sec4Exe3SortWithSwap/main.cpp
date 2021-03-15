/*
题意：
给出0, 1, … , N-1 的一个序列， 要求通过两两交换的方式将其变为递增序列， 但是规定
每次只能用0与其他数进行交换。求最小交换次数。
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int pos[maxn];	// 存放各数字当前所处的位置编号

int main()
{
	int n, ans = 0;
	cin >> n;

	int left = n - 1, num;	// left存放除0以外不在本位上的数的个数
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		pos[num] = i;	// num所处的位置为i；
		if (num == i && num != 0)
			left--;
	}

	int k = 1;	// k存放除0以外当前不在本位上的最小数
	while (left > 0)
	{
		// 如果0在本位上，则寻找一个当前不在本位上的数与0交换
		if (pos[0] == 0)
		{
			while (k < n)
			{
				if (pos[k] != k)	// 找到一个当前不在本位上的数
				{
					swap(pos[0], pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		// 只要0不在本位，就将0所在位置的数的当前所处位置与0的位置交换
		while (pos[0] != 0)
		{
			swap(pos[0], pos[pos[0]]);	// 将0与pos[0]交换
			ans++;
			left--;
		}
	}
	cout << "Ans = " << ans;
}