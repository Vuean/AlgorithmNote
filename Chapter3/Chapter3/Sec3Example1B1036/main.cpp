#include<iostream>
using namespace std;
int main()
{
	int N;
	char C;
	cin >> N >> C;
	int row = 0;		// ���������
	if (N % 2 == 0)
		row = N / 2;
	else
		row = N / 2 + 1;
	// �����һ��
	for (int i = 0; i < N; i++)
		cout << C;
	cout << endl;

	// ����м���
	for (int i = 2; i < row; i++)
	{
		cout << C;
		for (int j = 0; j < N-2; j++)
		{
			cout << " ";
		}
		cout << C << endl;
	}

	// ������һ��
	for (int i = 0; i < N; i++)
		cout << C;
}