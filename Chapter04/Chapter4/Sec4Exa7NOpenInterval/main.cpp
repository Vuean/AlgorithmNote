// N开区间问题

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 110;
struct Interval
{
	int x, y;	// 开区间左右拐点
} I[maxn];

bool cmp(Interval a, Interval b)
{
	if (a.x != b.x) return a.x > b.x;	// 先按左端点从大到小排序
	else return a.y < b.y;	// 左端点相同的按右端点从小到大排序
}

int main()
{
	int n;
	while (scanf_s("%d", &n), n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d%d", &I[i].x, &I[i].y);
		}
		sort(I, I + n, cmp);	// 将区间排序
		// ans记录不相交个数，lastX记录上一个被选中区间的左端点
		int ans = 1, lastX = I[0].x;
		for (int i = 1; i < n; i++)
		{
			if (I[i].y <= lastX)	// 如果该区间右端点在lastX左边
			{
				lastX = I[i].x;	// 以I[i]作为新选中的区间
				ans++;	// 不相交区间个数加1
			}
		}
		printf("%d\n", ans);
	}
}