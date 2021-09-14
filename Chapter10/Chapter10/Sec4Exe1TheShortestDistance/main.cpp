#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 1000;			// 最大顶点数
const int INF = 100000000;	// 极大值

int n, m, s, G[MAXV][MAXV];	// n为顶点数，m为边数，s为起点
int d[MAXV];								// 起点到达各点的最短路径长度
bool vis[MAXV] = { false };	// 标记数组

void Dijkstra(int s)
{
	fill(d, d + MAXV, INF);
	d[s] = 0;		// 起点s到达自身的距离为0
	for (int i = 0; i < n; i++)
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}

		// 找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
		if (u == -1) return;

		vis[u] = true;			// 标记u为己访问
		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
			{
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

int main()
{
	int u, v, w;
	scanf_s("%d%d%d", &n, &m, &s);	// 顶点个数、边数、起点编号
	fill(G[0], G[0] + MAXV * MAXV, INF);	// 初始化图G
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &u, &v, &w);	// 输入u，v及u->v的边权
		G[u][v] = w;
	}

	Dijkstra(s);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", d[i]);
	}
}