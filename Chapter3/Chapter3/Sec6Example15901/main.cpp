#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 256;

// �ж��ַ���str�Ƿ��ǻ��Ĵ�
bool judge(char str[])
{
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
			return false;
		return true;
	}
}

int main()
{
	char str[maxn];
	cin >> str;
	bool flag = judge(str);
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}