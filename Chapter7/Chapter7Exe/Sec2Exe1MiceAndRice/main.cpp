/*
给出NP只老鼠的质量，并给出它们的初始顺序（具体见样例解释），按这个
初始顺序把这些老鼠按每NG只分为一组，最后不够NG只的也单独分为一组。
对每组老鼠，选出它们中质量最大的1只晋级，这样晋级的老鼠数就等于该轮
分组的组数。对这些晋级的老鼠再按上面的步骤每NG只分为一组进行比较，
选出质量最大的一批继续晋级，这样直到最后只剩下1只老鼠，排名为1。
把这些老鼠的排名按原输入的顺序输出。
*/
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;

struct node {
	int weight;	// 质量
	int R;				// 排名
}mouse[maxn];

int main()
{
	int np, ng, order;
	scanf_s("%d%d", &np, &ng);
	for (int i = 0; i < np; i++) {
		scanf_s("%d", &mouse[i].weight);
	}

	queue<int> q;
	for (int i = 0; i < np; i++) {
		scanf_s("%d", &order);	// 题目给出的顺序
		q.push(order);
	}

	int temp = np, group;	// temp为当前轮的比赛老鼠总数，group为组数
	while (q.size() != 1) {
		if (temp % ng == 0) group = temp / ng;
		else group = temp / ng + 1;

		// 枚举每一组，选出改组中老鼠质量最大的
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < ng; j++) {
				// 在最后一组老鼠不足ng时其租用，退出循环
				if (i * ng + j >= temp) break;
				int front = q.front();
				if (mouse[front].weight > mouse[k].weight){
					k = front;
				}
				mouse[front].R = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;	// group组只有group只老鼠晋级
	}
	mouse[q.front()].R = 1;
	// 输出
	for (int i = 0; i < np; i++) {
		printf("%d", mouse[i].R);
		if (i < np - 1) printf(" ");
	}
}