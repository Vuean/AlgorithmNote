#include <iostream>
using namespace std;
const int maxn = 11;
int Count = 0;
int n, P[maxn], hashTable[maxn] = { false };

void generateP(int index)
{
	if (index == n + 1)	// �ݹ�߽磬����һ������
	{
		bool flag = true;	// flagΪtrue��ʾ��ǰ����Ϊһ���Ϸ�����
		for (int i = 1; i <= n; i++)	// �������������ʺ�
		{
			for (int j = i + 1; j <= n; j++)
			{
				if(abs(i-j) == abs(P[i] - P[j]))	// �����һ���Խ�����
					flag = false;
			}
		}
		if (flag) Count++;
		return;
	}
	for (int x = 1; x <= n; x++)
	{
		if (hashTable[x] == false)
		{
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false;
		}
	}
}

// ���ݷ�
void generateP2(int index)
{
	if (index == n + 1)// �ݹ�߽磬 ����һ���Ϸ�����
	{
		Count++;
		return;
	}
	for (int x = 1; x <= n; x++)	// ��x��
	{
		if (hashTable[x] == false)	// �����x��û�лʺ�
		{
			bool flag = true;	//flag Ϊtrue ��ʾ��ǰ�ʺ󲻻��֮ǰ�Ļʺ��ͻ
			for (int pre = 1; pre < index; pre++)	// ����֮ǰ�Ļʺ�
			{
				// ��index�лʺ���к�ΪX , ��pre �лʺ���к�ΪP[pre]
				if (abs(index - pre) == abs(x - P[pre]))
				{
					flag = false;	// ��֮ǰ�Ļʺ���һ���Խ��ߣ� ��ͻ
					break;
				}
			}
			if (flag)	// ������԰ѻʺ���ڵ�x ��
			{
				P[index] = x;	// ���index �лʺ���к�Ϊx
				hashTable[x] = true;	// ��x ���ѱ�ռ��
				generateP2(index + 1);	// �ݹ鴦���index+l �лʺ�
				hashTable[x] = false;	// �ݹ���ϣ���ԭ��x��Ϊδռ��
			}
		}
	}
}

int main()
{
	return 0;
}