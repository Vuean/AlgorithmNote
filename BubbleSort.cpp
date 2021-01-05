// 输入数组，降序排列
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int num[10];
    scanf("%d%d%d%d%d%d%d%d%d%d", &num[0], &num[1], &num[2], 
                            &num[3], &num[4], &num[5], 
                            &num[6], &num[7], &num[8], &num[9]);
    
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 0; j < 10 - i; j++)
        {
            // 改为>即为升序排列
            if (num[j] > num[j+1])
            {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }
    } 

    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", num[i]);
    }
}