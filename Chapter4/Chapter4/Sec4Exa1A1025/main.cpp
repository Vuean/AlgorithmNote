#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
	char	id[5];	// 准考证号
	int		score;	// 分数
	int		location_number;	// 考场号
	int		local_rank;	// 考场内排名
};

bool cmp(Student a, Student b)
{
	if (a.score != b.score) 
		return a.score > b.score;	// 先按分数从高到低排序
	else 
		return strcmp(a.id, b.id) < 0;	// 分数相同按准考证号从小到大排序
}

int main()
{
	int N, num = 0;
	cin >> N;
	Student stu[3000];
	for (int i = 1; i <= N; i++)
	{
		int K;
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> stu[j].id >> stu[j].score;
			stu[j].location_number = i;
			num++;
		}
		sort(stu + num - K, stu + num, cmp);	// 将该考场的考生排序
		stu[num - K].local_rank = 1;	// 该考场第1名记为1
		for (int j = num - K + 1; j < num; j++)
		{
			if (stu[j].score == stu[j - 1].score)
			{
				stu[j].local_rank = stu[j - 1].local_rank;
			}
			else
			{
				stu[j].local_rank = j + 1 - (num - K);
			}
		}
	}
	cout << num << endl;
	sort(stu, stu + num, cmp);
	int r = 1;
	for (int i = 0; i < num; i++)
	{
		if (i > 0 && stu[i].score != stu[i - 1].score)
		{
			r = i + 1;
		}
		cout << stu[i].id << " " << r << " "
			<< stu[i].location_number << " "
			<< stu[i].local_rank << endl;
	}
	return 0;
}