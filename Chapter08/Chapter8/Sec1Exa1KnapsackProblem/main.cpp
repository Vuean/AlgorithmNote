/*
n件物品，每件物品的重量为w[i]，价值为c[i]。现在需要选出若干件物品放入一个容量为V的背包中，
使得在选入背包的物品重量和不超过容量V的前提下，让背包中物品的价值之和最大，求最大价值。
*/

#include <cstdio>
const int maxn = 30;
int n, V, maxValue = 0;	// 物品件数n，背包容量V，最大价值maxValue

int w[maxn], c[maxn];	// w[i]为每件物品重量，V[i]为价值

// DFS, index 为当前处理的物品编号
// sumW 和sumC 分别为当前总重量和当前总价值\

// DFS方法1
//void DFS(int index, int sumW, int sumC) {
//	if (index == n) {	// 已经完成对n件物品的选择
//		if (sumW <= V && sumC > maxValue) {
//			maxValue = sumC;	// 不超过背包容量时更新最大价值maxValue
//		}
//		return;
//	}
//	// 岔路口
//	DFS(index + 1, sumW, sumC);	// 不选第index件物品
//	DFS(index + 1, sumW + w[index], sumC + c[index]);	// 选第index件物品
//}

// DFS方法2
void DFS(int index, int sumW, int sumC) {
	if (index == n) {	// 已经完成对n件物品的选择
		return;
	}
	// 岔路口
	DFS(index + 1, sumW, sumC);	// 不选第index件物品
	// 只有加入第index件物品后未超过容量V, 才能继续
	if (sumW + w[index] <= V) {
		if (sumC + c[index] > maxValue) {
			maxValue = sumC + c[index];	// 更新最大价值maxValue
		}
	}
	DFS(index + 1, sumW + w[index], sumC + c[index]);	// 选第index件物品
}

int main()
{
	scanf_s("%d %d", &n, &V);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &w[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &c[i]);	// 每件物品的价值
	}

	DFS(0, 0, 0);
	printf("%d\n", maxValue);
}