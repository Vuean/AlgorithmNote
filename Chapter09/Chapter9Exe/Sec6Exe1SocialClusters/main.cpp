/*
有N 个人，每个人喜欢若干项活动，如果两个人有任意一个活
动相同，那么就称他们处于同一个社交网络（若A和B属于同一
个社交网络，B和C属于同一个社交网络，那么A、B、C属于同
一个社交网络）。求这N个人总共形成了多少个社交网络。
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int father[N];				// 存放父亲节点
int isRoot[N] = { 0 };	// 记录每个结点是否作为某个集合的根结点
int course[N] = { 0 };
int findFather(int x)
{
	int a = x;
	while (x != father[x])
	{
		x = father[x];
	}
	// 路径压缩
	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
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

// 将isRoot数组从大到小排序
bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n, k, h;
	scanf_s("%d", &n);	// 人数
	init(n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d:", &k);	// 活动个数
		for (int j = 0; j < k; j++)
		{
			scanf_s("%d", &h);
			if (course[h] == 0)	// 如果活动h第一次有人喜欢
			{
				course[h] = i;
			}
			Union(i, findFather(course[h]));
		}
	}

	for (int i = 1; i <= n; i++)
	{
		isRoot[findFather(i)]++;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isRoot[i] != 0)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	sort(isRoot+1, isRoot + n+1, cmp);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", isRoot[i]);
		if (i < ans) printf(" ");
	}
}