/*
给出一棵销售供应的树，树根唯一。在树根处货物的价格为P,
然后从根结点开始每往子结点走二层，该层的货物价格将会在
父亲结点的价格上增加r%。求所有叶结点中的最高价格以及
这个价格的叶结点个数。
*/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];		// 存放树
double p, r;
// maxDepth 为最大深度，num为最大深度的叶结点个数
int n, maxDepth = 0, num = 0;

void DFS(int index, int depth)
{
	if (child[index].size() == 0)
	{
		if (depth > maxDepth)
		{
			maxDepth = depth;
			num = 1;
		}
		else if (depth == maxDepth) {
			num++;
		}
		return;
	}
	for (int i = 0; i < child[index].size(); i++)
	{
		DFS(child[index][i], depth + 1);
	}
}

int main()
{
	int father, root = 0;
	scanf_s("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &father);
		if (father != -1)
		{
			child[father].push_back(i);	// i是father的子结点
		}
		else {
			root = i;	// i为根结点
		}
	}
	DFS(root, 0);
	printf("%0.2f %d\n", p * pow(1 + r, maxDepth), num);
}