// 全排列(Full Permutation)
#include <iostream>
using namespace std;
const int maxn = 11;

// P为当前排列， hashTable记录整数x是否已经在P中
int n, P[maxn], hashTable[maxn] = { false };

// 当前处理排列的第index号位
void generateP(int index)
{
	if (n + 1 == index)	// 递归边界，已处理完排列的1~n位
	{
		for (int i = 1; i <= n; i++)
		{
			cout << P[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int x = 1; x <= n; x++)	// 枚举1~n，试图将x填入P[index]
	{
		if (false == hashTable[x])	// 如果x不在P[0]~P[index-1]中
		{
			P[index] = x;	// 令P的第index位位x，即把x加入当前排列
			hashTable[x] = true;	// 记住x已在P中
			generateP(index + 1);	// 处理排列的第index+1号位
			hashTable[x] = false;	// 已处理完P [ index]为x 的子问题， 还原状态
		}
	}
}

int main()
{
	n = 3;
	generateP(1);	// 从P[1]开始填
	return 0;
}