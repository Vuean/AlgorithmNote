/*
n����Ʒ��ÿ����Ʒ������Ϊw[i]����ֵΪc[i]��������Ҫѡ�����ɼ���Ʒ����һ������ΪV�ı����У�
ʹ����ѡ�뱳������Ʒ�����Ͳ���������V��ǰ���£��ñ�������Ʒ�ļ�ֵ֮�����������ֵ��
*/

#include <cstdio>
const int maxn = 30;
int n, V, maxValue = 0;	// ��Ʒ����n����������V������ֵmaxValue

int w[maxn], c[maxn];	// w[i]Ϊÿ����Ʒ������V[i]Ϊ��ֵ

// DFS, index Ϊ��ǰ�������Ʒ���
// sumW ��sumC �ֱ�Ϊ��ǰ�������͵�ǰ�ܼ�ֵ\

// DFS����1
//void DFS(int index, int sumW, int sumC) {
//	if (index == n) {	// �Ѿ���ɶ�n����Ʒ��ѡ��
//		if (sumW <= V && sumC > maxValue) {
//			maxValue = sumC;	// ��������������ʱ��������ֵmaxValue
//		}
//		return;
//	}
//	// ��·��
//	DFS(index + 1, sumW, sumC);	// ��ѡ��index����Ʒ
//	DFS(index + 1, sumW + w[index], sumC + c[index]);	// ѡ��index����Ʒ
//}

// DFS����2
void DFS(int index, int sumW, int sumC) {
	if (index == n) {	// �Ѿ���ɶ�n����Ʒ��ѡ��
		return;
	}
	// ��·��
	DFS(index + 1, sumW, sumC);	// ��ѡ��index����Ʒ
	// ֻ�м����index����Ʒ��δ��������V, ���ܼ���
	if (sumW + w[index] <= V) {
		if (sumC + c[index] > maxValue) {
			maxValue = sumC + c[index];	// ��������ֵmaxValue
		}
	}
	DFS(index + 1, sumW + w[index], sumC + c[index]);	// ѡ��index����Ʒ
}

int main()
{
	scanf_s("%d %d", &n, &V);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &w[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &c[i]);	// ÿ����Ʒ�ļ�ֵ
	}

	DFS(0, 0, 0);
	printf("%d\n", maxValue);
}