/*
有一个容量限制为M 的栈，先分别把1 ,2,3,..,n 依次入栈，并给出一系列
出栈顺序，问这些出栈顺序是否可能。
*/

#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

const int maxn = 1010;
int arr[maxn];	// 保存出栈序列
stack<int> st;	// 定义栈st
int main()
{
	int m, n, T;	// m为栈最大容量，n为入栈长度，T为出栈序列数目
	scanf_s("%d%d%d", &m, &n, &T);
	while (T--) {// 循环执行T次
		while (!st.empty()) {	// 清空栈
			st.pop();
		}
		for (int i = 1; i <= n; i++) {
			// cin >> arr[i];
			scanf_s("%d", &arr[i]);
		}
		int current = 1;	// 指向出栈序列中的待出栈元素
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			st.push(i);	// 把i压入栈
			if (st.size() > m) {	// 如果此时栈中元素个数大于容量m, 则序列非法
				flag = false;
				break;
			}
			// 栈顶元素与出栈序列当前位置的元素相同是
			while (!st.empty() && st.top() == arr[current]) {
				st.pop();
				current++;
			}
		}
		if (st.empty() && flag == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}