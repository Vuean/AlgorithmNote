#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int A[maxn], n;

// 选择随机主元，对区间A[left, right]进行划分
int randPartition(int A[], int left, int right)
{
	// 生成[left, right]内的随机数
	int p = (round(1.0 * rand() / RAND_MAX * (right - left) + left));
	swap(A[p], A[left]);
	int temp = A[left];
	while (left < right)
	{
		while (left < right && A[right] > temp) right--;
		A[left] = A[right];
		while (left < right && A[left] <= temp) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

// 随机选择算法，从A[left, right]中找到第K大的数，并进行切分
void randSelect(int A[], int left, int right, int K)
{
	if (left == right) return;
	int p = randPartition(A, left, right);
	int M = p - left + 1;
	if (K == M) return;
	if (K < M)
	{
		randSelect(A, left, p - 1, K);
	}
	else
	{
		randSelect(A, p + 1, right, K - M);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int sum = 0, sum1 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	randSelect(A, 0, n - 1, n / 2);
	for (int i = 0; i < n / 2; i++)
	{
		sum1 += A[i];
	}
	cout << (sum - sum1) - sum1;
}