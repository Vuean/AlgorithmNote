// [PATB1032] �ھ�������ļ�ǿ
/*
����ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��
���룺
	�ڵ�1�и���������10^5��������N, ���������������N�У�ÿ�и���һλ�����ߵ�
��Ϣ�ͳɼ��� �������������ѧУ�ı�ţ���1��ʼ������ţ���������ɼ����ٷ��ƣ�����
���Կո�ָ���
�����
	��һ���и����ܵ÷���ߵ�ѧУ�ı�ż����ܷ֣��м��Կո�ָ�����Ŀ��֤��Ψһ��
û�в��С�
*/
#include <iostream>
using namespace std;

const int maxnum = 100;
int school[maxnum] = { 0 };	// ��¼ÿ��ѧУ���ܷ�

int main()
{
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;	// ����ѧУID�ͷ���
		school[a] += b;
	}
	int index = 1, maxscore = 0;	// ����ֵܷ�ѧУID���ܷ�
	for (int i = 1; i <= n; i++)
	{
		if (school[i] > maxscore)
		{
			maxscore = school[i];
			index = i;
		}
	}
	cout << index << " " << maxscore << endl;
}