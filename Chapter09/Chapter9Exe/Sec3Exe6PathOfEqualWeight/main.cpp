/*
����һ������ÿ������Ȩֵ�� �����дӸ���㵽Ҷ�ӽ���
·����ʹ��ÿ��·���Ͻ���Ȩֵ֮�͵��ڸ����ĳ���S�����
�ж���������·������·���ǵ�����˳�����������·���Ĵ�С
��ָ���������·���ֱ�Ϊa1-a2-...-ai-an ��b1-b2-������
-bi-bm, ����a1==b1��a2 == b2��. . . ��ai-1 == bi-1
��������ai>bi����ô�Ƶ�һ��·���ȵڶ���·����
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
	// �����������Ӵ�С����
	return Node[a].weight > Node[b].weight;
}

int n, m, S;	// ������������������ĺ�
int path[MAXN];	// ��¼·��
// ��ǰ���ʽ��Ϊindex , numNodeΪ��ǰ·��path�ϵĽ�����
// sumΪ��ǰ�Ľ���Ȩ��
void DFS(int index, int numNode, int sum)
{
	if (sum > S) return;
	if (sum == S)
	{
		// ������Ҷ�ӽڵ㣬ֱ�ӷ���
		if (Node[index].child.size() != 0) return;
		// ����Ҷ�ӽ�㣬��ʱpath[] �д����һ��������·���� �����
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
	path[0] = 0;// ·���ĵ�һ���������Ϊ0 �Ž��
	DFS(0, 1, Node[0].weight);
}
