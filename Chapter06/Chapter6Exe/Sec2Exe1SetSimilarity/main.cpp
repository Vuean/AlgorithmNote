/*
����N�����ϣ������ļ����п��ܺ�����ͬ��ֵ��Ȼ��Ҫ��M����ѯ��ÿ����ѯ
�����������ϵı��X��Y,�󼯺�X�ͼ���Y����ͬԪ���ʣ����������ϵĽ���
�벢��������ȥ�أ���Ԫ�ظ����ı��ʡ�
*/

#include <cstdio>
#include <set>
using namespace std;

const int N = 51;
set<int> st[N];	// N������
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
		scanf_s("%d", &k);	// ������Ԫ�ظ���
		for (int j = 0; j < k; j++) {
			scanf_s("%d", &v);
			st[i].insert(v);
		}
	}
	scanf_s("%d", &q);	// q����ѯ
	for (int i = 0; i < q; i++) {
		scanf_s("%d %d", &st1, &st2);
		compare(st1, st2);
	}
}