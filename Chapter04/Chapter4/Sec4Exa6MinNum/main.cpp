/*
题目描述：
给定数字0 ~ 9 各若干个。可以任意顺序排列这些数字， 但必须全部使用。目标是使得最
后得到的数尽可能小。
*/

#include <iostream>
using namespace std;

int main()
{
	int count[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> count[i];
	}

	for (int i = 1; i < 10; i++)
	{
		if (count[i] > 0)
		{
			printf("%d", i);
			count[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			printf("%d", i);
		}
	}
}