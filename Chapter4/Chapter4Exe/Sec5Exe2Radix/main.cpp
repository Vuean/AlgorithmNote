/*
���⣺
�����ĸ�����N1��N2��tag��radix������tag==1��ʾN1Ϊradix��������
tag==2��ʾN2Ϊradix����������Χ��N1��N2��������10����λ����ÿ����λ��Ϊ
0~9��a~z������0~9��ʾ����0~9��a~z��ʾ����10~35��

��N1��N2��δ֪���Ƶ��Ǹ����Ƿ���ڣ�������ĳ������ʱ������һ����
��ʮ��������ȵ������������ڣ������������������С���ƣ��������Impossible
*/

/*
ע��㣺
1.ʹ�ñ������Ƶı���ö�ٻᳬʱ��
2.����ı�������ʹ��long long ���͡�
3. ��N1��N2���ʱ�� �����Ŀ������radixֵ��
4.N2���Ƶ��½�Ϊ������λ�������Ǹ��� 1��
�Ͻ�Ϊ�½��� N1���ƵĽϴ�ֵ��1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL Map[256];			// 0~9��a~z��0~35�Ķ�Ӧ
LL inf = (1LL << 63) - 1;		// long long�����ֵ2^63-1

void init()
{
	for (char c = '0'; c <= '9'; c++)
	{
		Map[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		Map[c] = c - 'a' + 10;
	}
}

// ��aת��Ϊʮ���ƣ�tΪ�Ͻ�
LL convertNum10(char a[], LL radix, LL t)
{
	LL ans = 0;
	int len = (int)strlen(a);
	for (int i = 0; i < len; i++)
	{
		ans = ans * radix + Map[a[i]];
		if (ans < 0 || ans > t) return -1;
	}
	return ans;
}

// N2��ʮ������t�Ƚ�
int cmp(char N2[], LL radix, LL t)
{
	int len = (int)strlen(N2);
	LL num = convertNum10(N2, radix, t);
	if (num < 0) return 1;
	if (t > num) return -1;
	else if (t == num) return 0;
	else return 1;	// num�ϴ󣬷���1
}

//  �������N2 �Ľ���
LL binarySearch(char N2[], LL left, LL right, LL t)
{
	LL mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);	// �ж�N2 ת��Ϊʮ���ƺ���t �Ƚ�
		if (flag == 0) return mid;
		else if (flag == -1) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

// ��������λ
int findLargestDigit(char N2[])
{
	int ans = -1, len = (int)strlen(N2);
	for (int i = 0; i < len; i++)
	{
		if (Map[N2[i]] > ans)
		{
			ans = Map[N2[i]];
		}
	}
	return ans + 1;
}

char N1[20], N2[20], temp[20];
int tag, radix;

int main()
{
	init();
	cin >> N1 >> N2 >> tag >> radix;
	if (tag == 2)
	{
		strcpy_s(temp, N1);
		strcpy_s(N1, N2);
		strcpy_s(N2, temp);
	}

	LL t = convertNum10(N1, radix, inf);
	LL low = findLargestDigit(N2);	// �ҵ�N2����λ����λ��1�����ɶ����½�
	LL high = max(low, t) + 1; // �Ͻ�
	LL ans = binarySearch(N2, low, high, t);
	if (ans == -1) cout << "Impossible\n";
	else cout << "Ans = " << ans;
}