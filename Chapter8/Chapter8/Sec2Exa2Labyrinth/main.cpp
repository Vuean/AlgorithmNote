/*
����2������һ��`n*m`��С���Թ�������*������ͨ����ǽ�ڣ�
����.������ƽ�أ�S��ʾ��㣬T�����յ㡣�ƶ������У������ǰ
λ����(x, y)���±��0��ʼ������ÿ��ֻ��ǰ����������
(x, y+1)��(x, y-1)��(x-1,y)����x+1, y)�ĸ�λ�õ�ƽ�أ�
������S�����յ�T�����ٲ�����
*/

#include <cstdio>
#include <string>
#include <queue>
using namespace std;

const int maxn = 100;
struct node {
	int x, y;
	int step;	// stepΪ�����S�����λ�õ����ٲ�������������
}S, T, Node;

int n, m;	// nΪ�У�mΪ��
char maze[maxn][maxn];	// �Թ���Ϣ
bool inq[maxn][maxn] = { false };	// ��¼�Ƿ������
int X[4] = { 0, 0, 1, -1 };
int Y[4] = { 1, -1, 0, 0 };

bool test(int x, int y) {
	if (x >= n || x < 0 || y > m || y < 0) return false;
	if (maze[x][y] == '*') return false;
	if (inq[x][y] == true) return false;
	return true;
}

int BFS() {
	queue<node> q;
	q.push(S);
	while (!q.empty()) {
		node top = q.front();
		q.pop();
		if (top.x == T.x && top.y == T.y) {
			return top.step;
		}
		for (int i = 0; i < 4; i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			if (test(newX, newY)) {
				// λ��(newX, newY)��Ч
				// ����Node ������Ϊ(newX, newY)
				Node.x = newX, Node.y = newY;
				Node.step = top.step + 1;
				q.push(Node);		// �����Node �������
				inq[newX][newY] = true;
			}
		}
	}
	return -1;	// �޷������յ�Tʱ���أ�1
}

int main()
{
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		getchar();	// ���˵�ÿ�к���Ļ��з�
		for (int j = 0; j < m; j++) {
			maze[i][j] = getchar();
		}
		maze[i][m + 1] = '\0';
	}
	scanf_s("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
	S.step = 0;
	printf("%d\n", BFS());
}