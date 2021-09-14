/*
װˮ���⣺��һ�����濴ȥ�ǰ�Բ�Ĵ�ˮװ�ã��ð�Բ�İ뾶ΪR��
Ҫ��������װ��߶�Ϊh��ˮ��ʹ���ڲ��濴ȥ��������Բ����ı���ǡ��Ϊr�����ڸ���R��r����߶�h��
*/

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-5;

double f(double R, double h)
{
	double alpha = 2 * acos((R - h) / R);
	double L = 2 * sqrt(R * R - (R - h) * (R - h));
	double S1 = alpha * R * R / 2 - L * (R - h) / 2;
	double S2 = PI * R * R / 2;
	return S1 / S2;
}

double solve(double R, double r)
{
	double left = 0, right = R, mid = 0;
	while((right - left) > eps)
	{
		mid = (left + right) / 2;
		if (f(R, mid) > r)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	return mid;
}

int main()
{
	double R, r;
	cin >> R >> r;
	cout << solve(R, r) << endl;
}