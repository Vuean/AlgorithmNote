/*
��Ŀ������
�����Ŀ��������㷨����һ������Ļ��ֹ��̣�ͨ������ĳ�ַ���ȡһ��Ԫ����Ϊ��Ԫ��
ͨ���������ѱ���ԪС��Ԫ�طŵ�����ߣ��ѱ���Ԫ���Ԫ�طŵ����ұߡ��������ֺ��N
��������ͬ�������������У������ж��ٸ����ؿ����ǻ���ǰѡȡ����Ԫ��
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3fffffff; // `һ���ܴ����

// aΪ���У�leftMax��rightmin�ֱ�Ϊ������������ұ���С����
int a[MAXN], leftMax[MAXN], rightMin[MAXN];
// ans��¼������Ԫ��numΪ��Ԫ����
int ans[MAXN], num = 0;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	leftMax[0] = 0;
	for (int i = 1; i < n; i++)
	{
		leftMax[i] = max(leftMax[i - 1], a[i-1]);
	}
	rightMin[n - 1] = INF;	// A[n-1]�ұ�û�б���С����
	for (int i = n - 2; i >= 0; i--)
	{
		rightMin[i] = min(rightMin[i + 1], a[i + 1]);
	}
	for (int i = 0; i < n; i++)
	{
		if (leftMax[i] < a[i] && rightMin[i] > a[i])
		{
			ans[num++] = a[i];	// ��¼��Ԫ
		}
	}
	cout << "NUM = " << num << endl;
	for (int i = 0; i < num; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}