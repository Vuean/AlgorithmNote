/*
例题1：给出一个m x n的矩阵，矩阵中的元素为0或1。称位置(x, y)与其上下左右
四个位置(x, y+1)、(x, y-1)、(x+1 , y)、(x-1, y)是相邻的。如果矩阵中有
若干个1是相邻的（不必两两相邻），那么称这些1构成了一个“块”。
求给定的矩阵中“块”的个数。
*/

#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;
struct node {
	int x, y;
}Node;

int n, m;	// 矩阵大小为n*m
int matrix[maxn][maxn];					// 01矩阵
bool inq[maxn][maxn] = { false };	// 记录(x, y)是否已入过队
int X[4] = { 0, 0, 1, -1 };
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y) {
	// 判断坐标(x, y) 是否需要访问
	// 越界返回false
	if (x >= n || x < 0 || y > m || y < 0) return false;
	// 当前位置为0, 或（x, y) 已入过队，返回false
	if (matrix[x][y] == 0 || inq[x][y] == true) return false;
	return true;
}

// BFS 函数访问位置(x, y)所在的块， 
// 将该块中所有“ 1 " 的inq都设置为true
void BFS(int x, int y) {
	queue<node> Q;
	Node.x = x, Node.y = y;	// 当前结点的坐标为(x, y)
	Q.push(Node);					// 将结点Node入队
	inq[x][y] = true;			// 设置(x, y)已入过队
	while (!Q.empty()) {
		node top = Q.front();	// 取出队首元素
		Q.pop();						// 队首元素出队
		for (int i = 0; i < 4; i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			if (judge(newX, newY)) {
				// 如果新位置(newX, newY)需要访问
				// 设置Node 的坐标为(newX, newY)
				Node.x = newX, Node.y = newY;
				Q.push(Node);		// 将结点Node 加入队列
				inq[newX][newY] = true;
			}
		}
	}
}

int main()
{
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 如果元素为1, 且未入过队
			if (matrix[i][j] == 1 && inq[i][j] == false) {
				ans++;		// 块数加1
				BFS(i, j);
			}
		}
	}
	printf("%d\n", ans);
}