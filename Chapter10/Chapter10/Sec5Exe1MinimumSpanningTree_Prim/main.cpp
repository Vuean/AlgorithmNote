#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXV = 1000;				// 最大顶点数
const int INF = 100000000000;	// 设INF为一个很大的数

int n, m, G[MAXV][MAXV];			// n为顶点数，MAXV为最大顶点数
int d[MAXV];									// 顶点与集合S的最短距离
bool vis[MAXV] = { false };		// 标记数组

// 默认0号为初始点，函数返回最小生成树的边权之和
int prim()
{
	fill(d, d + MAXV, INF);
	d[0] = 0;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int u = -1, MIN = INF;			// u使d[u]最小，MIN存放该最小的d[u]
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}

		// 找不到小于INF的d[u]，则剩下的顶点和集合S不连通
		if (u == -1) return -1;
		vis[u] = true;
		ans += d[u];
		for (int v = 0; v < n; v++)
		{
			// v未被访问&&u能到达v&&以u为中介可以使v离集合S更近
			if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v])
			{
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}

int main()
{
	int u, v, w;
	scanf_s("%d%d", &n, &m);
	fill(G[0], G[0] + MAXV * MAXV, INF);	// 初始化图G
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &u, &v, &w);
		G[u][v] = G[v][u] = w;
	}

	int ans = prim();
	printf_s("%d\n", ans);
	return 0;
}