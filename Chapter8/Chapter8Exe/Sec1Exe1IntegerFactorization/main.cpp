/*
����һ����ά���飬����Ԫ�ص�ȡֵΪ0 ��1����ĳһ��Ԫ�����ڵ�Ԫ��Ϊ���ϡ��¡�
���ҡ�ǰ������6 ��������ڽ�Ԫ�ء����⣬���ɸ����ڵ�"1"��Ϊһ���� �飢
�������������ڣ�ֻҪ�����ĳһ��"1"���ڣ���"1"���ڿ��У��������ĳ������
��"1"�ĸ�������ǧT������ô�������Ϊ"���к���������������Ҫ����������к������е�1�ĸ���֮�͡�
*/

/*
1. ��ά01���󲻿�����Ϊbool�ͣ���������������ݻ�𰸴���
2. ����ʹ��DFS�ǳ�������������������г��ֶδ���ԭ����
����ά����������Ԫ�ؾ�Ϊ1ʱ��DFS����ȹ����ʹϵͳջ��
�����ޣ��Ӷ���ջ��
3. ��������ʱ�ǰ������ά����ķ�ʽ����ģ����3��forѭ��
�еĵ�һ����Ҫ���������ţ��ڶ���������ǵ�����������ݶ�
*/
#include <cstdio>
#include <queue>
using namespace std;

struct node {
	int x, y, z;
}Node;
int n, m, slice, T;	// ����Ϊn*m������slice�㣬TΪ���к�����1�ĸ�������
int pixel[1290][130][61];
bool inq[1290][130][61] = { false };	

int X[6] = { 0, 0, 0, 0, 1, -1 }; // ��������
int Y[6] = { 0, 0, 1, -1, 0, 0 };
int Z[6] = { 1 , -1, 0 , 0, 0, 0 };

bool judge(int x, int y, int z) {
	if (x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0) return false;
	if (pixel[x][y][z] == 0 || inq[x][y][z] == true) return false;
	return true;
}

int BFS(int x, int y, int z) {
	int tot = 0;	// ������ǰ����1 �ĸ���
	queue<node> Q;
	Node.x = x, Node.y = y, Node.z = z;
	Q.push(Node);
	inq[x][y][z] = true;
	while (!Q.empty()) {
		node top = Q.front();
		Q.pop();
		tot++;	// ��ǰ����1 �ĸ�����1
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
				// �����ǰλ��Ϊ1 , ��δ�����ʣ���BFS��ǰ��
				if (pixel[x][y][z] == 1 && inq[x][y][z] == false) {
					ans += BFS(x, y, z);
				}
			}
		}
	}
}