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
void downAdjust(int low, int high)
{
	int i = low, j = i * 2;
	while (j <= high)
	{
		// 如果右孩子结点存在，且右孩子结点的值大于左孩子结点
		if (j + 1 <= high && tempOri[j + 1] > tempOri[j])
		{
			j = j + 1;	// 让j存储右孩子结点下标
		}
		// 如果孩子结点中最大的权值比父亲结点大
		if (tempOri[j] > tempOri[i])
		{
			swap(tempOri[j], tempOri[i]);
			i = j;
			j = i * 2;
		}
		else
		{
			break;
		}
	}
}

// 堆排序
void heapSort()
{
	bool flag = false;
	for (int i = n / 2; i >= 1; i--)
	{
		downAdjust(i, n);	// 建堆
	}
	for (int i = n; i > 1; i--)
	{
		if (i != n && isSame(tempOri, changed))
		{
			flag = true;
		}
		swap(tempOri[i], tempOri[1]);	// 交换heap[i]与堆顶
		downAdjust(1, i - 1);	// 调整堆顶
		if (flag == true)
		{
			showArray(tempOri);
			return;
		}
	}
}

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &changed[i]);
	}
	if (insertSort())
	{
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else
	{
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++)
		{
			tempOri[i] = origin[i]; // 还原tempOri数组
		}
		heapSort();
	}
}