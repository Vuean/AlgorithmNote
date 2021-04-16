/*
令“单词” 的定义为大小写字母、数字的组合。给出一个字符串， 问出现次数最多
的单词及其出现次数（一切除了大小写字母、数字之外的字符都作为单词的分隔符）。
其中字母不区分大小写，且最后按小写字母输出。
*/

#include <iostream>
# include <string>
# include <map>
using namespace std;

bool check(char c) {	// 检查字符c是否是[0,9], [a,z], [A,Z]
	if (c >= '0' && c <= '9') return true;
	if (c >= 'a' && c <= 'z') return true;
	if (c >= 'A' && c <= 'Z') return true;
	return false;
}

int main()
{
	map<string, int> count;
	string str;
	getline(cin, str);	// 读入整行字符串
	int i = 0;
	while (i < (int)str.length()) {
		string word;
		while (i < (int)str.length() && check(str[i])) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 32;	// 将大写字母转化为小写字母
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