// 问题 B: A+B
/*
给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开�?
现在请计算A+B的结果，并以正常形式输出�?
*/
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    char a[20], b[20], A[10], B[10];
    while(scanf("%s%s", a, b) != EOF)
    {
        int x, y, m, n;
        x = strlen(a);
        int j = 0;
        for(int i = 0; i < x; i++)
        {
            if(a[i] >= '0' && a[i] <= '9')
            {
                A[j] = a[i];
                j++;
            }
        }
        A[j] = '\0';
        sscanf(A, "%d", &m);
        if(a[0] == '-') m = -m;

        y = strlen(b);
        int k = 0;
        for(int i = 0; i < y; i++)
        {
            if(b[i] >= '0' && b[i] <= '9')
            {
                B[k] = b[i];
                k++;
            }
        }
        B[k] = '\0';
        sscanf(B, "%d", &n);
        if(b[0] == '-') n = -n;
        printf("%d\n", m+n);
    }
}