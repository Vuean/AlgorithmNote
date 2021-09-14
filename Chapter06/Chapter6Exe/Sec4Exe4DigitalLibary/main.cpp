/*
����N����ı�š����������ߡ��ؼ��ʣ������ж�����������缰������ݣ�
������M����ѯ��ÿ����ѯ�������������ߡ��ؼ��ʣ��������������缰
��������е�һ����Ҫ���������ø�����Ϣ��������ı�š�
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, set< int>> mpTitle, mpAuthor, mpKey, mpPub, mpYear;

// ��map�в���str
void query(map<string, set<int>>& mp, string& str) {
	if (mp.find(str) == mp.end()) cout << "Not Found" << endl;
	else {
		for (auto iter = mp[str].begin(); iter != mp[str].end(); iter++) {
			printf_s("%07d\n", *iter);
		}
	}
}

int main()
{
	int n, m, id, type;
	string title, author, key, pub, year;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &id);
		char c = getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
		while (cin >> key) {
			mpKey[key].insert(id);
			c = getchar();
			if (c == '\n') break;
		}
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[year].insert(id);
	}
	string temp;
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf_s("%d: ", &type);
		getline(cin, temp);
		cout << type << ": " << temp << endl;
		if (type == 1) query(mpTitle, temp);
		else if (type == 2) query(mpAuthor, temp);
		else if (type == 3) query(mpKey, temp);
		else if (type == 4) query(mpPub, temp);
		else query(mpYear, temp);
	}
}