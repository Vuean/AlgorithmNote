/*
��Ŀ������
�������������±��Ŀ���������ۼ��Լ��г�������������� 
�Լ�����Ի�õ�������档
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct mooncake
{
	double store;	// �ܿ����
	double sell;		// ���ۼ�
	double price;	// ����
}cake[1010];

// �����۴Ӹߵ�������
bool cmp(mooncake a, mooncake b)
{
	return a.price > b.price;
}

int main()
{
	int n;			// �±�������
	double D;	// �г����������
	cin >> n >> D;
	for (int i = 0; i < n; i++)
	{
		cin >> cake[i].store;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cake[i].sell;
		cake[i].price = cake[i].sell / cake[i].store;
	}
	
	
	for (int i = 0; i < n; i++)
	{
		cout << cake[i].price << endl;
	}
}