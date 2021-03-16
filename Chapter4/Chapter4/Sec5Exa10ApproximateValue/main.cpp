// 计算根号2的近似值：

const double eps = 1e-5;	//	精度为10^-5
double f(double x)
{
	return x * x;
}

double calSqrt()
{
	double left = 1, right = 2, mid;
	while (right - left > eps)
	{
		mid = (left + right) / 2;
		if (f(mid) > 2)
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

}