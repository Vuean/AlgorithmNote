/*
����һ�����۹�Ӧ����������Ψһ��������������ļ۸�ΪP, 
Ȼ��Ӹ���㿪ʼÿ���ӽ����һ�㣬�ò�Ļ���۸񽫻���
���׽��ļ۸������Ӳ�r%������ÿ��Ҷ���Ļ�����������
�ǵļ۸�֮�͡�
*/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
	double data;	// ������
	vector<int> child;	// ָ����
} Node[maxn];

int n;
double p, r, ans = 0;	// ansΪҶ������ļ۸�֮��
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
			// Ҷ�ڵ�
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