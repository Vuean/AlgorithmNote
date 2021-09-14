#include <iostream>
using namespace std;
const int maxn = 11;
int Count = 0;
int n, P[maxn], hashTable[maxn] = { false };

void generateP(int index)
{
	if (index == n + 1)	// 递归边界，生成一个排列
	{
		bool flag = true;	// flag为true表示当前排列为一个合法方案
		for (int i = 1; i <= n; i++)	// 边离任意两个皇后
		{
			for (int j = i + 1; j <= n; j++)
			{
				if(abs(i-j) == abs(P[i] - P[j]))	// 如果在一条对角线上
					flag = false;
			}
		}
		if (flag) Count++;
		return;
	}
	for (int x = 1; x <= n; x++)
	{
		if (hashTable[x] == false)
		{
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false;
		}
	}
}

// 回溯法
void generateP2(int index)
{
	if (index == n + 1)// 递归边界， 生成一个合法方案
	{
		Count++;
		return;
	}
	for (int x = 1; x <= n; x++)	// 第x行
	{
		if (hashTable[x] == false)	// 如果第x行没有皇后
		{
			bool flag = true;	//flag 为true 表示当前皇后不会和之前的皇后冲突
			for (int pre = 1; pre < index; pre++)	// 遍历之前的皇后
			{
				// 第index列皇后的行号为X , 第pre 列皇后的行号为P[pre]
				if (abs(index - pre) == abs(x - P[pre]))
				{
					flag = false;	// 与之前的皇后在一条对角线， 冲突
					break;
				}
			}
			if (flag)	// 如果可以把皇后放在第x 行
			{
				P[index] = x;	// 令第index 列皇后的行号为x
				hashTable[x] = true;	// 第x 行已被占用
				generateP2(index + 1);	// 递归处理第index+l 行皇后
				hashTable[x] = false;	// 递归完毕，还原第x行为未占用
			}
		}
	}
}

int main()
{
	return 0;
}