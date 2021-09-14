#include <iostream>
using namespace std;

// A[]Ϊ�ϸ�������У�leftΪ�����½磬rightΪ�����Ͻ磬
// xΪ����ѯ����
// ��������Ϊ����ұյ�[left, right]������ĳ�ֵΪ[0, n-1]

int binarySearch(int A[], int left, int right, int x)
{
	int mid;	// midΪleft��right���е�
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
	return -1;	// ����ʧ��
}

int main()
{
	const int n = 10;
	int A[n] = { 1, 3, 4, 6, 7, 8, 10, 11, 12, 15 };
	cout << binarySearch(A, 0, n - 1, 6) << " " << binarySearch(A, 0, n - 1, 9) << endl;
}