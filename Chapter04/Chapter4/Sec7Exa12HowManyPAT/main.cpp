/*
字符串APPAPT中包含了两个单词“PAT", 其中第一个PAT是由第二位(P)、第四位(A)
和第六位(T)组成的；第二个PAT是由第三位(P)、第四位(A)和第六位(T)组成的。
现给定字符串，问一共可以形成多少个PAT?
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100010;
const int MOD = 100000007;
char str[MAXN];
int leftNumP[MAXN] = { 0 };

int main()
{
	gets_s(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (i > 0)
		{
			leftNumP[i] = leftNumP[i - 1];
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