/*
例题2：给定一个`n*m`大小的迷宫，其中*代表不可通过的墙壁，
而“.”代表平地，S表示起点，T代表终点。移动过程中，如果当前
位置是(x, y)（下标从0开始），且每次只能前往上下左右
(x, y+1)、(x, y-1)、(x-1,y)、（x+1, y)四个位置的平地，
求从起点S到达终点T的最少步数。
*/

#include <cstdio>
#include <string>
#include <queue>
using namespace std;

const int maxn = 100;
struct node {
	int x, y;
	int step;	// step为从起点S到达该位置的最少步数（即层数）
}S, T, Node;

int n, m;	// n为行，m为列
char maze[maxn][maxn];	// 迷宫信息
bool inq[maxn][maxn] = { false };	// 记录是否已入队
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
				// 位置(newX, newY)有效
				// 设置Node 的坐标为(newX, newY)
				Node.x = newX, Node.y = newY;
				Node.step = top.step + 1;
				q.push(Node);		// 将结点Node 加入队列
				inq[newX][newY] = true;
			}
		}
	}
	return -1;	// 无法到达终点T时返回－1
}

int main()
{
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		getchar();	// 过滤掉每行后面的换行符
		for (int j = 0; j < m; j++) {
			maze[i][j] = getchar();
		}
		maze[i][m + 1] = '\0';
	}
	scanf_s("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
	S.step = 0;
	printf("%d\n", BFS());
}