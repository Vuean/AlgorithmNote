#include<iostream>
using namespace std;
int main()
{
	int N;
	char C;
	cin >> N >> C;
	int row = 0;		// 输出的行数
	if (N % 2 == 0)
		row = N / 2;
	else
		row = N / 2 + 1;
	// 输出第一行
	for (int i = 0; i < N; i++)
		cout << C;
	cout << endl;

	// 输出中间行
	for (int i = 2; i < row; i++)
	{
		cout << C;
		for (int j = 0; j < N-2; j++)
		{
			cout << " ";
		}
		cout << C << endl;
	}

	// 输出最后一行
	for (int i = 0; i < N; i++)
		cout << C;
}