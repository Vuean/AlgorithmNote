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



int main()
{

}