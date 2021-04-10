/*
��N��ѧ���� K�ſΡ����ڸ���ѡ��ÿ�ſε�ѧ��������
����֮�����N��ѧ����������Ҫ��˳�����ÿ��ѧ����ѡ�������
*/

/*
ע��㣺
1. ʹ��map��string�ᵼ�³�ʱ���������map<string, vector<int>>
����map<string, set<int>>��д�����ǲ��еġ�
2.�����������Ӵ�����벻Ҫʹ��cin��cout��������������
3. ���ʹ�ö�ά������ѧ����ѡ�Ŀγ̱�ţ��ᵼ�����һ�������ڴ泬�ޣ�
�����Ҫʹ��vector�����ٿռ����ġ�
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 40010;

// ���ַ���hash���
int getID(char name[]) {	// hash��������nameתΪ����
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}

// ����vector��������Ų�ͬѧ������ѡ������пγ̵ı�š�
const int M = 26 * 26 * 26 * 10 + 1;	// ����ɢ�гɵ������Ͻ�
vector<int> selectCourse[M];			// ÿ��ѧ��ѡ��Ŀγ̱��

int main()
{
	char name[5];
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int course, x;
		cin >> course >> x;
		for (int j = 0; j < x; j++) {
			scanf_s("%s", name);
			int id = getID(name);
			selectCourse[id].push_back(course);
		}
	}

	// n����ѯ
	for (int i = 0; i < n; i++) {
		scanf_s("%s", name);
		int id = getID(name);
		sort(selectCourse[id].begin(), selectCourse[id].end());
		printf_s("%s %d", name, selectCourse[id].size());
		for (int j = 0; j < selectCourse[id].size(); j++) {
			printf_s("%d", selectCourse[id][j]);
		}
		printf_s("\n");
	}
}