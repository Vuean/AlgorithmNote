/*
����ʡ� �Ķ���Ϊ��Сд��ĸ�����ֵ���ϡ�����һ���ַ����� �ʳ��ִ������
�ĵ��ʼ�����ִ�����һ�г��˴�Сд��ĸ������֮����ַ�����Ϊ���ʵķָ�������
������ĸ�����ִ�Сд�������Сд��ĸ�����
*/

#include <iostream>
# include <string>
# include <map>
using namespace std;

bool check(char c) {	// ����ַ�c�Ƿ���[0,9], [a,z], [A,Z]
	if (c >= '0' && c <= '9') return true;
	if (c >= 'a' && c <= 'z') return true;
	if (c >= 'A' && c <= 'Z') return true;
	return false;
}

int main()
{
	map<string, int> count;
	string str;
	getline(cin, str);	// ���������ַ���
	int i = 0;
	while (i < (int)str.length()) {
		string word;
		while (i < (int)str.length() && check(str[i])) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 32;	// ����д��ĸת��ΪСд��ĸ
			}
			word += str[i];
			i++;
		}
		if (word != "") {
			if (count.find(word) == count.end()) {
				count[word] = 1;
			}
			else {
				count[word]++;
			}
		}
		while (i < (int)str.length() && !check(str[i])) {
			i++;
		}
	}
	string ans;
	int MAX = 0;
	for (auto iter = count.begin(); iter != count.end(); iter++) {
		if (iter->second > MAX) {
			ans = iter->first;
			MAX = iter->second;
		}
	}
	cout << ans << " " << MAX << endl;
}