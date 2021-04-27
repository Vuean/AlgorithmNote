/*
����1������һ��m x n�ľ��󣬾����е�Ԫ��Ϊ0��1����λ��(x, y)������������
�ĸ�λ��(x, y+1)��(x, y-1)��(x+1 , y)��(x-1, y)�����ڵġ������������
���ɸ�1�����ڵģ������������ڣ�����ô����Щ1������һ�����顱��
������ľ����С��顱�ĸ�����
*/

#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;
struct node {
	int x, y;
}Node;

int n, m;	// �����СΪn*m
int matrix[maxn][maxn];					// 01����
bool inq[maxn][maxn] = { false };	// ��¼(x, y)�Ƿ��������
int X[4] = { 0, 0, 1, -1 };
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y) {
	// �ж�����(x, y) �Ƿ���Ҫ����
	// Խ�緵��false
	if (x >= n || x < 0 || y > m || y < 0) return false;
	// ��ǰλ��Ϊ0, ��x, y) ������ӣ�����false
	if (matrix[x][y] == 0 || inq[x][y] == true) return false;
	return true;
}

// BFS ��������λ��(x, y)���ڵĿ飬 
// ���ÿ������С� 1 " ��inq������Ϊtrue
void BFS(int x, int y) {
	queue<node> Q;
	Node.x = x, Node.y = y;	// ��ǰ��������Ϊ(x, y)
	Q.push(Node);					// �����Node���
	inq[x][y] = true;			// ����(x, y)�������
	while (!Q.empty()) {
		node top = Q.front();	// ȡ������Ԫ��
		Q.pop();						// ����Ԫ�س���
		for (int i = 0; i < 4; i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			if (judge(newX, newY)) {
				// �����λ��(newX, newY)��Ҫ����
				// ����Node ������Ϊ(newX, newY)
				Node.x = newX, Node.y = newY;
				Q.push(Node);		// �����Node �������
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
			// ���Ԫ��Ϊ1, ��δ�����
			if (matrix[i][j] == 1 && inq[i][j] == false) {
				ans++;		// ������1
				BFS(i, j);
			}
		}
	}
	printf("%d\n", ans);
}