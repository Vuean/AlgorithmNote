/*
输入树的结点个数N(结点编号为1~N)、非叶子结点个数M,
然后输入M个非叶子结点各自的孩子结点编号，求结点个数
最多的一层(层号是从整体来看的，根结点层号为1),输出该
层的结点个数以及层号。
*/

#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 110;
vector<int> Node[MAXN];

int hashTable[MAXN] = { 0 };	// 记录每层的结点个数
void DFS(int index, int level)
{
	hashTable[level]++;	// 第level层的结点个数加1
	for (int j = 0; j < Node[index].size(); j++) {
		DFS(Node[index][j], level + 1);
	}
}

int main()
{
	int n, m, parent, k, child;
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &parent, &k);	// 父亲结点编号， 孩子个数
		for (int j = 0; j < k; j++)
		{
			scanf_s("%d", &child);
			Node[parent].push_back(child);
		}
	}
	DFS(1, 1);	// 根结点为1号结点，层号为1
	int maxLevel = -1, maxValue = 0;

	// 计算hashTable 数组的最大值
	for (int i = 1; i < MAXN; i++)
	{
		if (hashTable[i] > maxValue)
		{
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}

	printf("%d %d\n", maxValue, maxLevel);
}