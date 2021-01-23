// ȫ����(Full Permutation)
#include <iostream>
using namespace std;
const int maxn = 11;

// PΪ��ǰ���У� hashTable��¼����x�Ƿ��Ѿ���P��
int n, P[maxn], hashTable[maxn] = { false };

// ��ǰ�������еĵ�index��λ
void generateP(int index)
{
	if (n + 1 == index)	// �ݹ�߽磬�Ѵ��������е�1~nλ
	{
		for (int i = 1; i <= n; i++)
		{
			cout << P[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int x = 1; x <= n; x++)	// ö��1~n����ͼ��x����P[index]
	{
		if (false == hashTable[x])	// ���x����P[0]~P[index-1]��
		{
			P[index] = x;	// ��P�ĵ�indexλλx������x���뵱ǰ����
			hashTable[x] = true;	// ��סx����P��
			generateP(index + 1);	// �������еĵ�index+1��λ
			hashTable[x] = false;	// �Ѵ�����P [ index]Ϊx �������⣬ ��ԭ״̬
		}
	}
}

int main()
{
	n = 3;
	generateP(1);	// ��P[1]��ʼ��
	return 0;
}