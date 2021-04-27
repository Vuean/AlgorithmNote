/*
给出一个三维数组，数组元素的取值为0 或1。与某一个元素相邻的元素为其上、下、
左、右、前、后这6 个方向的邻接元素。另外，若干个相邻的"1"称为一个“ 块＂
（不必两两相邻，只要与块中某一个"1"相邻，该"1"就在块中）。而如果某个块中
的"1"的个数不低千T个，那么称这个块为"卒中核心区”。现在需要求解所有卒中核心区中的1的个数之和。
*/

/*
1. 三维01矩阵不可设置为bool型，否则最后两组数据会答案错误。
2. 本题使用DFS非常容易在最后两组数据中出现段错误，原因是
当三维矩阵中所有元素均为1时，DFS的深度过深，会使系统栈达
到上限，从而爆栈。
3. 输入数据时是按多个二维矩阵的方式读入的，因此3层for循环
中的第一层需要遍历矩阵编号，第二、三层才是单个矩阵的数据读
*/
#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int x, y, z;
}Node;
int n, m, slice, T;	// 矩阵为n*m，共有slice层，T为卒中核心区1的个数下限
int pixel[1290][130][61];
bool inq[1290][130][61] = { false };	

int X[6] = { 0, 0, 0, 0, 1, -1 }; // 增量矩阵
int Y[6] = { 0, 0, 1, -1, 0, 0 };
int Z[6] = { 1 , -1, 0 , 0, 0, 0 };

bool judge(int x, int y, int z) {
	if (x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0) return false;
	if (pixel[x][y][z] == 0 || inq[x][y][z] == true) return false;
	return true;
}

int BFS(int x, int y, int z) {
	int tot = 0;	// 计数当前块中1 的个数
	queue<node> Q;
	Node.x = x, Node.y = y, Node.z = z;
	Q.push(Node);
	inq[x][y][z] = true;
	while (!Q.empty()) {
		node top = Q.front();
		Q.pop();
		tot++;	// 当前块中1 的个数加1
		for (int i = 0; i < 6; i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if (judge(newX, newY, newZ)) {
				Node.x = newX, Node.y = newY, Node.z = newZ;
				Q.push(Node);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	if (tot >= T) return tot;
	else return 0;
}

int main()
{
	scanf_s("%d%d%d%d", &n, &m, &slice, &T);
	for (int z = 0; z < slice; z++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				scanf_s("%d", &pixel[x][y][z]);
			}
		}
	}
	int ans = 0;
	for (int z = 0; z < slice; z++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				// 如果当前位置为1 , 且未被访问，则BFS当前块
				if (pixel[x][y][z] == 1 && inq[x][y][z] == false) {
					ans += BFS(x, y, z);
				}
			}
		}
	}
}