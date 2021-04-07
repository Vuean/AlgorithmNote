/*
定义一种操作： 让一个整数加上这个整数首尾颠倒后的数字。
例如对整数1257执行操作就是1257 + 7521 = 8778。现在给出一个正整数和操作次数限制，
问在限定的操作次数内能是否能得到回文数。如果能得到，则输出那个回文数，
并输出操作的次数； 否则， 输出最后一次操作得到的数字以及操作次数。
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

bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

bool Judge(bign a) {
	for (int i = 0; i <= a.len / 2; i++) {
		if (a.d[i] != a.d[a.len - 1 - i]) {
			return false;
		}
	}
	return true;
}

void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		cout << a.d[i];
	}
}

int main()
{
	char str[1000];
	int T, k = 0;
	cin >> str >> T;
	bign a = change(str);
	while (k < T && Judge(a) == false) {
		bign b = a;
		reverse(b.d, b.d + b.len);	// 将b倒置
		a = add(a, b);
		k++;
	}
	print(a);
	cout << k << endl;
}