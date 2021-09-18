#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXV = 100;
const int MAXE = 10010;

// 边集定义部分
struct edge {
	int u, v;		// 边的两个端点编号
	int cost;		// 边权
}E[MAXE];

bool cmp(edge a, edge b)
{
	return a.cost < b.cost;
}

// 并查集部分
int father[MAXV];		// 并查集数组
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

// kruskal部分，返回最小生成树的边权之和，参数n为顶点个数，m为图的边数
int kruskal(int n, int m)
{
	// ans为所求边权之和，Num_Edge为当前生成树的边数
	int ans = 0, Num_Edge = 0;
	for (int i = 0; i < n; i++)
	{
		father[i] = i;			// 并查集初始化
	}

	sort(E, E + m, cmp);
	for (int i = 0; i < m; i++)
	{
		// 查询测试边两个端点所在集合的根结点
		int faU = findFather(E[i].u);
		int faV = findFather(E[i].v);
		if (faU != faV)	// 如果不在一个集合中
		{
			father[faU] = faV;
			ans += E[i].cost;
			Num_Edge++;
			if(Num_Edge == n-1) break;
		}
	}
	if (Num_Edge != n - 1) return -1;
	else return ans;
}

int main()
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
	}
	int ans = kruskal(n, m);
	printf("%d\n", ans);
	return 0;
}