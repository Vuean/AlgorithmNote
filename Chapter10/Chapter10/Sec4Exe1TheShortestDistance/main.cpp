#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 1000;			// ��󶥵���
const int INF = 100000000;	// ����ֵ

int n, m, s, G[MAXV][MAXV];	// nΪ��������mΪ������sΪ���
int d[MAXV];								// ��㵽���������·������
bool vis[MAXV] = { false };	// �������

void Dijkstra(int s)
{
	fill(d, d + MAXV, INF);
	d[s] = 0;		// ���s��������ľ���Ϊ0
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

		// �Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		if (u == -1) return;

		vis[u] = true;			// ���uΪ������
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
	scanf_s("%d%d%d", &n, &m, &s);	// ��������������������
	fill(G[0], G[0] + MAXV * MAXV, INF);	// ��ʼ��ͼG
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &u, &v, &w);	// ����u��v��u->v�ı�Ȩ
		G[u][v] = w;
	}

	Dijkstra(s);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", d[i]);
	}
}