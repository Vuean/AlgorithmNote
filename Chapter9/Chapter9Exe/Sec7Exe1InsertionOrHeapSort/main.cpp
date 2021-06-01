/*
����һ����ʼ���У����Զ���ʹ�ò������������򷨽�������
���ڸ���һ�����У����ж������ɲ��������Ƕ���������ģ�
�������һ��������������С�
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;

// ԭʼ���顢ԭʼ���鱸�ݡ�Ŀ������
int origin[N], tempOri[N], changed[N];
// Ԫ�ظ���
int n;

// �ж�����A������B�Ƿ���ͬ
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

// ��������
bool insertSort()
{
	bool flag = false;
	for (int i = 2; i <= n; i++)
	{
		if (i != 2 && isSame(tempOri, changed)) {
			flag = true;
		}
		// ���벿��ֱ����sort����
		sort(tempOri, tempOri + i + 1);
		if (flag == true)
		{
			return true;
		}
	}
	return false;
}

// ��heap������[low, high]��Χ���е���
// ����low Ϊ���������������±꣬
// high һ��Ϊ�ѵ����һ��Ԫ�ص������±�
void downAdjust(int low, int high)
{
	int i = low, j = i * 2;
	while (j <= high)
	{
		// ����Һ��ӽ����ڣ����Һ��ӽ���ֵ�������ӽ��
		if (j + 1 <= high && tempOri[j + 1] > tempOri[j])
		{
			j = j + 1;	// ��j�洢�Һ��ӽ���±�
		}
		// ������ӽ��������Ȩֵ�ȸ��׽���
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

// ������
void heapSort()
{
	bool flag = false;
	for (int i = n / 2; i >= 1; i--)
	{
		downAdjust(i, n);	// ����
	}
	for (int i = n; i > 1; i--)
	{
		if (i != n && isSame(tempOri, changed))
		{
			flag = true;
		}
		swap(tempOri[i], tempOri[1]);	// ����heap[i]��Ѷ�
		downAdjust(1, i - 1);	// �����Ѷ�
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
			tempOri[i] = origin[i]; // ��ԭtempOri����
		}
		heapSort();
	}
}