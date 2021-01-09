// 问题 G: 数字分类 (20)
/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
*/

#include <cstdio>

int main()
{

	int n;
	while(scanf("%d", &n)!=EOF)
    {
        int A[5]={};
        int t1=0,t2=0;
        double t3=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t1);
            if(t1%5==0&&t1%2==0)
                A[0]=A[0]+t1;
            if(t1%5==1)
            {
                t2++;
                if(t2%2==1)
                    A[1]=A[1]+t1;
                else
                    A[1]=A[1]-t1;
            }
            if(t1%5==2)
                A[2]++;
            if(t1%5==3)
            {
                t3++;
                A[3]=A[3]+t1;
            }
            if(t1%5==4)
            {
                if(t1>A[4])
                    A[4]=t1;
            }

        }
        double x=A[3]/t3;
        if(A[0]==0)
            printf("N ");
        else
            printf("%d ",A[0]);
        if(t2==0)
            printf("N ");
        else
            printf("%d ",A[1]);
        if(A[2]==0)
            printf("N ");
        else
            printf("%d ",A[2]);
        if(t3==0)
            printf("N ");
        else
            printf("%.1f ",x);
        if(A[4]==0)
            printf("N\n");
        else
            printf("%d\n",A[4]);
    }

    return 0;
}