// ���� F: A+B��C (15)
// ��������[-2^31, 2^31]�ڵ�3������A��B��C�����ж�A+B�Ƿ����C��

#include <iostream>
using namespace std;
int main()
{
    long long int num;
    cin >> num;
    int m[10];
    for(int i = 1; i <= num; i++)
    {
        long long int num1, num2, num3;
        cin >> num1 >> num2 >> num3;
        if(num1 + num2 > num3)
            m[i] = 1;
        else
            m[i] = 0;
    }
    for(int i = 1; i <= num; i++)
    {
        if(m[i] == 1)
            cout << "Case #" << i << ": true" << endl;
        else
            cout << "Case #" << i << ": false" << endl;
    }
}