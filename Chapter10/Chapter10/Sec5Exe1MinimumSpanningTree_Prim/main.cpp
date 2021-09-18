#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXV = 1000;				// ��󶥵���
const int INF = 100000000000;	// ��INFΪһ���ܴ����

int n, m, G[MAXV][MAXV];			// nΪ��������MAXVΪ��󶥵���
int d[MAXV];									// �����뼯��S����̾���
bool vis[MAXV] = { false };		// �������

// Ĭ��0��Ϊ��ʼ�㣬����������С�������ı�Ȩ֮��
int prim()
{
	fill(d, d + MAXV, INF);
	d[0] = 0;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int u = -1, MIN = INF;			// uʹd[u]��С��MIN��Ÿ���С��d[u]
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}

		// �Ҳ���С��INF��d[u]����ʣ�µĶ���ͼ���S����ͨ
		if (u == -1) return -1;
		vis[u] = true;
		ans += d[u];
		for (int v = 0; v < n; v++)
		{
			// vδ������&&u�ܵ���v&&��uΪ�н����ʹv�뼯��S����
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
	fill(G[0], G[0] + MAXV * MAXV, INF);	// ��ʼ��ͼG
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &u, &v, &w);
		G[u][v] = G[v][u] = w;
	}

	int ans = prim();
	printf_s("%d\n", ans);
	return 0;
}