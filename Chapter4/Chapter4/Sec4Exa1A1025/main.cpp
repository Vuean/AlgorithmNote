#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
	char	id[5];	// ׼��֤��
	int		score;	// ����
	int		location_number;	// ������
	int		local_rank;	// ����������
};

bool cmp(Student a, Student b)
{
	if (a.score != b.score) 
		return a.score > b.score;	// �Ȱ������Ӹߵ�������
	else 
		return strcmp(a.id, b.id) < 0;	// ������ͬ��׼��֤�Ŵ�С��������
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
		sort(stu + num - K, stu + num, cmp);	// ���ÿ����Ŀ�������
		stu[num - K].local_rank = 1;	// �ÿ�����1����Ϊ1
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