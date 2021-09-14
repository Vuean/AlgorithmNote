/*
给出一棵树， 问每一层各有多少叶子结点。
*/

/*
由于题目给定的是一般性质的树， 因此可以使用邻接表来存储。
此时树的遍历一般使用两种方法实现： 深度优先搜索和广度优先搜索。
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

vector<int> G[N];			// 存放树
int h[N] = { 0 };				// 各结点所处的层号， 从1 开始
int leaf[N] = { 0 };			// 存放每层的叶子结点个数
int max_h = 1;					// 树的深度

void DFS(int index, int h)
{
	// index 为当前遍历到的结点编号， h 为当前深度
	max_h = max(h, max_h);
	if (G[index].size() == 0)	// 如果该结点是叶子结点
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
	Q.push(1);		// 将根结点压入队列
	while (!Q.empty())
	{
		int id = Q.front();
		Q.pop();
		max_h = max(max_h, h[id]);
		if (G[id].size() == 0)// 如果该结点是叶子结点
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