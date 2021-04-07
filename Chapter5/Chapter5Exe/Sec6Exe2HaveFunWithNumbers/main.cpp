/*
给出一个长度不超过20 的整数，问这个整数两倍后的数位是否为原数数位的一个排列。
*/

/*
1234567899中，数字1 ~ 8 均出现了一次，而9出现了两次；2469135798中
，数字1 ~8也都出现了一次，9出现了两次。
所以2469135798是1234567899的数位的一个排列，输出"Yes”。
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
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

bign multi(bign a, int b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0) {
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

bool Judge(bign a, bign b) {
	if (a.len != b.len) return false;
	int count[10] = { 0 };
	for (int i = 0; i < a.len; i++) {
		count[a.d[i]]++;
		count[b.d[i]]--;
	}
	for (int i = 0; i < 10; i++) {
		if (count[i] != 0) {
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
	char str[21];
	cin >> str;
	bign a = change(str);
	bign mul = multi(a, 2);
	if (Judge(a, mul)) cout << "Yes" << endl;
	else cout << "No" << endl;
	print(mul);
}