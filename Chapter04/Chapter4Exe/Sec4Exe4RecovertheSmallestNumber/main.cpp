/*
���⣺
�������ɿ�����ǰ��������ִ��� �����ǰ�ĳ��˳��ƴ�ӣ� ʹ���ɵ�����С��
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
	return a + b < b + a;	// ���a+b<b+a���Ͱ�a����ǰ��
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
		ans.erase(ans.begin());	// ȥ��ǰ����
	}
	if (ans.size() == 0) cout << "Ans = " << 0 << endl;
	else cout << "Ans = " << ans << endl;
}