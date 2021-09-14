/*
�ַ���APPAPT�а������������ʡ�PAT", ���е�һ��PAT���ɵڶ�λ(P)������λ(A)
�͵���λ(T)��ɵģ��ڶ���PAT���ɵ���λ(P)������λ(A)�͵���λ(T)��ɵġ�
�ָ����ַ�������һ�������γɶ��ٸ�PAT?
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