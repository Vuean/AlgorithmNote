/*
题意：
输入四个整数N1，N2，tag，radix。其中tag==1表示N1为radix进制数，
tag==2表示N2为radix进制数。范围：N1和N2均不超过10个数位，且每个数位均为
0~9或a~z，其中0~9表示数字0~9，a~z表示数字10~35。

求N1和N2中未知进制的那个数是否存在，并满足某个进制时和另外一个数
在十进制下相等的条件。若存在，则输出满足条件的最小进制，否则输出Impossible
*/

/*
注意点：
1.使用遍历进制的暴力枚举会超时。
2.本题的变量尽量使用long long 类型。
3. 当N1和N2相等时， 输出题目给定的radix值。
4.N2进制的下界为所有数位中最大的那个加 1，
上界为下界与 N1进制的较大值加1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL Map[256];			// 0~9、a~z与0~35的对应
LL inf = (1LL << 63) - 1;		// long long的最大值2^63-1

void init()
{
	for (char c = '0'; c <= '9'; c++)
	{
		Map[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		Map[c] = c - 'a' + 10;
	}
}

// 将a转换为十进制，t为上界
LL convertNum10(char a[], LL radix, LL t)
{
	LL ans = 0;
	int len = (int)strlen(a);
	for (int i = 0; i < len; i++)
	{
		ans = ans * radix + Map[a[i]];
		if (ans < 0 || ans > t) return -1;
	}
	return ans;
}

// N2的十进制与t比较
int cmp(char N2[], LL radix, LL t)
{
	int len = (int)strlen(N2);
	LL num = convertNum10(N2, radix, t);
	if (num < 0) return 1;
	if (t > num) return -1;
	else if (t == num) return 0;
	else return 1;	// num较大，返回1
}

//  二分求解N2 的进制
LL binarySearch(char N2[], LL left, LL right, LL t)
{
	LL mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);	// 判断N2 转换为十进制后与t 比较
		if (flag == 0) return mid;
		else if (flag == -1) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

// 求最大的数位
int findLargestDigit(char N2[])
{
	int ans = -1, len = (int)strlen(N2);
	for (int i = 0; i < len; i++)
	{
		if (Map[N2[i]] > ans)
		{
			ans = Map[N2[i]];
		}
	}
	return ans + 1;
}

char N1[20], N2[20], temp[20];
int tag, radix;

int main()
{
	init();
	cin >> N1 >> N2 >> tag >> radix;
	if (tag == 2)
	{
		strcpy_s(temp, N1);
		strcpy_s(N1, N2);
		strcpy_s(N2, temp);
	}

	LL t = convertNum10(N1, radix, inf);
	LL low = findLargestDigit(N2);	// 找到N2中数位最大的位加1，当成二分下界
	LL high = max(low, t) + 1; // 上界
	LL ans = binarySearch(N2, low, high, t);
	if (ans == -1) cout << "Impossible\n";
	else cout << "Ans = " << ans;
}