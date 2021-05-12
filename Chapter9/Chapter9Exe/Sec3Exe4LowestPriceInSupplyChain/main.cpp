/*
����һ�����۹�Ӧ����������Ψһ��������������ļ۸�ΪP,
Ȼ��Ӹ���㿪ʼÿ���ӽ����һ�㣬�ò�Ļ���۸񽫻���
���׽��ļ۸�������r%����Ҷ�ӽ�㴦�ܻ�õ���ͼ۸���
�����ṩ��ͼ۸��Ҷ�ӽ��ĸ�����
*/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
const double INF = 1e12; // �ܴ������10 ^ 12

vector<int> Node[maxn];	// Node[i]���i�����к��ӽ��ı��
int n, num;	// nΪ�������numΪ�۸���͵�Ҷ�ӽ�����
double p, r, ans = INF;	// ansΪ���Ҷ�ӽ��۸�

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