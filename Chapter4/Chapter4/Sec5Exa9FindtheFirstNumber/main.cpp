// 1.�������еĵ�һ�����ڵ���x��Ԫ�ص�λ�á�

// A[]Ϊ�ϸ�������У�xΪ����ѯ�������������ص�һ�����ڵ���x��Ԫ�ص�λ��
// ��������Ϊ����ұյ�[left, right]������ĳ�ֵΪ[0, n]

#include <iostream>
using namespace std;

int lower_bound(int A[], int left, int right, int x)
{
	int mid;	// midΪleft��right���е�
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

// 2.�������е�һ������x��Ԫ�ص�λ�á�

int upper_bound(int A[], int left, int right, int x)
{
	int mid;	// midΪleft��right���е�
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