/*
����������֮���ͨ�����ȣ���Ϊ����ߣ�����Щͨ��������
��Ϊ�����顣ÿ������ܱ�Ȩ��Ϊ�����ڵ�����ͨ���ĳ���֮
�ͣ���ÿ���˵ĵ�Ȩ��Ϊ���˲����ͨ������֮�͡����ڸ���
һ����ֵK,��ֻҪһ������ܱ�Ȩ����K, �������Ա��������
2,�򽫸�����Ϊ�������Ż�(Gang)",�������ڵ�Ȩ��������
ΪͷĿ��Ҫ������������Ż�ĸ���������ͷĿ�����ֵ����
С�����˳�����ÿ���� �����Ż��ͷĿ�����ͳ�Ա������
*/

/*
����1�� ����Ҫ������������������ŵĶ�Ӧ��ϵ��
����2 : ������Ŀ�е�Ҫ�� ��Ҫ���ÿ���˵ĵ�Ȩ��
����֮��ص�ͨ����¼��ʱ��֮��
����3 : ����ͼ�ı�����
����4 : ͨ������3���Ի����ͨ����ܱ�ȨtotalValue
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;	// ������
const int INF = 10000000000000;	// �����

map<int, string> IntToString;		// ���->����
map<string, int> StringToInt;		// ����->���
map<string, int> Gang;						// head->����
int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };	// �ڽӾ���G����Ȩweight
int n, k, numPerson = 0;	// ����n������K��������numPerson
bool vis[maxn] = { false };	// ����Ƿ����

// DFS�������ʵ�����ͨ�飬nowVisitΪ��ǰ���ʵı��
// head ΪͷĿ��numMember ��Ա��ţ�totalValueΪ��ͨ����ܱ�Ȩ
void DFS(int nowVisit, int& head, int& numMember, int& totalValue)
{
	numMember++;					// ��Ա������1
	vis[nowVisit] = true;	// ���nowVisit�ѷ���
	if (weight[nowVisit] > weight[head])
	{
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++)
	{
		if (G[nowVisit][i] > 0)// �����nowVisit�ܵ���i
		{
			totalValue += G[nowVisit][i];	// ��ͨ����ܱ�Ȩ���Ӹñ�Ȩ
			G[nowVisit][i] = G[i][nowVisit] = 0;	// ɾ�������ߣ� ��ֹ��ͷ 
			if (vis[i] == false)
			{
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}

// DFSTrave������������ͼ��ȡÿ����ͨ�����Ϣ
void DFSTrave()
{
	for (int i = 0; i < numPerson; i++)
	{
		if (vis[i] == false)
		{
			int head = i, numMember = 0,totalValue = 0;	// ͷĿ����Ա�����ܱ�Ȩ
			DFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k)
			{
				Gang[IntToString[head]] = numMember;
			}
		}
	}
}

// change ������������str ��Ӧ�ı��
int change(string str)
{
	if (StringToInt.find(str) != StringToInt.end())
	{
		return StringToInt[str];
	}
	else 
	{
		StringToInt[str] = numPerson;
		IntToString[numPerson] = str;
		return numPerson++;
	}
}

int main()
{
	int w;
	string str1, str2;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> str1 >> str2 >> w;	// ����ߵ������˵�͵�Ȩ
		int id1 = change(str1);		// ��str1ת��Ϊ���id1
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>::iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}