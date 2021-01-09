// 问题 H: 部分A+B (15)
/*
整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。
例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。
*/

#include <iostream>
#include <string>
using namespace std;

long long func(string a, int da)
{
    long long sum = 0;
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] - '0' == da)
        {
            sum = sum * 10 + da;
        }
    }
    return sum;
}



int main()
{
    string A, B;
    int Da, Db;
    cin >> A >> Da >> B >> Db;
    long long sum_a, sum_b;
    sum_a = func(A, Da);
    sum_b = func(B, Db);
    cout << sum_a + sum_b << endl;
    return 0;
}