/*
��Ŀ������
��������0 ~ 9 �����ɸ�����������˳��������Щ���֣� ������ȫ��ʹ�á�Ŀ����ʹ����
��õ�����������С��
*/

#include <iostream>
using namespace std;

int main()
{
	int count[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> count[i];
	}

	for (int i = 1; i < 10; i++)
	{
		if (count[i] > 0)
		{
			printf("%d", i);
			count[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			printf("%d", i);
		}
	}
}