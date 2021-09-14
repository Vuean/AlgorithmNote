/*
题意：字符串APPAPT 中包含了两个“PAT”，其中第一个PAT是第二位(P)，
第四位(A)，第六位(T)；第二个PAT是第三位(P)，第四位(A)，第六位(T)。
现给定字符串， 问一共可以形成多少个PAT?
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN]; // 字符串
int leftNumP[MAXN] = { 0 }; // 每一位左边（含） P 的个数

int main()
{
	gets_s(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (i > 0)
		{
			leftNumP[i] = leftNumP[i - 1]; // 继承上一位的结果
		}
		if (str[i] == 'P')
		{
			leftNumP[i]++;
		}
	}

	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (str[i] == 'T')
		{
			rightNumT++;
		}
		else if (str[i] == 'A')
		{
			ans = (ans + leftNumP[i] * rightNumT) % MOD;
		}
	}
	cout << "Ans = " << ans;
}