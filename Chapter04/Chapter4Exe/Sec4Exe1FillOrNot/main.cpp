/*
题意（P159）:
已知起点与终点的距离为D, 油箱的最大油量为Cmax, 单位汽油能够支持前进Davg 。
给定N个加油站的单位油价和离起点的距离（所有加油站都在一条线上）， 汽车初始时刻处
于起点位置， 油箱为空， 且可以在任意加油站购买任意量的汽油（前提是不超过油箱容量），
求从起点到终点的最小花费。如果无法到达终点， 则输出能够行驶的最远距离。
*/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

struct station
{
	double price, dis;	// 价格，与起点距离
}st[maxn];

bool cmp(station a, station b)
{
	return a.dis < b.dis;	// 按距离从小到大排序
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
	st[n].price = 0.0;	// 数组最后面放置终点，价格为0；
	st[n].dis = D;
	sort(st, st + n, cmp);
	if (st[0].dis != 0)
	{
		cout << "The maximun travel distance = 0.0\n";
	}
	else
	{
		int now = 0;	// 当前所处加油站编号
		// 总花费、当前油量及满油行驶距离
		double ans = 0.0, nowTank = 0.0, MAX = Cmax * Davg;
		// 每次循环将选出下一个需要到达的加油站
		while (now < n)
		{
			// 选出从当前加油站满油能到达范围内的第一个油价低于当前油价的加油站，
			// 如果没有，则选择价格最低的那个
			int k = -1;	// 最低油价的加油站编号
			double preiceMin = INF;
			for (int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++)
			{
				if (st[i].price < preiceMin)
				{
					preiceMin = st[i].price;
					k = i;
					// 如果找到第一个油价低于当前油价的加油站，直接终端循环
					if (preiceMin < st[now].price)
						break;
				}
			}

			if (k == -1) break;

			// 下面为能找到可到达的加油站k，计算转移花费
			// need为从now到k需要的油量
			double need = (st[k].dis - st[now].dis) / Davg;
			// 如果加油站k的油价低于当前油价
			if (preiceMin < st[now].price)
			{
				// 只需要购买到达加油站k的油
				if (nowTank < need)
				{
					ans += (need - nowTank) * st[now].price;
					nowTank = 0;	// 到达加油站k后邮箱内油量为0
				}
				else
				{
					nowTank -= need;
				}
			}
			else	// 加油站k的油价高于当前油价
			{
				// 邮箱加满
				ans += (Cmax - nowTank) * st[now].price;
				// 到达k后，邮箱剩余油量为Cmax - need
				nowTank = Cmax - need;
			}
			now = k;
		}
		if (now == n)	// 能到达终点
		{
			cout << ans << endl;
		}
		else
		{
			cout << "The maximum travel distance = " << st[now].dis + MAX;
		}
	}
}