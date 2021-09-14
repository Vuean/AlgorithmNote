/*
������һ����λ���ֲ���ȫ��ͬ����λ������������Ȱ��ĸ����ְ��ǵ�������
�ٰ��ǵݼ�����Ȼ���õ�һ�����ּ��ڶ������֣����õ�һ���µ����֡�
һֱ�ظ����������ܿ��ͣ���С����ֺڶ���֮�Ƶ�6174, ������������Ҳ��Kaprekar ������
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)	// �ݼ�����cmp
{
	return a > b;
}

void to_array(int n, int num[])	// ��n ��ÿһλ�浽num ������
{
	for (int i = 0; i < 4; i++)
	{
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[])	// ��num ����ת��Ϊ����
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum = sum * 10 + num[i];
	}
	return sum;
}

int main()
{
	int n, MIN, MAX;
	cin >> n;
	int num[5];
	while (1)
	{
		to_array(n, num);
		sort(num, num + 4);
		MIN = to_number(num);
		sort(num, num + 4, cmp);
		MAX = to_number(num);
		n = MAX - MIN;
		// cout << MAX << " - " << MIN << " = " << n << endl;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if (n == 0 || n == 6174) break;
	}
}