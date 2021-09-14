// [codeup 1934] евx
#include <iostream>
using namespace std;
const int maxn = 201;
int num[maxn];

int main()
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	cin >> x;
	int k = 0;
	for (; k < n; k++)
	{
		if (num[k] == x)
		{
			cout << k << endl;
			break;
		}
	}
	if (k == n)
		cout << -1 << endl;
}