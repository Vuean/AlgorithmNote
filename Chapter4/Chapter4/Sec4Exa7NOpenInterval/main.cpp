// N����������

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 110;
struct Interval
{
	int x, y;	// ���������ҹյ�
} I[maxn];

bool cmp(Interval a, Interval b)
{
	if (a.x != b.x) return a.x > b.x;	// �Ȱ���˵�Ӵ�С����
	else return a.y < b.y;	// ��˵���ͬ�İ��Ҷ˵��С��������
}

int main()
{
	int n;
	while (scanf_s("%d", &n), n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d%d", &I[i].x, &I[i].y);
		}
		sort(I, I + n, cmp);	// ����������
		// ans��¼���ཻ������lastX��¼��һ����ѡ���������˵�
		int ans = 1, lastX = I[0].x;
		for (int i = 1; i < n; i++)
		{
			if (I[i].y <= lastX)	// ����������Ҷ˵���lastX���
			{
				lastX = I[i].x;	// ��I[i]��Ϊ��ѡ�е�����
				ans++;	// ���ཻ���������1
			}
		}
		printf("%d\n", ans);
	}
}