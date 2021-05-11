/*
给出一棵销售供应的树，树根唯一。在树根处货物的价格为P, 
然后从根结点开始每往子结点走一层，该层的货物价格将会在
父亲结点的价格上增加产r%。给出每个叶结点的货物量，求它
们的价格之和。
*/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
	double data;	// 数据域
	vector<int> child;	// 指针域
} Node[maxn];

int n;
double p, r, ans = 0;	// ans为叶结点货物的价格之和
void DFS(int index, int depth)
{
	if (Node[index].child.size() == 0)
	{
		ans += Node[index].data * pow(1 + r, depth);
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++)
	{
		DFS(Node[index].child[i], depth + 1);
	}
}

int main()
{
	int k, child;
	scanf_s("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &k);
		if (k == 0)
		{
			// 叶节点
			scanf_s("%lf", &Node[i].data);
		}
		else {
			for (int j = 0; j < k; j++)
			{
				scanf_s("%d", &child);
				Node[i].child.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%0.1f\n", p * ans);
}