// [codeup 1918] �򵥼�����
/*
����һ��ֻ������, -, x, /�ķǸ�����������ʽ������ñ��ʽ��ֵ��
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node {
	double num;	// ������
	char op;			// ������
	bool flag;		// true��ʾ��������false��ʾ������
};

string str;
stack<node> s;	// ������ջ
queue<node> q;	// ����������
map<char, int> op;

void Change() {	// ����׺���ʽת��Ϊ��׺���ʽ
	double num;
	node temp;
	for (int i = 0; i < str.length();) {
		if (str[i] >= '0' && str[i] <= '9') {
			temp.flag = true;
			temp.num = str[i++] - '0';	// ��¼����
			while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else {
			temp.flag = false;	// �ǲ�����
			// ֻҪ������ջ��ջ��Ԫ�رȸò��������ȼ���
			// �ͰѲ�����ջջ��Ԫ�ص�������׺���ʽ�Ķ�����
			while (!s.empty() && op[str[i]] <= op[s.top().op]) {
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp); // �Ѹò�����ѹ�������ջ��
			i++;
		}
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}

double Cal() {	// �����׺���ʽ
	double temp1, temp2;
	node cur, temp;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.flag == true) s.push(cur);	// ����ǲ�������ֱ��ѹ��ջ
		else {
			temp2 = s.top().num;	// �����ڶ�������
			s.pop();
			temp1 = s.top().num;	// ������һ������
			s.pop();
			temp.flag = true;
			if (cur.op == '+') temp.num = temp1 + temp2;
			else if (cur.op == '-') temp.num = temp1 - temp2;
			else if (cur.op == '*') temp.num = temp1 * temp2;
			else temp.num = temp1 / temp2;
			s.push(temp);	// �Ѹò�����ѹ��ջ
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