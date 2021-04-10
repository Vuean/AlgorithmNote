/*
给出选课人数和课程数目，然后再给出每个人的选课情况，请针对每门课程输出选课人
数以及所有选该课的学生的姓名。
*/

/*
思路：
1. 以二维数组char[N][5]存放输入的姓名，其中char[i]表示第i个姓名。
以vector数组course[]存放选每门课的学生编号，其中course[i]存放
所有选第i门课的学生编号。
2. 在读入数据时，如果某学生(编号为i)选择了课程j，那么就将该学生的编号i
存到course[j]中
3. 对每一门课i,将course[i]中的学生按姓名字典序从小到大排序，
然后输出所需要的结果。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 40010;
const int maxc = 2510;		// 最大课程门数

char name[maxn][5];			// maxn个学生
vector<int> course[maxc];

bool cmp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;	// 按姓名字典序从小到大排序
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