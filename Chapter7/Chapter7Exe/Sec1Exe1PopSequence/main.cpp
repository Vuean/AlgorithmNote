/*
��һ����������ΪM ��ջ���ȷֱ��1 ,2,3,..,n ������ջ��������һϵ��
��ջ˳������Щ��ջ˳���Ƿ���ܡ�
*/

#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

const int maxn = 1010;
int arr[maxn];	// �����ջ����
stack<int> st;	// ����ջst
int main()
{
	int m, n, T;	// mΪջ���������nΪ��ջ���ȣ�TΪ��ջ������Ŀ
	scanf_s("%d%d%d", &m, &n, &T);
	while (T--) {// ѭ��ִ��T��
		while (!st.empty()) {	// ���ջ
			st.pop();
		}
		for (int i = 1; i <= n; i++) {
			// cin >> arr[i];
			scanf_s("%d", &arr[i]);
		}
		int current = 1;	// ָ���ջ�����еĴ���ջԪ��
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			st.push(i);	// ��iѹ��ջ
			if (st.size() > m) {	// �����ʱջ��Ԫ�ظ�����������m, �����зǷ�
				flag = false;
				break;
			}
			// ջ��Ԫ�����ջ���е�ǰλ�õ�Ԫ����ͬ��
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