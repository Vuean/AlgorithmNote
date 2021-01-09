// [PATB1032] 挖掘机技术哪家强
/*
请根据比赛结果统计出技术最强的那个学校。
输入：
	在第1行给出不超过10^5的正整数N, 即参赛人数。随后N行，每行给出一位参赛者的
信息和成绩， 包括其所代表的学校的编号（从1开始连续编号）及其比赛成绩（百分制），中
间以空格分隔。
输出：
	在一行中给出总得分最高的学校的编号及其总分，中间以空格分隔。题目保证答案唯一，
没有并列。
*/
#include <iostream>
using namespace std;

const int maxnum = 100;
int school[maxnum] = { 0 };	// 记录每个学校的总分

int main()
{
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;	// 输入学校ID和分数
		school[a] += b;
	}
	int index = 1, maxscore = 0;	// 最高总分的学校ID和总分
	for (int i = 1; i <= n; i++)
	{
		if (school[i] > maxscore)
		{
			maxscore = school[i];
			index = i;
		}
	}
	cout << index << " " << maxscore << endl;
}