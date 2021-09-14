/*
题意：
插入排序是迭代算法， 逐一获得输入数据， 逐步产生有序的输出序列。每步迭代中，算
法从从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
归并排序进行如下迭代操作：首先将原始序列看作.N个只包含一个元素的有序子序列，
然后每次迭代归并两个相邻的有序子序列，直到最后只剩下一个有序的序列。
现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？
*/

// 初始序列不参与是否与目标序列相同的比较

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 111;
int origin[N], tempOri[N], changed[N];	// 原始数组，原始数组备份，目标数组
int n;	// 元素个数

bool isSame(int A[], int B[])
{
	for (int i = 0; i < n; i++)
	{
		if (A[i] != B[i]) return false;
	}
	return true;
}

void showArray(int A[])
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

bool insertSort()
{
	bool flag = false;	// 记录是否存在数组中间步骤与changed相同
	for(int i = 1; i < n; i++)
	{
		if (i != 1 && isSame(tempOri, changed))
		{
			flag = true;
		}
		// 以下为插入部分
		int temp = tempOri[i], j = i;
		while (j > 0 && tempOri[j - 1] > temp)
		{
			tempOri[j] = tempOri[j - i];
			j--;
		}
		tempOri[j] = temp;
		if(flag == true)
		{
			return true;
		}
	}
	return false;
}

void mergeSort()
{
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2)
	{
		if (step != 2 && isSame(tempOri, changed))
		{
			flag = true;
		}
		for (int i = 0; i < n; i += step)
		{
			sort(tempOri + i, tempOri + min(i + step, n));
		}
		if (flag == true)
		{
			showArray(tempOri);
			return;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> origin[i];
		tempOri[i] = origin[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> changed[i];
	}

	if (insertSort())
	{
		cout << "Insertion Sort" << endl;
		showArray(tempOri);
	}
	else
	{
		cout << "Merge Sort" << endl;
		for (int i = 0; i < n; i++)
		{
			tempOri[i] = origin[i];	// 还原tempOri数组
		}
		mergeSort();
	}
}