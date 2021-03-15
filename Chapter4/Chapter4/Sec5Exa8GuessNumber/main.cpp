#include <iostream>
using namespace std;

// A[]为严格递增序列，left为二分下界，right为二分上界，
// x为欲查询的数
// 二分区间为左闭右闭的[left, right]，传入的初值为[0, n-1]

int binarySearch(int A[], int left, int right, int x)
{
	int mid;	// mid为left和right的中点
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (A[mid] == x) return mid;
		else if (A[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;	// 查找失败
}

int main()
{
	const int n = 10;
	int A[n] = { 1, 3, 4, 6, 7, 8, 10, 11, 12, 15 };
	cout << binarySearch(A, 0, n - 1, 6) << " " << binarySearch(A, 0, n - 1, 9) << endl;
}