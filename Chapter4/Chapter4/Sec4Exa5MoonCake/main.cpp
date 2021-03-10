/*
题目描述：
给定所有种类月饼的库存量、总售价以及市场的最大需求量， 
试计算可以获得的最大收益。
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct mooncake
{
	double store;	// 总库存量
	double sell;		// 总售价
	double price;	// 单价
}cake[1010];

// 按单价从高到低排序
bool cmp(mooncake a, mooncake b)
{
	return a.price > b.price;
}

int main()
{
	int n;			// 月饼种类数
	double D;	// 市场最大需求量
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
	
	sort(cake, cake+n, cmp);
	
	double ans = 0.0; // 收益

	for (int i = 0; i < n; i++)
	{
		if (cake[i].store <= D)
		{
			ans += cake[i].sell;
			D -= cake[i].store;
		}
		else
		{
			ans += cake[i].price * D;
			break;
		}
	}

	printf("%.2f\n", ans);
}