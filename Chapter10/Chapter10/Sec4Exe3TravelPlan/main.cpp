/*
��N ���У����ΪO ~ N-1) ��M����·������ߣ���������M����·�ľ��������뻨�����ԡ�
���ڸ������S���յ�D, �����㵽�յ�����·������̾��뼰���ѡ�ע�⣺
����ж������·���� ��ѡ�񻨷���С��������
*/
/*
#pragma region Dijkstra�㷨
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;

// nΪ��������mΪ������ st��ed�ֱ�Ϊ�����յ�
// GΪ�������costΪ���Ѿ���
// d[]��¼��̾��룬c[]��¼��С����
int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], c[MAXV], pre[MAXV];
bool vis[MAXV] = { false };

void Dijkstra(int s)
{
	fill(d, d + MAXV, INF);
	fill(c, c + MAXV, INF);
	for (int i = 0; i < n; i++)
	{
		pre[i] = i;
	}
	d[s] = 0;			// ���s��������ľ���Ϊ0
	c[s] = 0;			// ���s��������Ļ���Ϊ0
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

		// �Ҳ���С��INF��d[u]��˵��ʣ�µ�������㲻��ͨ
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != INF)
			{
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
				}
				else if (d[u] + G[u][v] == d[v])
				{
					if (c[u] + cost[u][v] < c[v])
					{
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}

void DFS(int v)
{
	if (v == st)
	{
		printf_s("%d ", v);
		return;
	}
	DFS(pre[v]);
	printf_s("%d ", v);
}

int main()
{
	scanf_s("%d%d%d%d", &n, &m, &st, &ed);
	int u, v;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &u, &v);
		scanf_s("%d%d", &G[u][v], &cost[u][v]);
		G[u][v] = G[v][u];
		cost[u] [v] = cost[v][u];
	}
	Dijkstra(st);
	DFS(ed);
	printf_s("%d %d\n", d[ed], c[ed]);
}
#pragma endregion
*/


#pragma region Dijkstra+DFS�㷨
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;

// nΪ��������mΪ������ st��ed�ֱ�Ϊ�����յ�
// GΪ�������costΪ���Ѿ���
// d[]��¼��̾��룬c[]��¼��С����

int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], minCost = INF;
bool vis[MAXV] = { false };
vector<int> pre[MAXV];				// ǰ��
vector<int> tempPath, path;	// ��ʱ·��������·��
void Dijkstra(int s)
{
	fill(d, d + MAXV, INF);
	d[s] = 0;
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

		// �Ҳ���С��INF��d[u]��˵��ʣ�µ�������㲻��ͨ
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++)
		{
			// ���vδ����&&u�ܵ���v
			if (vis[v] == false && G[u][v] != INF)
			{
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = G[u][v] + d[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v)
{
	if (v == st)
	{
		tempPath.push_back(v);
		int tempCost = 0;
		for (int i = tempPath.size() - 1; i > 0; i--)
		{
			int id = tempPath[i], idNext = tempPath[i - 1];
			tempCost += cost[id][idNext];
		}
		if (tempCost < minCost)
		{
			minCost = tempCost;
			path = tempPath;
		}
		tempPath.push_back(v);
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

int main()
{
	scanf_s("%d%d%d%d", &n, &m, &st, &ed);
	int u, v;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	fill(cost[0], cost[0] + MAXV * MAXV, INF);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &u, &v);
		scanf_s("%d%d", &G[u][v], &cost[u][v]);
		G[u][v] = G[v][u];
		cost[u][v] = cost[v][u];
	}
	Dijkstra(st);
	DFS(ed);
	for (int i = 0; i < path.size(); i++)
	{
		printf_s("%d ", path[i]);
	}
	printf_s("%d %d\n", d[ed], minCost);
}
#pragma endregion
