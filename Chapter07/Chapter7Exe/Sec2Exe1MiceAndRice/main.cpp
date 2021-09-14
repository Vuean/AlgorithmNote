/*
����NPֻ��������������������ǵĳ�ʼ˳�򣨾�����������ͣ��������
��ʼ˳�����Щ����ÿNGֻ��Ϊһ�飬��󲻹�NGֻ��Ҳ������Ϊһ�顣
��ÿ������ѡ����������������1ֻ�����������������������͵��ڸ���
���������������Щ�����������ٰ�����Ĳ���ÿNGֻ��Ϊһ����бȽϣ�
ѡ����������һ����������������ֱ�����ֻʣ��1ֻ��������Ϊ1��
����Щ�����������ԭ�����˳�������
*/
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;

struct node {
	int weight;	// ����
	int R;				// ����
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
		scanf_s("%d", &order);	// ��Ŀ������˳��
		q.push(order);
	}

	int temp = np, group;	// tempΪ��ǰ�ֵı�������������groupΪ����
	while (q.size() != 1) {
		if (temp % ng == 0) group = temp / ng;
		else group = temp / ng + 1;

		// ö��ÿһ�飬ѡ��������������������
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < ng; j++) {
				// �����һ��������ngʱ�����ã��˳�ѭ��
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
		temp = group;	// group��ֻ��groupֻ�������
	}
	mouse[q.front()].R = 1;
	// ���
	for (int i = 0; i < np; i++) {
		printf("%d", mouse[i].R);
		if (i < np - 1) printf(" ");
	}
}