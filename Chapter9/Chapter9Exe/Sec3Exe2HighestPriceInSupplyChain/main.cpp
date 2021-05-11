/*
����һ�����۹�Ӧ����������Ψһ��������������ļ۸�ΪP,
Ȼ��Ӹ���㿪ʼÿ���ӽ���߶��㣬�ò�Ļ���۸񽫻���
���׽��ļ۸�������r%��������Ҷ����е���߼۸��Լ�
����۸��Ҷ��������
*/

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];		// �����
double p, r;
// maxDepth Ϊ�����ȣ�numΪ�����ȵ�Ҷ������
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
			child[father].push_back(i);	// i��father���ӽ��
		}
		else {
			root = i;	// iΪ�����
		}
	}
	DFS(root, 0);
	printf("%0.2f %d\n", p * pow(1 + r, maxDepth), num);
}