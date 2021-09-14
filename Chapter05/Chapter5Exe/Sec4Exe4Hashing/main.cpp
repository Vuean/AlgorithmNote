/*
����ɢ�б�TSize���������Ԫ�أ�����ЩԪ�ذ������˳�����ɢ�б��У�
����ɢ�к���ΪH(key) = key % TSize�������ͻ����ֻ���������ӵ�
����̽�鷨�������η�̽�鷨�������⣬�����Ŀ������TSize����������
��ô��Ҫ��TSize���¸�ֵΪ��һ����TSize��������ٽ���Ԫ�ز��롣
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 11111;

bool IsPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i < sqr; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

bool HashTable[MAXN] = { 0 };	// Ϊfalse��iλδ��ʹ�ú�

int main()
{
	int N, TSize, a;
	cin >> TSize >> N;
	while (!IsPrime(TSize))
	{
		TSize++;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		int M = a % TSize;
		if (!HashTable[M])	// M��λδ��ʹ�ã������ҵ�
		{
			HashTable[M] = true;
			if (i == 0) cout << M;
			else cout << " " << M;
		}
		else
		{
			int step;	// ���η�̽�鷨
			for (step = 1; step < TSize; step++)
			{
				M = (a + step * step) % TSize;
				if (!HashTable[M])
				{
					HashTable[M] = true;
					if (i == 0) cout << M;
					else cout << " " << M;
					break;
				}
			}
			if (step >= TSize)	// �Ҳ�������ĵط�
			{
				if (i > 0) cout << " ";
				cout << "-";
			}
		}
	}

}