/*
本题要求计算A/B, 其中A 是不超过1 000位的正整数，B是1位正整数。
请输出商数Q和余数R, 使得A =B * Q +R 成立。
*/

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct bign {
	int d[1000];
	int len;

	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

bign divide(bign a, int b, int& r) {
	bign c;
	c.len = a.len;
	for (int i = a.len - 1; i >= 0; i--) {
		r = r * 10 + a.d[i];
		if (r < b) c.d[i] = 0;
		else {
			c.d[i] = r / b;	// 商
			r = r % b;
		}
	}
	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
		c.len--;
	}
	return c;
}

void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		cout << a.d[i];
	}
}

int main()
{
	char str1[1010], str2[1010];
	int b, r = 0;
	cin >> str1 >> b;
	bign a = change(str1);
	print(divide(a, b, r));
	cout << " " << r << endl;
}