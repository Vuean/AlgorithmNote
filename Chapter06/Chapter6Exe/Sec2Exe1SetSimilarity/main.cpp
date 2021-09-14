/*
给出N个集合，给出的集合中可能含有相同的值。然后要求M个查询，每个查询
给出两个集合的编号X和Y,求集合X和集合Y的相同元素率，即两个集合的交集
与并集（均需去重）的元素个数的比率。
*/

#include <cstdio>
#include <set>
using namespace std;

const int N = 51;
set<int> st[N];	// N个集合
void compare(int x, int y) {
	int totalNum = st[y].size(), sameNum = 0;
	for (set<int>::iterator it = st[x].begin(); it != st[x].end(); it++) {
		if (st[y].find(*it) != st[y].end()) {
			sameNum++;
		}
		else {
			totalNum++;
		}
	}
	printf_s("%.1f%\n", sameNum * 100 / totalNum);
}

int main()
{
	int n, k, q, v, st1, st2;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &k);	// 集合中元素个数
		for (int j = 0; j < k; j++) {
			scanf_s("%d", &v);
			st[i].insert(v);
		}
	}
	scanf_s("%d", &q);	// q个查询
	for (int i = 0; i < q; i++) {
		scanf_s("%d %d", &st1, &st2);
		compare(st1, st2);
	}
}