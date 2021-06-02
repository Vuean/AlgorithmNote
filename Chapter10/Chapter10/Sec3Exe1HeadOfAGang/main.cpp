/*
给出若干人之间的通话长度（视为无向边），这些通话将他们
分为若干组。每个组的总边权设为该组内的所有通话的长度之
和，而每个人的点权设为该人参与的通话长度之和。现在给定
一个阈值K,且只要一个组的总边权超过K, 并满足成员人数超过
2,则将该组视为“犯罪团伙(Gang)",而该组内点权最大的人视
为头目。要求输出“犯罪团伙＂的个数，并按头目姓名字典序从
小到大的顺序输出每个“ 犯罪团伙＂的头目姓名和成员人数。
*/

/*
步骤1： 首先要解决的问题是姓名与编号的对应关系。
步骤2 : 根据题目中的要求， 需要获得每个人的点权，
即与之相关的通话记录的时长之和
步骤3 : 进行图的遍历。
步骤4 : 通过步骤3可以获得连通块的总边权totalValue
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;	// 总人数
const int INF = 10000000000000;	// 无穷大

map<int, string> IntToString;		// 编号->姓名
map<string, int> StringToInt;		// 姓名->编号
map<string, int> Gang;						// head->人数
int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };	// 邻接矩阵G，点权weight
int n, k, numPerson = 0;	// 边数n、下限K、总人数numPerson
bool vis[maxn] = { false };	// 标记是否访问

// DFS函数访问单个连通块，nowVisit为当前访问的编号
// head 为头目，numMember 成员编号，totalValue为连通块的总边权
void DFS(int nowVisit, int& head, int& numMember, int& totalValue)
{
	numMember++;					// 成员人数加1
	vis[nowVisit] = true;	// 标记nowVisit已访问
	if (weight[nowVisit] > weight[head])
	{
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++)
	{
		if (G[nowVisit][i] > 0)// 如果从nowVisit能到达i
		{
			totalValue += G[nowVisit][i];	// 连通块的总边权增加该边权
			G[nowVisit][i] = G[i][nowVisit] = 0;	// 删除这条边， 防止回头 
			if (vis[i] == false)
			{
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}

// DFSTrave函数遍历整个图获取每个连通块的信息
void DFSTrave()
{
	for (int i = 0; i < numPerson; i++)
	{
		if (vis[i] == false)
		{
			int head = i, numMember = 0,totalValue = 0;	// 头目、成员数、总边权
			DFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k)
			{
				Gang[IntToString[head]] = numMember;
			}
		}
	}
}

// change 函数返回姓名str 对应的编号
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
		cin >> str1 >> str2 >> w;	// 输入边的两个端点和点权
		int id1 = change(str1);		// 将str1转换为编号id1
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