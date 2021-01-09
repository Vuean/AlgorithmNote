// 问题 D: 比较奇偶数个数
/*
第一行输入一个数，为n，第二行输入n个数，这n个数中，
如果偶数比奇数多，输出NO，否则输出YES。
*/
#include<iostream>
using namespace std;

int main()
{
    int n1;
    while(cin >> n1)
    {
        int num1 = 0, num2 = 0;
        for(int i = 0; i < n1; i++)
        {
            int x;
            cin >> x;
            if(x % 2 == 0) num1++;
            else num2++;
        }
        if(num1 > num2)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}