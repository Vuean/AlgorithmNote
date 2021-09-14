# include <cstdio>
# include <iostream>
# include <string>
# include <map>
using namespace std;

// [0, 12]������
string unitDigit[13] = { "tret", "jan", "feb", "mar", "apr",
	"may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };

// 13��[0, 12]���Ļ�����
string tenDigit[13] = { "tret", "tam", "hel", "maa", "huh",
	"tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

string numToStr[170]; // ����to������
map<string, int> strToNum;	// ������to����

void init() {
	for (int i = 0; i < 13; i++) {
		numToStr[i] = unitDigit[i];
		strToNum[unitDigit[i]] = i;
		numToStr[i * 13] = tenDigit[i];
		strToNum[tenDigit[i]] = i * 13;
	}
	for (int i = 1; i < 13; i++) {	// ʮλ
		for (int j = 1; j < 13; j++) {	// ��λ
			string str = tenDigit[i] + " " + unitDigit[j];
			numToStr[i * 13 + j] = str;
			strToNum[str] = i * 13 + j;
		}
	}
}

int main()
{
	init();
	int T;
	scanf_s("%d%*c", &T);
	while (T--) {
		string str;
		getline(cin, str);
		if (str[0] >= '0' && str[0] <= '9') {
			int num = 0;
			for (int i = 0; i < str.length(); i++) {
				num = num * 10 + (str[i] - '0');
			}
			cout << numToStr[num] << endl;
		}
		else {
			cout << strToNum[str] << endl;
		}
	}
}