/*
����ѡ�������Ϳγ���Ŀ��Ȼ���ٸ���ÿ���˵�ѡ������������ÿ�ſγ����ѡ����
���Լ�����ѡ�ÿε�ѧ����������
*/

/*
˼·��
1. �Զ�ά����char[N][5]������������������char[i]��ʾ��i��������
��vector����course[]���ѡÿ�ſε�ѧ����ţ�����course[i]���
����ѡ��i�ſε�ѧ����š�
2. �ڶ�������ʱ�����ĳѧ��(���Ϊi)ѡ���˿γ�j����ô�ͽ���ѧ���ı��i
�浽course[j]��
3. ��ÿһ�ſ�i,��course[i]�е�ѧ���������ֵ����С��������
Ȼ���������Ҫ�Ľ����
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 40010;
const int maxc = 2510;		// ���γ�����

char name[maxn][5];			// maxn��ѧ��
vector<int> course[maxc];

bool cmp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;	// �������ֵ����С��������
}

int main()
{
	int n, k, c, courseID;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf_s("%s %d", name[i], &c);
		for (int j = 0; j < c; j++) {
			cin >> courseID;
			course[courseID].push_back(i);
		}
	}
	for (int i = 1; i <= k; i++) {
		printf_s("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0; j < course[i].size(); j++) {
			printf_s("%s\n", name[course[i][j]]);
		}
	}
}