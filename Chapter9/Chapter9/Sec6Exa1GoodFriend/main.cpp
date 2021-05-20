/*
第一，数码宝贝A和数码宝贝B是好朋友等价于数码宝贝B和数
码宝贝A是好朋友。
第二，如果数码宝贝A和数码宝贝C是好朋友，而数码宝贝B和
数码宝贝C也是好朋友，那么A和B也是好朋友。
现在给出这些数码宝贝中所有好朋友的信息，问：可以把这些
数码宝贝分成多少组，满足每组中的任意两只数码宝贝都是好
朋友，且任意两组之间的数码宝贝都不是好朋友。
*/

#include <cstdio>
const int N = 110;
int father[N];			// 存放父节点
bool isRoot[N];		// 记录每个结点是否某个集合的根节点

int findFather(int x)
{
	int a = x;
	while (x != father[x])
	{
		x = father[x];
	}
	// 路径压缩(可不写)
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
		Union(a, b);		// 合并a和b
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