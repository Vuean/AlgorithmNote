/*
����һ������ ��ÿһ����ж���Ҷ�ӽ�㡣
*/

/*
������Ŀ��������һ�����ʵ����� ��˿���ʹ���ڽӱ����洢��
��ʱ���ı���һ��ʹ�����ַ���ʵ�֣� ������������͹������������
*/

# define DFS_FUNCTION 0;
// # define BFS_FUNCTION 0;

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 105;

vector<int> G[N];			// �����
int h[N] = { 0 };				// ����������Ĳ�ţ� ��1 ��ʼ
int leaf[N] = { 0 };			// ���ÿ���Ҷ�ӽ�����
int max_h = 1;					// �������

void DFS(int index, int h)
{
	// index Ϊ��ǰ�������Ľ���ţ� h Ϊ��ǰ���
	max_h = max(h, max_h);
	if (G[index].size() == 0)	// ����ý����Ҷ�ӽ��
	{
		leaf[h]++;
		return;
	}
	for (int i = 0; i < G[index].size(); i++)
	{
		DFS(G[index][i], h + 1);
	}
}

void BFS()
{
	queue<int> Q;
	Q.push(1);		// �������ѹ�����
	while (!Q.empty())
	{
		int id = Q.front();
		Q.pop();
		max_h = max(max_h, h[id]);
		if (G[id].size() == 0)// ����ý����Ҷ�ӽ��
		{
			leaf[h[id]]++;
		}

		for (int i = 0; i < G[id].size(); i++)
		{
			h[G[id][i]] = h[id] + 1;
			Q.push(G[id][i]);
		}
	}
}

int main()
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	int parent, child, k;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &parent, &k);
		for (int j = 0; j < k; j++)
		{
			scanf_s("%d", &child);
			G[parent].push_back(child);
		}
	}
#ifdef BFS_FUNCTION
	{
		h[1] = 1;
		BFS();
		for (int i = 1; i <= max_h; i++)
		{
			if (i == 1) printf("%d", leaf[i]);
			else printf(" %d", leaf[i]);
		}
	}
#endif

#ifdef DFS_FUNCTION
	DFS(1, 1);
	printf("%d", leaf[1]);
	for(int i = 2; i <= max_h; i++) printf(" %d", leaf[i]);
#endif

}