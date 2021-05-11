/*
�������Ľ�����N(�����Ϊ1~N)����Ҷ�ӽ�����M,
Ȼ������M����Ҷ�ӽ����Եĺ��ӽ���ţ��������
����һ��(����Ǵ����������ģ��������Ϊ1),�����
��Ľ������Լ���š�
*/

#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 110;
vector<int> Node[MAXN];

int hashTable[MAXN] = { 0 };	// ��¼ÿ��Ľ�����
void DFS(int index, int level)
{
	hashTable[level]++;	// ��level��Ľ�������1
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
		scanf_s("%d%d", &parent, &k);	// ���׽���ţ� ���Ӹ���
		for (int j = 0; j < k; j++)
		{
			scanf_s("%d", &child);
			Node[parent].push_back(child);
		}
	}
	DFS(1, 1);	// �����Ϊ1�Ž�㣬���Ϊ1
	int maxLevel = -1, maxValue = 0;

	// ����hashTable ��������ֵ
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