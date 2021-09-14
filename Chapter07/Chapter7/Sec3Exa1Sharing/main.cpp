/*
给出两条链表的首地址以及若干结点的地址、数据、下一个结点的地址，
求两条链表的首个共用结点的地址。如果两条链表没有共用结点，则输出－1。
*/
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 100010;

struct NODE {
	char data;	// 数据域
	int next;	// 指针域
	bool flag;	// 结点是否在第一条链中出现过
}node[maxn];

int main()
{
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}

	int s1, s2, n;	// s1与s2 分别代表两条链表的首地址
	scanf_s("%d%d%d", &s1, &s2, &n);
	int address, next;;	// 结点地址与后继结点地址
	char data;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}
	int p;
	for (p = s1; p != -1; p = node[p].next)
	{
		node[p].flag = true;
	}
	for (p = s2; p != -1; p = node[p].next) {
		if (node[p].flag == true) break;
	}
	if (p != -1) {
		printf("%05d\n", p);
	}
	else {
		printf("-1\n");
	}
}