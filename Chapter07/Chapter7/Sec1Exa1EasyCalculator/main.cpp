// [codeup 1918] 简单计算器
/*
读入一个只包含＋, -, x, /的非负整数计算表达式，计算该表达式的值。
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node {
	double num;	// 操作数
	char op;			// 操作符
	bool flag;		// true表示操作数，false表示操作符
};

string str;
stack<node> s;	// 操作符栈
queue<node> q;	// 操作数队列
map<char, int> op;

void Change() {	// 将中缀表达式转换为后缀表达式
	double num;
	node temp;
	for (int i = 0; i < str.length();) {
		if (str[i] >= '0' && str[i] <= '9') {
			temp.flag = true;
			temp.num = str[i++] - '0';	// 记录数字
			while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else {
			temp.flag = false;	// 是操作符
			// 只要操作符栈的栈顶元素比该操作符优先级高
			// 就把操作符栈栈顶元素弹出到后缀表达式的队列中
			while (!s.empty() && op[str[i]] <= op[s.top().op]) {
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp); // 把该操作符压入操作符栈中
			i++;
		}
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}

double Cal() {	// 计算后缀表达式
	double temp1, temp2;
	node cur, temp;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.flag == true) s.push(cur);	// 如果是操作数，直接压入栈
		else {
			temp2 = s.top().num;	// 弹出第二操作数
			s.pop();
			temp1 = s.top().num;	// 弹出第一操作数
			s.pop();
			temp.flag = true;
			if (cur.op == '+') temp.num = temp1 + temp2;
			else if (cur.op == '-') temp.num = temp1 - temp2;
			else if (cur.op == '*') temp.num = temp1 * temp2;
			else temp.num = temp1 / temp2;
			s.push(temp);	// 把该操作数压入栈
		}
	}
	return s.top().num;
}

int main()
{
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	while (getline(cin, str), str != "0") {
		for (string::iterator it = str.end(); it != str.begin(); it--) {
			if (*it == ' ') str.erase(it);
		}
		while (!s.empty()) s.pop();
		Change();
		cout << Cal() << endl;
	}
}