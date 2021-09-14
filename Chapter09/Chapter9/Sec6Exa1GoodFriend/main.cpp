/*
��һ�����뱦��A�����뱦��B�Ǻ����ѵȼ������뱦��B����
�뱦��A�Ǻ����ѡ�
�ڶ���������뱦��A�����뱦��C�Ǻ����ѣ������뱦��B��
���뱦��CҲ�Ǻ����ѣ���ôA��BҲ�Ǻ����ѡ�
���ڸ�����Щ���뱦�������к����ѵ���Ϣ���ʣ����԰���Щ
���뱦���ֳɶ����飬����ÿ���е�������ֻ���뱦�����Ǻ�
���ѣ�����������֮������뱦�������Ǻ����ѡ�
*/

#include <cstdio>
const int N = 110;
int father[N];			// ��Ÿ��ڵ�
bool isRoot[N];		// ��¼ÿ������Ƿ�ĳ�����ϵĸ��ڵ�

int findFather(int x)
{
	int a = x;
	while (x != father[x])
	{
		x = father[x];
	}
	// ·��ѹ��(�ɲ�д)
	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
		return x;
	}
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
	{
		father[faA] = faB;
	}
}

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		isRoot[i] = false;
	}
}

int main()
{
	int n, m, a, b;
	scanf_s("%d%d", &n, &m);
	init(n);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &a, &b);
		Union(a, b);		// �ϲ�a��b
	}
	for (int i = 1; i <= n; i++)
	{
		isRoot[findFather(i)] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += isRoot[i];
	}
	printf("%d\n", ans);
}