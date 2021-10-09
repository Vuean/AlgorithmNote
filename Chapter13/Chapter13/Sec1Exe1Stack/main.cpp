/*
����һ��ջ����ջ(Push)����ջ(Pop)���̣�����ʱͨ��PeekMedian����Ҫ�����ջ���м��С
����(Pop���������ջ����������ջ��û��Ԫ��ʱ��Pop�����PeekMedian���Ӧ�����Invalid��
*/

#include <cstdio>
#include <string>
#include <stack>
using namespace std;
const int maxn = 100010;
const int sqrN = 316;			// sqrt(100010)����ʾ����Ԫ�ظ���

stack<int> st;
int block[sqrN];					// ��¼ÿһ���д��ڵ�Ԫ�ظ���
int table[maxn];					// hash���飬��¼Ԫ�ص�ǰ���ڸ���

void PeekMedian(int K)
{
	int sum = 0;		// sum ��ŵ�ǰ�ۼƴ��ڵ����ĸ���
	int idx = 0;		// ���
	while (sum + block[idx] < K)	// �ҵ���K��������ڿ��
	{
		sum += block[idx++];	// δ�ﵽK, ���ۼ��ϵ�ǰ���Ԫ�ظ���
	}
	int num = idx * sqrN;		// idx�ſ�ĵ�һ����
	while (sum + table[num] < K)
	{
		sum += table[num++];		// �ۼӿ���Ԫ�ظ����� ֱ��sum �ﵽK
	}

	printf("%d\n", num);
}

void Push(int x)
{
	st.push(x);
	block[x / sqrN]++;	// x���ڿ��Ԫ�ظ�����1
	table[x]++;				// x�Ĵ��ڸ�����1
}

void Pop()
{
	int x = st.top();		// ���ջ��
	st.pop();
	block[x / sqrN]--;	// x���ڿ��Ԫ�ظ�����1
	table[x]--;				// x�Ĵ��ڸ�����1
	printf("%d\n", x);	// ���
}

int main()
{
	int x, query;
	memset(block, 0, sizeof(block));
	memset(table, 0, sizeof(table));
	char cmd[20];	// ����
	scanf_s("%d", &query);		// ��ѯ��Ŀ

	for (int i = 0; i < query; i++)
	{
		scanf_s("%s", cmd, sizeof(cmd));
		if (strcmp(cmd, "Push") == 0)
		{
			// Push
			scanf_s("%d", &x);
			Push(x);		// ��ջ
		}
		else if (strcmp(cmd, "Pop") == 0)
		{
			if (st.empty())
			{
				printf("Invalid\n");	// ջ��
			}
			else
			{
				Pop();
			}
		}
		else
		{
			// PeekMedian
			if (st.empty())
			{
				printf("Invalid\n");	// ջ��
			}
			else
			{
				int K = st.size();
				if (K % 2 == 1) K = (K + 1) / 2;
				else K = K / 2;
				PeekMedian(K);
			}
		}
	}
}