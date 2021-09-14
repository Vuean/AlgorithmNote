/*
���⣺�ַ���APPAPT �а�����������PAT�������е�һ��PAT�ǵڶ�λ(P)��
����λ(A)������λ(T)���ڶ���PAT�ǵ���λ(P)������λ(A)������λ(T)��
�ָ����ַ����� ��һ�������γɶ��ٸ�PAT?
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN]; // �ַ���
int leftNumP[MAXN] = { 0 }; // ÿһλ��ߣ����� P �ĸ���

int main()
{
	gets_s(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (i > 0)
		{
			leftNumP[i] = leftNumP[i - 1]; // �̳���һλ�Ľ��
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