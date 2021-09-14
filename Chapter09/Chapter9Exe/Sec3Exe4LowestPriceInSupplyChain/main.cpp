/*
给出一棵销售供应的树，树根唯一。在树根件货物的价格为P,
然后从根结点开始每往子结点走一层，该层的货物价格将会在
父亲结点的价格上增加r%。求叶子结点处能获得的最低价格以
及能提供最低价格的叶子结点的个数。
*/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
const double INF = 1e12; // 很大的数，10 ^ 12

vector<int> Node[maxn];	// Node[i]存放i的所有孩子结点的编号
int n, num;	// n为结点数，num为价格最低的叶子结点个数
double p, r, ans = INF;	// ans为最低叶子结点价格

void DFS(int index, int depth)
{
	if (Node[index].size() == 0)
	{
		double price = p * pow(1 + r, depth);
		if (price < ans)
		{
			ans = price;
			num = 1;
		}
		else if(price == ans){
			num++;
		}
		return;
	}
	for (int i = 0; i < Node[index].size(); i++)
	{
		DFS(Node[index][i], depth + 1);
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
		if (k != 0)
		{
			for (int j = 0; j < k; j++)
			{
				scanf_s("%d", &child);
				Node[i].push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.4f %d\n", ans, num);
}