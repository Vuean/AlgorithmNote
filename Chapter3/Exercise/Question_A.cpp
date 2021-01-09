// 问题 A: 剩下的树
/*
问题描述：
有一个长度为整数L(1<=L<=10000)的马路，可以想象成数轴上长度为L的一个线段，起点是坐标原点，在每个整数坐标点有一棵树，
即在0,1,2，...，L共L+1个位置上有L+1棵树。现在要移走一些树，移走的树的区间用一对数字表示，
如 100 200表示移走从100到200之间（包括端点）所有的树。
可能有M(1<=M<=100)个区间，区间之间可能有重叠。现在要求移走所有区间的树之后剩下的树的个数。
*/
#include<iostream>
using namespace std;
const int MaxNum = 10001;

int main()
{
    int L, M;
    int left, right;
    while(cin >> L >> M)
    {
        if (L == 0 && M == 0)
            break;
        
        int TotalNum[MaxNum] = {0};
        for(int i = 0; i < M; i++)
        {
            cin >> left >> right;
            for(int j = left; j <= right; j++)
            {
                TotalNum[j] = 1;
            }
        }

        int num = 0;
        for(int k = 0; k < MaxNum; k++)
        {
            if(TotalNum[k])
                num++;
        }
        cout << L + 1 - num << endl;
    }
}