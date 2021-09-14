/*
给出N个结点的地址address、数据域data以及指针域next,然后给出链表
的首地址，要求把在这个链表上的结点按data值从小到大输出。
(可能存在无效结点：不在链表上的结点)
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;

struct Node {
	int address, data, next;
	bool flag;
}node[maxn];

bool cmp(Node a, Node b) {
	if (a.flag == false || b.flag == false) {
		return a.flag > b.flag;	// 只要a 和b 中有一个无效结点， 就把它放后面去
	}
	else {
		return a.data < b.data;	// 如果都是有效结点， 则按要求排序
	}
}

int main()
{
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}

	int n, begin, address;
	scanf_s("%d%d", &n, &begin);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &address);
		scanf_s("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int count = 0, p = begin;
	while (p != -1) {
		node[p].flag = true;
		count++;
		p = node[p].next;
	}
	if (count == 0) {
		printf("0, -1");
	}
	else {
		// 筛选有效结点，并按data 从小到大排序（步骤4 )
		sort(node, node + maxn, cmp);
		printf("%d %05d\n", count, node[0].address);
		for (int i = 0; i < count; i++) {
			if (i != count - 1) {
				printf("%05d %d %05d", node[i].address, node[i].data, node[i + 1].address);
			}
			else {
				printf("%05d %d -1", node[i].address, node[i].data);
			}
		}
	}
}