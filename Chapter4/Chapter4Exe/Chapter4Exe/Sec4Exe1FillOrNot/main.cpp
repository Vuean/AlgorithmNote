/*
���⣨P159��:
��֪������յ�ľ���ΪD, ������������ΪCmax, ��λ�����ܹ�֧��ǰ��Davg ��
����N������վ�ĵ�λ�ͼۺ������ľ��루���м���վ����һ�����ϣ��� ������ʼʱ�̴�
�����λ�ã� ����Ϊ�գ� �ҿ������������վ���������������ͣ�ǰ���ǲ�����������������
�����㵽�յ����С���ѡ�����޷������յ㣬 ������ܹ���ʻ����Զ���롣
*/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

struct station
{
	double price, dis;	// �۸���������
}st[maxn];

bool cmp(station a, station b)
{
	return a.dis < b.dis;	// �������С��������
}

int main()
{
	int n;
	double Cmax, D, Davg;
	cin >> Cmax >> D >> Davg >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> st[i].price >> st[i].dis;
	}
	st[n].price = 0.0;	// �������������յ㣬�۸�Ϊ0��
	st[n].dis = D;
	sort(st, st + n, cmp);
	if (st[0].dis != 0)
	{
		cout << "The maximun travel distance = 0.0\n";
	}
	else
	{
		int now = 0;	// ��ǰ��������վ���
		// �ܻ��ѡ���ǰ������������ʻ����
		double ans = 0.0, nowTank = 0.0, MAX = Cmax * Davg;
		// ÿ��ѭ����ѡ����һ����Ҫ����ļ���վ
		while (now < n)
		{
			// ѡ���ӵ�ǰ����վ�����ܵ��ﷶΧ�ڵĵ�һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ��
			// ���û�У���ѡ��۸���͵��Ǹ�
			int k = -1;	// ����ͼ۵ļ���վ���
			double preiceMin = INF;
			for (int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++)
			{
				if (st[i].price < preiceMin)
				{
					preiceMin = st[i].price;
					k = i;
					// ����ҵ���һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ��ֱ���ն�ѭ��
					if (preiceMin < st[now].price)
						break;
				}
			}

			if (k == -1) break;

			// ����Ϊ���ҵ��ɵ���ļ���վk������ת�ƻ���
			// needΪ��now��k��Ҫ������
			double need = (st[k].dis - st[now].dis) / Davg;
			// �������վk���ͼ۵��ڵ�ǰ�ͼ�
			if (preiceMin < st[now].price)
			{
				// ֻ��Ҫ���򵽴����վk����
				if (nowTank < need)
				{
					ans += (need - nowTank) * st[now].price;
					nowTank = 0;	// �������վk������������Ϊ0
				}
				else
				{
					nowTank -= need;
				}
			}
			else	// ����վk���ͼ۸��ڵ�ǰ�ͼ�
			{
				// �������
				ans += (Cmax - nowTank) * st[now].price;
				// ����k������ʣ������ΪCmax - need
				nowTank = Cmax - need;
			}
			now = k;
		}
		if (now == n)	// �ܵ����յ�
		{
			cout << ans << endl;
		}
		else
		{
			cout << "The maximum travel distance = " << st[now].dis + MAX;
		}
	}
}