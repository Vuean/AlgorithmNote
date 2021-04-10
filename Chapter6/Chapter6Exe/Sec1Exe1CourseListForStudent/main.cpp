/*
有N个学生， K门课。现在给出选择每门课的学生姓名，
并在之后给出N个学生的姓名，要求按顺序给出每个学生的选课情况。
*/

/*
注意点：
1. 使用map、string会导致超时，因此类似map<string, vector<int>>
或者map<string, set<int>>的写法都是不行的。
2.由于数据量庞大，因此请不要使用cin和cout进行输入和输出。
3. 如果使用二维数组存放学生所选的课程编号，会导致最后一组数据内存超限，
因此需要使用vector来减少空间消耗。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 40010;

// 用字符串hash求解
int getID(char name[]) {	// hash函数，将name转为数字
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}

// 建立vector数组来存放不同学生各自选择的所有课程的编号。
const int M = 26 * 26 * 26 * 10 + 1;	// 名字散列成的数字上界
vector<int> selectCourse[M];			// 每个学生选择的课程编号

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

	// n个查询
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