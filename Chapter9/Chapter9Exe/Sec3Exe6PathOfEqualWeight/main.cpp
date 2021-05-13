/*
给定一棵树和每个结点的权值， 求所有从根结点到叶子结点的
路径，使得每条路径上结点的权值之和等于给定的常数S。如果
有多条这样的路径，按路径非递增的顺序输出。其中路径的大小
是指，如果两条路径分别为a1-a2-...-ai-an 与b1-b2-···
-bi-bm, 且有a1==b1、a2 == b2、. . . 、ai-1 == bi-1
成立，但ai>bi，那么称第一条路径比第二条路径大。
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 110;

struct node {
	int weight;
	vector<int> child;

	node()
		: weight(0)
	{}
}Node[MAXN];

bool cmp(int a, int b)
{
	// 按结点数据域从大到小排序
	return Node[a].weight > Node[b].weight;
}

int n, m, S;	// 结点数，边数，给定的和
int path[MAXN];	// 记录路径
// 当前访问结点为index , numNode为当前路径path上的结点个数
// sum为当前的结点点权和
void DFS(int index, int numNode, int sum)
{
	if (sum > S) return;
	if (sum == S)
	{
		// 还不到叶子节点，直接返回
		if (Node[index].child.size() != 0) return;
		// 到达叶子结点，此时path[] 中存放了一条完整的路径， 输出它
		for (int i = 0; i < numNode; i++)
		{
			printf("%d", Node[path[i]].weight);
			if (i < numNode - 1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++)
	{
		int child = Node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode + 1, sum + Node[child].weight);
	}
}

int main()
{
	scanf_s("%d%d%d", &n, &m, &S);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &Node[i].weight);
	}
	int id, k, child = 0;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &id, &k);
		for (int j = 0; j < k; j++)
		{
			scanf_s("%d", child);
			Node[i].child.push_back(child);
		}
		sort(Node[id].child.begin(), Node[id].child.end());
	}
	path[0] = 0;// 路径的第一个结点设置为0 号结点
	DFS(0, 1, Node[0].weight);
}
