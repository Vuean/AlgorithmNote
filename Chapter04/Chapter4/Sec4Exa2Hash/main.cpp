#include <iostream>
using namespace std;

const int maxn = 100;
char S[maxn][5], temp[5];
int hashTable[26 * 26 * 26 + 10];

int hashFunc(char S[], int len)
{
	int id = 0;
	for (int i = 0; i < len; i++)
		id = id * 26 + (S[i] - 'A');
	return id;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> S[i];
		int id = hashFunc(S[i], 3);
		hashTable[id]++;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		int id = hashFunc(temp, 3);
		cout << hashTable[id] << endl;
	}
	return 0;
}