#include <iostream>
using namespace std;
int main()
{
	int a, b, d;
	cin >> a >> b >> d;
	int sum = a + b;
	int ans[31], num = 0;
	do {
		// ½øÖÆ×ª»»
		ans[num++] = sum % d;
		sum /= d;
	} while (sum != 0);
	for (int i = num - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
	cout << endl;
}