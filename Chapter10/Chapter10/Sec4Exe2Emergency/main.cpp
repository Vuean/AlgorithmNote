/*
����N�����У�M������ߡ�ÿ�������ж���һ����Ŀ�ľ�ԮС�飬���бߵı�Ȩ��֪��
���ڸ��������յ㣬�����㵽�յ�����·�����������·���ϵľ�ԮС����Ŀ֮�͡�
����ж������·�����������Ŀ֮�����ġ�
*/

#include <cstdio>
#include <string>
#include <algorithm>
using  namespace std;

const int MAXV = 510;					// ��󶥵���
const int INF = 1000000000;		// �����

// nΪ��������mΪ������st��ed�ֱ�Ϊ�����յ�
// GΪ�ڽӾ���weightΪ��Ȩ
// d[]��¼��̾��룬w[]��¼����Ȩ֮�ͣ�num[]��¼���·������

int n, m, st, ed, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], w[MAXV], num[MAXV];
bool vis[MAXV] = { false };

void Dijkstra(int s)
{
	fill(d, d + MAXV, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = -1;

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
		vis[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != INF)
			{
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if (d[u] + G[u][v] == d[v])
				{
					if (w[u] + weight[v] > w[v])
					{
						w[v] = w[u] + weight[v];
					}
					// ���·���������Ȩ�޹أ�����д������
					num[v] += num[u];
				}
			}
		}
	}
}


int main()
{
	scanf_s("%d%d%d%d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &weight[i]);
	}

	int u, v;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &u, &v);
		scanf_s("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}

	Dijkstra(st);
	printf("%d %d\n", num[ed], w[ed]);
}