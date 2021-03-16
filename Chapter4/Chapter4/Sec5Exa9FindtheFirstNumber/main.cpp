// 1.求序列中的第一个大于等于x的元素的位置。

// A[]为严格递增序列，x为欲查询的数，函数返回第一个大于等于x的元素的位置
// 二分区间为左闭右闭的[left, right]，传入的初值为[0, n]

#include <iostream>
using namespace std;

int lower_bound(int A[], int left, int right, int x)
{
	int mid;	// mid为left和right的中点
	while (left < right)
	{
		mid = (left + right) / 2;
		if (A[mid] >= x)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

// 2.求序列中第一个大于x的元素的位置。

int upper_bound(int A[], int left, int right, int x)
{
	int mid;	// mid为left和right的中点
	while (left < right)
	{
		mid = (left + right) / 2;
		if (A[mid] > x)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{

}