// ���� C: ����˷�
/*
д���㷨����2��С��1000000000�����룬������
����˷�������123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
*/

#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    char a[10], b[10];
    while(scanf("%s%s", a, b) != EOF)
    {
        int x, y;
        x = strlen(a);
        y = strlen(b);
        int sum = 0, num1, num2;
        for(int i = 0; i < x; i++)
        {
            num1 = a[i] - '0';
            for(int j = 0; j < y; j++)
            {
                num2 = b[j] - '0';
                sum += (num1 * num2);
            }
        }
        printf("%d\n", sum);
    }
}