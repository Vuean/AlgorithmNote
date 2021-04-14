/*
给出N 行M列的数字矩阵， 求其中超过半数的出现次数最多的数字。
*/

#include <cstdio>
#include <map>
using namespace std;

int main()
{
	int n, m, col;
	int k = 0, MAX = 0;
	scanf_s("%d%d", &n, &m);
	map<int, int> count;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &col);
			if (count.find(col) != count.end()) {
				count[col]++;
				if (count[col] >= (m * n) / 2) {
					k = col;
				}
			}
			else {
				count[col] = 1;
			}
		}
	}
	
	/*for (auto it = count.begin(); it != count.end(); it++) {
		if (it->second > MAX) {
			k = it->first;
			MAX = it->second;
		}
	}*/
	printf_s("%d\n", k);
}