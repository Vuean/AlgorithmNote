/*
题意：
给出若干可能有前导零的数字串， 将它们按某个顺序拼接， 使生成的数最小。
*/

#include<iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10010;
string str[maxn];
bool cmp(string a, string b)
{
	return a + b < b + a;	// 如果a+b<b+a，就把a排在前面
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	string ans;
	for (int i = 0; i < n; i++)
	{
		ans += str[i];
	}
	while (ans.size() != 0 && ans[0] == '0')
	{
		ans.erase(ans.begin());	// 去除前导零
	}
	if (ans.size() == 0) cout << "Ans = " << 0 << endl;
	else cout << "Ans = " << ans << endl;
}