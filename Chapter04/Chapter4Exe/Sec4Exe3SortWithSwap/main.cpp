/*
���⣺
����0, 1, �� , N-1 ��һ�����У� Ҫ��ͨ�����������ķ�ʽ�����Ϊ�������У� ���ǹ涨
ÿ��ֻ����0�����������н���������С����������
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int pos[maxn];	// ��Ÿ����ֵ�ǰ������λ�ñ��

int main()
{
	int n, ans = 0;
	cin >> n;

	int left = n - 1, num;	// left��ų�0���ⲻ�ڱ�λ�ϵ����ĸ���
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		pos[num] = i;	// num������λ��Ϊi��
		if (num == i && num != 0)
			left--;
	}

	int k = 1;	// k��ų�0���⵱ǰ���ڱ�λ�ϵ���С��
	while (left > 0)
	{
		// ���0�ڱ�λ�ϣ���Ѱ��һ����ǰ���ڱ�λ�ϵ�����0����
		if (pos[0] == 0)
		{
			while (k < n)
			{
				if (pos[k] != k)	// �ҵ�һ����ǰ���ڱ�λ�ϵ���
				{
					swap(pos[0], pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		// ֻҪ0���ڱ�λ���ͽ�0����λ�õ����ĵ�ǰ����λ����0��λ�ý���
		while (pos[0] != 0)
		{
			swap(pos[0], pos[pos[0]]);	// ��0��pos[0]����
			ans++;
			left--;
		}
	}
	cout << "Ans = " << ans;
}