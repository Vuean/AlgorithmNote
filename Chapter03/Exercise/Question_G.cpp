// ���� G: ���ַ��� (20)
/*
����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�

A1 = �ܱ�5����������������ż���ĺͣ�
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
A3 = ��5������2�����ֵĸ�����
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
A5 = ��5������4��������������֡�
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