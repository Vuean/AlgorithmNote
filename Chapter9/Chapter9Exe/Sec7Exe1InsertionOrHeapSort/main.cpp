/*
给出一个初始序列，可以对它使用插入排序或堆排序法进行排序。
现在给出一个序列，试判断它是由插入排序还是堆排序产生的，
并输出下一步将会产生的序列。
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;

// 原始数组、原始数组备份、目标数组
int origin[N], tempOri[N], changed[N];
// 元素个数
int n;

// 判断数组A和数组B是否相同
bool isSame(int A[], int B[])
{
	for (int i = 1; i <= n; i++)
	{
		if (A[i] != B[i])
			return false;
	}
	return true;
}

void showArray(int A[])
{
	for (int i = 1; i < n; i++)
	{
		printf("%d", A[i]);
		if (i < n)
			printf(" ");
	}
	printf("\n");
}

// 插入排序
bool insertSort()
{
	bool flag = false;
	for (int i = 2; i <= n; i++)
	{
		if (i != 2 && isSame(tempOri, changed)) {
			flag = true;
		}
		// 插入部分直接用sort代替
		sort(tempOri, tempOri + i + 1);
		if (flag == true)
		{
			return true;
		}
	}
	return false;
}

// 对heap数组在[low, high]范围进行调整
// 其中low 为欲调整结点的数组下标，
// high 一般为堆的最后一个元素的数组下标



int main()
{

}