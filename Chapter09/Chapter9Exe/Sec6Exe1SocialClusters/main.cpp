/*
��N ���ˣ�ÿ����ϲ�������������������������һ����
����ͬ����ô�ͳ����Ǵ���ͬһ���罻���磨��A��B����ͬһ
���罻���磬B��C����ͬһ���罻���磬��ôA��B��C����ͬ
һ���罻���磩������N�����ܹ��γ��˶��ٸ��罻���硣
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int father[N];				// ��Ÿ��׽ڵ�
int isRoot[N] = { 0 };	// ��¼ÿ������Ƿ���Ϊĳ�����ϵĸ����
int course[N] = { 0 };
int findFather(int x)
{
	int a = x;
	while (x != father[x])
	{
		x = father[x];
	}
	// ·��ѹ��
	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
	{
		father[faA] = faB;
	}
}

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		isRoot[i] = false;
	}
}

// ��isRoot����Ӵ�С����
bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n, k, h;
	scanf_s("%d", &n);	// ����
	init(n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d:", &k);	// �����
		for (int j = 0; j < k; j++)
		{
			scanf_s("%d", &h);
			if (course[h] == 0)	// ����h��һ������ϲ��
			{
				course[h] = i;
			}
			Union(i, findFather(course[h]));
		}
	}

	for (int i = 1; i <= n; i++)
	{
		isRoot[findFather(i)]++;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isRoot[i] != 0)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	sort(isRoot+1, isRoot + n+1, cmp);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", isRoot[i]);
		if (i < ans) printf(" ");
	}
}