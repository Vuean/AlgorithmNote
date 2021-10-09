/*
给出一个栈的入栈(Push)、出栈(Pop)过程，并随时通过PeekMedian命令要求输出栈中中间大小
的数(Pop命令输出出栈的数）。当栈中没有元素时，Pop命令和PeekMedian命令都应该输出Invalid。
*/

#include <cstdio>
#include <string>
#include <stack>
using namespace std;
const int maxn = 100010;
const int sqrN = 316;			// sqrt(100010)，表示块内元素个数

stack<int> st;
int block[sqrN];					// 记录每一块中存在的元素个数
int table[maxn];					// hash数组，记录元素当前存在个数

void PeekMedian(int K)
{
	int sum = 0;		// sum 存放当前累计存在的数的个数
	int idx = 0;		// 块号
	while (sum + block[idx] < K)	// 找到第K大的数所在块号
	{
		sum += block[idx++];	// 未达到K, 则累加上当前块的元素个数
	}
	int num = idx * sqrN;		// idx号块的第一个数
	while (sum + table[num] < K)
	{
		sum += table[num++];		// 累加块内元素个数， 直到sum 达到K
	}

	printf("%d\n", num);
}

void Push(int x)
{
	st.push(x);
	block[x / sqrN]++;	// x所在块的元素个数加1
	table[x]++;				// x的存在个数加1
}

void Pop()
{
	int x = st.top();		// 获得栈顶
	st.pop();
	block[x / sqrN]--;	// x所在块的元素个数减1
	table[x]--;				// x的存在个数减1
	printf("%d\n", x);	// 输出
}

int main()
{
	int x, query;
	memset(block, 0, sizeof(block));
	memset(table, 0, sizeof(table));
	char cmd[20];	// 命令
	scanf_s("%d", &query);		// 查询数目

	for (int i = 0; i < query; i++)
	{
		scanf_s("%s", cmd, sizeof(cmd));
		if (strcmp(cmd, "Push") == 0)
		{
			// Push
			scanf_s("%d", &x);
			Push(x);		// 入栈
		}
		else if (strcmp(cmd, "Pop") == 0)
		{
			if (st.empty())
			{
				printf("Invalid\n");	// 栈空
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
				printf("Invalid\n");	// 栈空
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