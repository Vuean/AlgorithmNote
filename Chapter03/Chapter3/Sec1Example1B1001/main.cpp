// [PAT B1 001]�����˲�������( 3n+1)����
/*
������(Cal1atz ) ���룺
���κ�һ����Ȼ��n, �������ż���� ��ô��������һ�룻 ���������������ô��C3n+1)����һ�롣����һֱ��������ȥ�� ���һ����ĳһ���õ�n=1��
��������1950���������ѧ�Ҵ���Ϲ�����������룬��˵��ʱҮ³��ѧʦ���붯Ա�� ƴ����֤�����ò�ƺܻ���......
�˴�����Ҫ֤�������Ȳ��룬���ǶԸ�������һ������1000��������n���򵥵���һ�£���Ҫ���ٲ����ܵõ�n= 1?
*/
#include <iostream>
using namespace std;

int main()
{
	int num = 0, n;
	cin >> n;
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n = 3 * n + 1;
			n /= 2;
		}
		num++;
	}
	cout << num << endl;
	return 0;
}