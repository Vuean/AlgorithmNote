/*
���⣺
���������ǵ����㷨�� ��һ����������ݣ� �𲽲��������������С�ÿ�������У���
���Ӵ�����������ȡ��һԪ�أ���֮����������������ȷ��λ�á���˵���ֱ��ȫ��Ԫ������
�鲢����������µ������������Ƚ�ԭʼ���п���.N��ֻ����һ��Ԫ�ص����������У�
Ȼ��ÿ�ε����鲢�������ڵ����������У�ֱ�����ֻʣ��һ����������С�
�ָ���ԭʼ���к���ĳ�����㷨�������м����У������жϸ��㷨���������������㷨��
*/

// ��ʼ���в������Ƿ���Ŀ��������ͬ�ıȽ�

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 111;
int origin[N], tempOri[N], changed[N];	// ԭʼ���飬ԭʼ���鱸�ݣ�Ŀ������
int n;	// Ԫ�ظ���

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
	bool flag = false;	// ��¼�Ƿ���������м䲽����changed��ͬ
	for(int i = 1; i < n; i++)
	{
		if (i != 1 && isSame(tempOri, changed))
		{
			flag = true;
		}
		// ����Ϊ���벿��
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
			tempOri[i] = origin[i];	// ��ԭtempOri����
		}
		mergeSort();
	}
}